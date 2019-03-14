import sys
import os
sys.dont_write_bytecode = True
known_commands = ['exit', 'quit', 'create', 'in', '..', 'build', 'ls', 'dir', 'run']

# if sys.platform.startswith('win32'):
#     slash = '\\'
# elif sys.platform.startswith('linux'):
#     slash = '/'
cwd = os.getcwd()
places = [cwd]
def get_projects(thing):
    common_part = ''
    subs = []
    i = 0
    done = False
    while i < len(thing):
        if thing[i] == '(' and done == False:
            done = True
            common_part += '{}'
            i += 1
            start = i
            while thing[i] != '-':
                i += 1
            first = int(thing[start:i])
            i += 1
            start = i
            while thing[i] != ')':
                i += 1
            last = int(thing[start:i])
            if first > last:
                first, last = last, first
            while first <= last:
                subs.append(first)
                first += 1
        else:
            common_part += thing[i]
        i += 1
    # print(common_part)
    result = []
    for elem in subs:
        result.append(common_part.format(elem))
    return result

while True:
    print(os.path.relpath(os.getcwd(), start=cwd), '$', end=' ', flush=True)
    line = sys.stdin.readline()
    tokens = line.strip().split()
    i = 0
    found = ''
    possible_commands = []
    while i < len(tokens[0]):
        possible_commands.clear()
        for cmd in known_commands:
            if cmd.startswith(tokens[0][:i+1]):
                possible_commands.append(cmd)
        if len(possible_commands) == 1:
            found = possible_commands[0]
            break
        i += 1
        pass
    if found == '':
        if len(possible_commands) != 0:
            print("error: ambiguous command name {}".format(tokens[0]))
            print("note: can be", possible_commands)
        elif len(possible_commands) == 0:
            print("error: unknown command name {}".format(tokens[0]))
    else:
        if found in ('exit', 'quit'):
            break
        if found == 'create':
            if len(tokens) != 4 or tokens[1] != 'in':
                print("error: wrong number of arguments to create")
                print("usage: create in [dir] [name]")
                print("usage: [name] can contain (from-to), including to")
            else:
                # print("if {0} not exist, creating {0}".format(tokens[2]))
                projects = get_projects(tokens[3])
                for proj in projects:
                    dir_name = os.path.join(tokens[2], proj)
                    os.makedirs(dir_name, exist_ok=True)
                    with open(os.path.join(dir_name, 'metal'), "w") as metal:
                        metal.write("exec {} *.c".format(proj))

                    with open(os.path.join(dir_name, proj + '.c'), "w") as c_file:
                        c_file.write("#include <stdio.h>\n\n")
                        c_file.write("int main() {\n")
                        c_file.write("    printf(\"Hello {} world\\n\");\n".format(proj))
                        c_file.write("    return 0;\n")
                        c_file.write("}")
                    # print('os.makedirs("{}", exist_ok=True)'.format(os.path.join(tokens[2], proj)))
                    # print('with open("{}", "w") as metal:'.format(os.path.join(tokens[2], proj, 'metal')))
                    # print('    metal.write("exec {} *.c")'.format(proj))
                    # print('with open("{}", "w") as c_file:'.format(os.path.join(tokens[2], proj, proj + '.c')))
                    # print('    c_file.write("#include <stdio.h>\\n\\n")')
                    # print('    c_file.write("int main() {\\n\\n")')
                    # print('    c_file.write("    printf(\"Hello {} world\\\\n\");\\n")'.format(proj))
                    # print('    c_file.write("    return 0;\\n")')
                    # print('    c_file.write("}")')
        if found == 'in':
            if len(tokens) != 2:
                print("error: wrong number of arguments to in")
                print("usage: in [dir]")
            if os.path.isdir(tokens[1]):
                places.append(tokens[1])
                os.chdir(tokens[1])
            else:
                for place in reversed(places):
                    idx = places.index(place)
                    possible_dir = os.path.join(cwd, *places[:idx+1], tokens[1])
                    if os.path.isdir(possible_dir):
                        places = places[:idx+1]
                        places.append(tokens[1])
                        os.chdir(possible_dir)
                        break
        if found == '..':
            if len(places) > 1:
                places.pop()
                os.chdir('..')
            else:
                print('error: can\'t go below')
        if found == 'build':
            if len(tokens) not in (1, 2):
                print('error: wrong number of arguments to build')
                print('usage: build {dir}')
                print('usage: dir may be ommited to build current dir')
            wd = os.getcwd()
            build_dir = ''
            if len(tokens) == 2:
                if os.path.isdir(tokens[1]):
                    build_dir = os.path.join(os.getcwd(), tokens[1])
                else:
                    print('error: there is no dir {}'.format(tokens[1]))
            else:
                build_dir = os.getcwd()
            if build_dir != '':
                metal_file = os.path.join(build_dir, 'metal')
                build_file = os.path.join(build_dir, 'build.ninja')
                if os.path.isfile(metal_file):
                    last_modified = os.path.getmtime(metal_file)
                    if not os.path.isfile(build_file) or \
                       last_modified > os.path.getmtime(build_file):
                        import shuriken
                        # print('running shuriken.py to update or create build.ninja')
                        shuriken.shuriken(metal_file)
                    # print('running ninja to actually build the project')
                    os.chdir(build_dir)
                    os.system('ninja')
                    os.chdir(wd)
                else:
                    print('error: couldn\'t find metal file needed to build project')
        if found in ('ls', 'dir'):
            print(' '.join(os.listdir(os.getcwd())))
            pass
        if found == 'run':
            if len(tokens) < 2:
                print('error: wrong number of arguments to run')
                print('usage: run [program] {args...}')
                print('usage: program can be . to mean the dir name')
                print('usage: there can be 0 or more args')
            wd = os.getcwd()
            if tokens[1] == '.':
                run_file = os.path.join(os.getcwd(), os.path.split(os.getcwd())[1])
            else:
                run_file = os.path.join(os.getcwd(), tokens[1])
            prename = ''
            if sys.platform.startswith('linux'):
                prename = './'
            os.system(prename + run_file + ' ' + ' '.join(tokens[2:]))
    pass

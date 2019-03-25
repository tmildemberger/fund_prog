import sys
sys.dont_write_bytecode = True
from cmd import Cmd
import os
cwd = os.getcwd()

class Kunai(Cmd):
    def __init__(self):
    #     self.do_check('')
        return super().__init__(completekey='tab')
    def check(self):
        self.do_check('')
        return self
    prompt = os.path.relpath(os.getcwd(), cwd) + ' $ '
    def do_exit(self, inp):
        return True
    known_commands = ['exit', 'quit', 'create', 'run', 'build', 'in', 'ls', 
                      'dir', 'cd']
    def get_projects(self, thing):
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
    
    def default(self, inp):
        tokens = inp.strip().split()
        i = 0
        found = ''
        possible_commands = []
        while i < len(tokens[0]):
            possible_commands.clear()
            for cmd in self.known_commands:
                if cmd.startswith(tokens[0][:i+1]):
                    possible_commands.append(cmd)
            if len(possible_commands) == 1:
                found = possible_commands[0]
                break
            i += 1
        if found == '':
            if len(possible_commands) != 0:
                print("error: ambiguous command name {}".format(tokens[0]))
                print("note: can be", possible_commands)
            elif len(possible_commands) == 0:
                print("error: unknown command name {}".format(tokens[0]))
        else:
            if hasattr(self, 'do_' + found):
                return getattr(self, 'do_' + found)(' '.join(tokens[1:]))
            else:
                print('unimplemented')
    do_quit = do_exit
    do_EOF = do_exit
    places = [cwd]
    def do_create(self, inp):
        tokens = inp.split()
        if len(tokens) != 3 or tokens[0] != 'in':
            print("error: wrong number of arguments to create")
            print("usage: create in [dir] [name]")
            print("usage: [name] can contain (from-to), including to")
        else:
            # print("if {0} not exist, creating {0}".format(tokens[1]))
            projects = self.get_projects(tokens[2])
            for proj in projects:
                dir_name = os.path.join(tokens[1], proj)
                os.makedirs(dir_name, exist_ok=True)
                with open(os.path.join(dir_name, 'metal'), "w") as metal:
                    metal.write("exec {} *.c".format(proj))

                with open(os.path.join(dir_name, proj + '.c'), "w") as c_file:
                    c_file.write("#include <stdio.h>\n\n")
                    c_file.write("int main() {\n")
                    c_file.write("    printf(\"Hello {} world\\n\");\n".format(proj))
                    c_file.write("    return 0;\n")
                    c_file.write("}")

    def do_in(self, inp):
        tokens = inp.split()
        # print(tokens)
        # print(len(tokens))
        if len(tokens) != 1:
            print("error: wrong number of arguments to in")
            print("usage: in [dir]")
        if os.path.isdir(tokens[0]):
            self.places.append(tokens[0])
            os.chdir(tokens[0])
            self.prompt = os.path.relpath(os.getcwd(), cwd) + ' $ '
        else:
            for place in reversed(self.places):
                idx = self.places.index(place)
                possible_dir = os.path.join(cwd, *self.places[:idx+1], tokens[0])
                if os.path.isdir(possible_dir):
                    self.places = self.places[:idx+1]
                    self.places.append(tokens[0])
                    os.chdir(possible_dir)
                    self.prompt = os.path.relpath(os.getcwd(), cwd) + ' $ '
                    break
    do_cd = do_in
    def do_build(self, inp):
        tokens = inp.split()
        if len(tokens) > 2:
            print('error: wrong number of arguments to build')
            print('usage: build {dir}')
            print('usage: dir may be ommited to build current dir')
        wd = os.getcwd()
        build_dir = ''
        if len(tokens) == 1:
            if os.path.isdir(tokens[0]):
                build_dir = os.path.join(os.getcwd(), tokens[0])
            else:
                print('error: there is no dir {}'.format(tokens[0]))
        else:
            build_dir = os.getcwd()
        if build_dir != '':
            metal_file = os.path.join(build_dir, 'metal')
            build_file = os.path.join(build_dir, 'build.ninja')
            if os.path.isfile(metal_file):
                last_modified = os.path.getmtime(metal_file)
                # print(last_modified)
                # print(os.path.getmtime(build_file))
                if not os.path.isfile(build_file) or \
                    last_modified > os.path.getmtime(build_file):
                    print('shuriken')
                    import shuriken
                    # print('running shuriken.py to update or create build.ninja')
                    shuriken.shuriken(metal_file)
                # print('running ninja to actually build the project')
                os.chdir(build_dir)
                os.system('ninja')
                os.chdir(wd)
            else:
                print('error: couldn\'t find metal file needed to build project')
    def do_ls(self, inp):
        print(' '.join(os.listdir(os.getcwd())))
    do_dir = do_ls
    def do_run(self, inp):
        tokens = inp.split()
        if len(tokens) < 1:
            tokens.append('.')
        wd = os.getcwd()
        if tokens[0] == '.':
            run_file = os.path.join(os.getcwd(), os.path.split(os.getcwd())[1])
        else:
            run_file = os.path.join(os.getcwd(), tokens[0])
        #prename = ''
        #if sys.platform.startswith('linux'):
        #    prename = './'
        os.system(run_file + ' ' + ' '.join(tokens[1:]))
    def do_check(self, inp):
        found = False
        for path in os.getenv('PATH').split(os.path.pathsep):
            full_path = os.path.join(path, 'ninja')
            if os.path.isfile(full_path) or os.path.isfile(full_path + '.exe'):
                print('found ninja in ' + full_path)
                found = True
                break
        if not found:
            last_attempt = os.path.join(os.getcwd(), 'ninja', 'ninja')
            if os.path.isfile(last_attempt) or os.path.isfile(last_attempt + '.exe'):
                print('actually found')
                os.environ['PATH'] += os.path.pathsep + os.path.join(os.getcwd(), 'ninja')
                return
            print('ninja not found, I\'m gonna install it then')
            wd = os.getcwd()
            os.chdir(cwd)
            os.system('git clone https://github.com/ninja-build/ninja.git')
            os.chdir('ninja')
            os.system('git checkout release')
            # exec(open('configure.py').read())
            # import sys
            import subprocess
            if sys.platform.startswith('win'):
                subprocess.run([sys.executable, 'configure.py', '--bootstrap', '--platform=mingw'])
            else:
                subprocess.run([sys.executable, 'configure.py', '--bootstrap'])
            # os.system('./configure.py --bootstrap')
            os.environ['PATH'] += os.path.pathsep + os.getcwd()
            os.chdir(wd)
            found = False
            for path in os.getenv('PATH').split(os.path.pathsep):
                full_path = os.path.join(path, 'ninja')
                if os.path.isfile(full_path) or os.path.isfile(full_path + '.exe'):
                    print('found ninja in ' + full_path)
                    found = True
                    break
            if not found:
                print('i give up')
            else:
                print('it worked')
        pass
    def complete_in(self, text, line, begidx, endidx):
        # print(text)
        # print(line)
        # print(begidx)
        # print(endidx)
        return [i for i in os.listdir(os.getcwd()) if i.startswith(text)]
    complete_cd = complete_in

Kunai().check().cmdloop()

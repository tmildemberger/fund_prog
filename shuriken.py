#!/usr/bin/env python3
import sys
import os

def shuriken(path_to_metal):
    recurse = False
    before = os.getcwd()
    if os.path.dirname(path_to_metal) != os.getcwd():
        os.chdir(os.path.dirname(path_to_metal))
    # print('hello')
    if sys.platform.startswith('win32'):
        obj_ext = '.obj'
        exe_ext = '.exe'
    elif sys.platform.startswith('linux'):
        obj_ext = '.o'
        exe_ext = ''
    libs = {}
    execs = {}
    curr_compile_flags = {}
    curr_section = ''
    # default_flags = {'cpp':'-std=c++17 -Wall -pedantic', 'c':'-std=c99 -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast -Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter -Wfloat-equal -pedantic -ansi'}
    default_flags = {'cpp':'-std=c++17 -Wall -pedantic', 'c':'-Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast -Wmissing-prototypes -Wmissing-declarations -Winline -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter -Wfloat-equal -pedantic -ansi -std=c99'}
    curr_compile_flags = default_flags.copy()
    walk_entries = []
    sources = []
    if os.path.isdir('src'):
        sources.append('src')
    else:
        sources.append('.')
    if recurse:
        walk_entries += os.walk(sources[0])
    else:
        walk_entries += [(sources[0], [], os.listdir(sources[0]))]
    with open(path_to_metal) as file:
        line = file.readline()
        while line != '':
            tokens = line.split(' ')
            if tokens[0].startswith('#'):
                line = file.readline()
                continue
            idx = 0
            while idx < len(tokens):
                if tokens[idx].endswith('\n'):
                    tokens[idx] = tokens[idx][:-1]
                idx += 1
            # print(tokens)
            if tokens[0] == 'exec':
                if len(tokens) < 3:
                    print("syntax error")
                name = tokens[1]
                execs[name] = {}
                i = 3
                cur_opt = 'selectors'
                options = {}
                options[cur_opt+'_begin'] = 2
                options[cur_opt+'_end'] = i
                while i < len(tokens):
                    if tokens[i] == 'using' or tokens[i] == 'linker_options' or tokens[i] == 'compiler_options':
                        cur_opt = tokens[i]
                        options[cur_opt+'_begin'] = i + 1
                    else:
                        options[cur_opt+'_end'] = i + 1
                    i += 1
                selectors = tokens[options['selectors_begin']:options['selectors_end']]
                # print(selectors)
                # need to separate the regex tokens from the future rest
                # print(options)
                import fnmatch
                result = []
                for walk_result in walk_entries:
                    for fn in walk_result[2]:
                        fn = os.path.relpath(os.path.join(walk_result[0], fn), '.')
                        # print(fn)
                        accept = False
                        discarted = False
                        for sel in selectors:
                            negate = sel.startswith('-')
                            if negate:
                                sel = sel[1:]
                            if not fnmatch.fnmatch(fn, sel):
                                continue
                            if negate:
                                discarted = True
                            accept = not negate
                            # temp = sel
                            # negate = temp.startswith('-')
                            # if negate:
                            #     temp = temp[1:]
                            # if not fnmatch.fnmatch(fn, temp):
                            #     continue
                            # if negate:
                            #     discarted = True
                            # accept = not negate
                        if accept and not discarted:
                            result.append(fn)
                result.sort()
                execs[name]['build_files'] = result
                # print('exec', end='')
                # for res in result:
                    # print(' ', end='')
                    # print(res, end='')
                # print()
                
                if 'using_begin' in options and 'using_end' in options:
                    using = tokens[options['using_begin']:options['using_end']]
                    execs[name]['libs'] = []
                    for wanted_lib in using:
                        if wanted_lib in libs:
                            if libs[wanted_lib] == '%fill%':
                                print('fill the thing in the file')
                            else:
                                # print('all right')
                                execs[name]['libs'].append((wanted_lib, libs[wanted_lib]))
                        else:
                            print('couldn\'t find')

                if 'compiler_options_begin' in options and 'compiler_options_end' in options:
                    compiler_options = tokens[options['compiler_options_begin']:options['compiler_options_end']]
                    # for opt in compiler_options:
                    #     if opt == 'default':

                    #     pass
                    # print(' '.join(compiler_options))
                    execs[name]['extra_opts'] = ' '.join(compiler_options)
                execs[name]['comp_flags'] = curr_compile_flags.copy()
                execs[name]['section'] = curr_section

            if tokens[0] == 'lib':
                if len(tokens) < 4:
                    print("syntax error")
                tokens = line.split(' ', 3)
                # print(tokens)
                if tokens[2] != 'in':
                    print('syntax error')
                libs[tokens[1]] = os.path.abspath(tokens[3][:-1])
                # print(libs)
            
            if tokens[0] == 'compiler_flags':
                if len(tokens) < 3:
                    print("syntax error")
                lang = tokens[1]
                if tokens[2] == 'none':
                    if len(tokens) > 3:
                        print("syntax error")
                    # print('no options to %s' % lang)
                    curr_compile_flags[lang] = ''
                elif tokens[2] == 'default':
                    if len(tokens) < 4:
                        print("unnecessary default specification if there is nothing to add")
                    # print('adding the rest to %s:' % lang, end=' ')
                    # print(' '.join(tokens[3:]))
                    curr_compile_flags[lang] = default_flags[lang] + ' '.join(tokens[3:])
                else:
                    print('options to %s:' % lang, end=' ')
                    # print(' '.join(tokens[2:]))
                    curr_compile_flags[lang] = ' '.join(tokens[2:])

            if tokens[0] == 'section':
                if len(tokens) < 2:
                    print("syntax error")
                curr_section = tokens[1]

            if tokens[0] == 'endsection':
                if len(tokens) > 1:
                    print("syntax error")
                curr_section = ''

            if tokens[0] == 'sources':
                if len(tokens) < 3:
                    print("syntax error")
                if tokens[1] != 'in':
                    print('syntax error')
                for tok in tokens[2:]:
                    if os.path.isdir(tok):
                        walk_entries += [(tok, [], os.listdir(tok))]
                        sources.append(tok)
                    pass
                pass
            
            line = file.readline()
    # print('\n')
    # print(execs)
    ninja_rules = ''
    ninja_builds = ''
    lang_rules = []
    for target, pack in execs.items():
        real_files = []
        # print(target)
        # print(pack)
        for file in pack['build_files']:
            if file.endswith('.c'):
                if not 'c' in lang_rules:
                    ninja_rules += 'CC = gcc\n'
                    ninja_rules += 'rule compile_c\n'
                    ninja_rules += '  command = $CC ${c_flags} ${c_opts} -MMD -MT $out -MF $out.dep -c $in -o $out\n'
                    ninja_rules += '  description = compile(c) $out\n'
                    ninja_rules += '  depfile = $out.dep\n'
                    ninja_rules += '  deps = gcc\n\n'
                    lang_rules.append('c')
                    pass
                obj_dir = 'obj/'
                if pack['section']:
                    obj_dir = pack['section'] + '_obj/'
                    pass
                ninja_builds += 'build %s%s%s: compile_c %s\n' % (obj_dir, file, obj_ext, file)
                real_files.append('%s%s%s' % (obj_dir, file, obj_ext))
                if 'extra_opts' in pack:
                    ninja_builds += '  c_opts = %s\n' % pack['extra_opts']
                    pass
                if pack['comp_flags']:
                    ninja_builds += '  c_flags = %s\n' % pack['comp_flags']['c']
                    pass
                if 'libs' in pack:
                    ninja_builds += '  c_flags ='
                    for lib, lib_path in pack['libs']:
                        ninja_builds += ' -I%s' % os.path.join(lib_path, 'include')
                    ninja_builds += '\n'
                    pass
                pass
            if file.endswith('.cpp'):
                if not 'cpp' in lang_rules:
                    ninja_rules += 'CXX = g++\n'
                    ninja_rules += 'rule compile_cpp\n'
                    ninja_rules += '  command = $CXX ${cxx_flags} ${c_opts} -MMD -MT $out -MF $out.dep -c $in -o $out\n'
                    ninja_rules += '  description = compile(cpp) $out\n'
                    ninja_rules += '  depfile = $out.dep\n'
                    ninja_rules += '  deps = gcc\n\n'
                    lang_rules.append('cpp')
                    pass
                obj_dir = 'obj\\'
                if pack['section']:
                    obj_dir = pack['section'] + '_obj\\'
                    pass
                ninja_builds += 'build %s%s%s: compile_cpp %s\n' % (obj_dir, file, obj_ext, file)
                real_files.append('%s%s%s' % (obj_dir, file, obj_ext))
                if 'extra_opts' in pack:
                    ninja_builds += '  c_opts = %s\n' % pack['extra_opts']
                    pass
                if pack['comp_flags']:
                    ninja_builds += '  cxx_flags = %s\n' % pack['comp_flags']['cpp']
                    pass
                if 'libs' in pack:
                    ninja_builds += '  cxx_flags ='
                    for lib, lib_path in pack['libs']:
                        ninja_builds += ' -I%s' % os.path.join(lib_path, 'include')
                    ninja_builds += '\n'
                    pass
                pass
            pass
        pass
        if not 'link' in lang_rules:
            ninja_rules += 'LINKER_EXE = g++\n'
            ninja_rules += 'rule link_exe\n'
            ninja_rules += '  command = $LINKER_EXE ${ld_flags} -o $out $in ${ld_libs}\n'
            ninja_rules += '  description = link(exe) $out\n\n'
            lang_rules.append('link')
            pass
        # print(len(real_files))
        # if len(real_files > 1)
        ninja_builds += 'build %s%s: link_exe %s\n' % (target, exe_ext, ' '.join(real_files))
        if 'libs' in pack:
            ninja_builds += '  ld_flags ='
            for lib, lib_path in pack['libs']:
                ninja_builds += ' -L%s' % os.path.join(lib_path, 'lib')
            ninja_builds += '\n'
            ninja_builds += '  ld_libs ='
            for lib, lib_path in pack['libs']:
                ninja_builds += ' -l%s' % lib
            ninja_builds += '\n'
            pass

    ninja_file = 'builddir = ninja\n'
    ninja_file += ninja_rules
    ninja_file += ninja_builds
    # print(ninja_file)
    output = open(os.path.join(os.path.dirname(path_to_metal), 'build.ninja'), 'w')
    output.write(ninja_file)
    output.close()
    os.chdir(before)

if __name__ == '__main__':
    # executed as a script
    metal_file = os.path.join(os.getcwd(), 'metal')
    if os.path.isfile(metal_file):
        shuriken(metal_file)
    else:
        print('no metal file found')
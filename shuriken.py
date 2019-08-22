#!/usr/bin/env python3
import sys
import os

def gettem(patterns):
    import glob
    ll = set()
    jj = set()
    bla = patterns.split(' ')
    for b in bla:
        neg = False
        if b.startswith('-'):
            neg = True
            b = b[1:]
        #print(b, end=' ')
        kk = set(glob.iglob(b))
        #print(kk)
        if neg:
            jj = set(list(kk) + list(jj))
        else:
            ll = set(list(kk) + list(ll))
    #print(ll - jj)
    return ll - jj
    pass

def parse_lines(content):
    idx = 0
    # possible_tokens = ['info', 'path', 'compiler', 'linker', 'libs']
    path = ''
    compiler_flags = ''
    linker_flags = ''
    linker_libs = ''
    if not content.endswith('\n'):
        content = content + '\n'
    # print(len(content), content)
    while idx < len(content): # and content.startswith(possible_tokens, idx):
        # print(idx, content[idx:idx+4], content.startswith('info', idx), path)
        if content.startswith('info', idx):
            while content[idx] != '"':
                idx += 1
            idx += 1
            while content[idx] != '"':
                idx += 1
            while content[idx] != '\n':
                idx += 1
            idx += 1
        elif content.startswith('path', idx):
            path = (content[idx:].split(None, 1))[1].split('\n', 1)[0]
            while content[idx] != '\n':
                idx += 1
            idx += 1
        elif content.startswith('compiler', idx):
            compiler_flags = (content[idx:].split(None, 1))[1].split('\n', 1)[0] + '  '
            place = compiler_flags.find('$path$')
            while place != -1:
                compiler_flags = compiler_flags[:place] + path + compiler_flags[place+6:]
                place = compiler_flags.find('$path$')

            while content[idx] != '\n':
                idx += 1
            idx += 1
        elif content.startswith('linker', idx):
            linker_flags = (content[idx:].split(None, 1))[1].split('\n', 1)[0] + '  '
            place = linker_flags.find('$path$')
            # print('linkerflags', linker_flags)
            # print('place', place)
            # print('path', path)
            # linker_flags = linker_flags[:place] + path + linker_flags[place+6:]
            # place = linker_flags.find('$path$')
            # print('linkerflags', linker_flags)
            # print('place', place)
            while place != -1:
                linker_flags = linker_flags[:place] + path + linker_flags[place+6:]
                place = linker_flags.find('$path$')

            while content[idx] != '\n':
                idx += 1
            idx += 1
        elif content.startswith('libs', idx):
            linker_libs = (content[idx:].split(None, 1))[1].split('\n', 1)[0] + '  '
            place = linker_libs.find('$path$')
            while place != -1:
                linker_libs = linker_libs[:place] + path + linker_libs[place+6:]
                place = linker_libs.find('$path$')

            while content[idx] != '\n':
                idx += 1
            idx += 1
        else:
            idx += 1
        pass
    pass
    compiler_flags = compiler_flags.strip()
    linker_flags = linker_flags.strip()
    linker_libs = linker_libs.strip()
    return compiler_flags, linker_flags, linker_libs

def parse_config(file):
    with open(file, "r") as config:
        content = config.read()
        flags = parse_lines(content)
        # print(flags)
        return flags
        pass
    pass

def get_config_files():
    # before = os.getcwd()
    # print(os.path.dirname(os.path.realpath(__file__)))
    config_folder = os.path.join(os.path.dirname(os.path.realpath(__file__)), 'config')
    os.makedirs(config_folder, exist_ok=True)
    files = {}
    for fl in os.listdir(config_folder):
        if fl.endswith('.cfg'):
            files[fl[:-4]] = os.path.join(config_folder, fl)
        
    # print(files)
    return files
    # compiler_flags = ''
    # linker_flags = ''
    # linker_libs = ''
    # for fl in files:
    #     cf, lf, lbs = parse_config(fl)
    #     compiler_flags += ' ' + cf
    #     linker_flags += ' ' + lf
    #     linker_libs += ' ' + lbs
    # compiler_flags = compiler_flags.strip()
    # linker_flags = linker_flags.strip()
    # linker_libs = linker_libs.strip()
    # print(compiler_flags, linker_flags, linker_libs)
    # return compiler_flags, linker_flags, linker_libs
    pass

class metal_parser():
    default_flags = dict()
    default_flags['cpp'] = '-std=c++17 -pedantic -pedantic-errors -Wall -Wextra -g -ggdb -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror'.split(' ')
    default_flags['c'] = '-Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast -Wmissing-prototypes -Wmissing-declarations -Winline -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wfloat-equal -pedantic -std=c99'.split(' ')
    selected_flags = default_flags.copy()
    compiler_f = {}
    linker_f = {}
    libs = {}
    found_libs = []

    execs = {}
    # found_configs = {}
    def __init__(self):
    	self.execs = dict()
    	self.libs = dict()
    	self.linker_f = dict()
    	self.compiler_f = dict()

    def set_found_configs(self, found_cfgs):
        self.found_configs = found_cfgs.copy()
        # print(self.found_configs)
        return

    def matches(self, files, selectors):
        result = gettem(' '.join(selectors))
        aa = []
        for fil in result:
            fil = os.path.relpath(fil, '.')
            aa.append(fil)
            # print(file)
            #accept = False
            # discarted = False
            # for sel in selectors:
            #     negate = sel.startswith('-')
            #     if negate:
            #         sel = sel[1:]
            #     if not fnmatch.fnmatch(file, sel):
            #         continue
            #     if negate:
            #         discarted = True
            #     accept = not negate
            # if accept and not discarted:
            #     result.append(file)
        aa.sort()
        # print(result)
        return aa
        pass

    def line_exec(self, number, tokens, line):
        if len(tokens) == 0:
            print('syntax error at line', number)
            print('not enough arguments')
            return
        name = tokens[0]
        selectors = []
        libraries = []
        if name == '.':
            name = os.path.split(os.getcwd())[1]
            pass
        if 'using' not in tokens:
            selectors = tokens[1:]
        else:
            start = tokens.index('using')
            selectors = tokens[1:start]
            libraries = tokens[start + 1:]

        files = os.listdir()
        # print(files)
        build_files = self.matches(files, selectors)
        # print(build_files)

        compiler_flags = ''
        linker_flags = ''
        linker_libs = ''
        for lib in libraries:
            if lib not in self.found_libs:
                print('error at line', number)
                print('not declared library', lib)
                print('note:', line)
                print(' ' * (line.find(lib) + 6) + '^' * len(lib))
                continue
            # print('adding library', lib, 'to', name)
            compiler_flags += ' ' + self.compiler_f[lib]
            linker_flags += ' ' + self.linker_f[lib]
            linker_libs += ' ' + self.libs[lib]

        # print(self.compiler_f, self.linker_f, self.libs)
        self.execs[name] = {'build_files': build_files}
        self.execs[name]['compiler_f'] = compiler_flags.strip()
        self.execs[name]['linker_f'] = linker_flags.strip()
        self.execs[name]['linker_libs'] = linker_libs.strip()
        self.execs[name]['c_only'] = ' '.join(self.selected_flags['c']).strip() + ' '
        self.execs[name]['cpp_only'] = ' '.join(self.selected_flags['cpp']).strip() + ' '
        return
        pass

    def line_configlib(self, number, tokens, line):
        if len(tokens) == 0:
            print('syntax error at line', number)
            print('not enough arguments')
            return
        elif len(tokens) > 1:
            print('syntax error at line', number)
            print('too many arguments')
            return
        lib = tokens[0]
        if self.found_configs.get(lib, False) == False:
            print('error at line', number)
            print("couldn't find the wanted library")
            print('note:', line)
            print(' ' * (line.find(lib) + 6) + '^' * len(lib))
            return
        self.compiler_f[lib], self.linker_f[lib], self.libs[lib] = parse_config(self.found_configs[lib])
        self.found_libs.append(lib)
        return
        pass

    def line_disable(self, number, tokens, line):
        if len(tokens) < 2:
            print('syntax error at line', number)
            print('not enough arguments')
            return
        if tokens[0] not in ['c', 'cpp']:
            print('error at line', number)
            print(tokens[0], 'is not c nor cpp')
            return
        language = tokens[0]
        options = tokens[1:]
        for opt in options:
            if opt in self.selected_flags[language]:
                self.selected_flags[language].remove(opt)
                pass
            pass
        pass

    def metal_line(self, number, line):
        if line.endswith('\n'):
            line = line[:-1]
        tokens = line.split(' ')
        if tokens[0].startswith('#') or len(tokens) == 0:
            return
        idx = 0
        for idx, token in enumerate(tokens):
            tokens[idx] = token.strip()
        # print(tokens)
        if tokens[0] in ['exec', 'configlib', 'section', 'disable']:
            if hasattr(self, 'line_' + tokens[0]):
                getattr(self, 'line_' + tokens[0])(number, tokens[1:], line)
                # print('executed', 'line_' + tokens[0])
            else:
                print('uninplemented command at line', number)
                print('note:', line)
                print(' ' * (line.find(tokens[0]) + 6) + '^' * len(tokens[0]))
        return
        # if tokens[0] == 'exec':
        #     if len(tokens) < 3:
        #         print("syntax error")
        #     name = tokens[1]
        #     execs[name] = {}
        #     i = 3
        #     cur_opt = 'selectors'
        #     options = {}
        #     options[cur_opt+'_begin'] = 2
        #     options[cur_opt+'_end'] = i
        #     while i < len(tokens):
        #         if tokens[i] == 'using' or tokens[i] == 'linker_options' or tokens[i] == 'compiler_options':
        #             cur_opt = tokens[i]
        #             options[cur_opt+'_begin'] = i + 1
        #         else:
        #             options[cur_opt+'_end'] = i + 1
        #         i += 1
        #     selectors = tokens[options['selectors_begin']:options['selectors_end']]
        #     # print(selectors)
        #     # need to separate the regex tokens from the future rest
        #     # print(options)
        #     import fnmatch
        #     result = []
        #     for walk_result in walk_entries:
        #         for fn in walk_result[2]:
        #             fn = os.path.relpath(os.path.join(walk_result[0], fn), '.')
        #             # print(fn)
        #             accept = False
        #             discarted = False
        #             for sel in selectors:
        #                 negate = sel.startswith('-')
        #                 if negate:
        #                     sel = sel[1:]
        #                 if not fnmatch.fnmatch(fn, sel):
        #                     continue
        #                 if negate:
        #                     discarted = True
        #                 accept = not negate
        #                 # temp = sel
        #                 # negate = temp.startswith('-')
        #                 # if negate:
        #                 #     temp = temp[1:]
        #                 # if not fnmatch.fnmatch(fn, temp):
        #                 #     continue
        #                 # if negate:
        #                 #     discarted = True
        #                 # accept = not negate
        #             if accept and not discarted:
        #                 result.append(fn)
        #     result.sort()
        #     execs[name]['build_files'] = result
        #     # print('exec', end='')
        #     # for res in result:
        #         # print(' ', end='')
        #         # print(res, end='')
        #     # print()
            
        #     if 'using_begin' in options and 'using_end' in options:
        #         using = tokens[options['using_begin']:options['using_end']]
        #         execs[name]['libs'] = []
        #         for wanted_lib in using:
        #             if wanted_lib in libs:
        #                 if libs[wanted_lib] == '%fill%':
        #                     print('fill the thing in the file')
        #                 else:
        #                     # print('all right')
        #                     execs[name]['libs'].append((wanted_lib, libs[wanted_lib]))
        #             else:
        #                 print('couldn\'t find')

        #     if 'compiler_options_begin' in options and 'compiler_options_end' in options:
        #         compiler_options = tokens[options['compiler_options_begin']:options['compiler_options_end']]
        #         # for opt in compiler_options:
        #         #     if opt == 'default':

        #         #     pass
        #         # print(' '.join(compiler_options))
        #         execs[name]['extra_opts'] = ' '.join(compiler_options)
        #     execs[name]['comp_flags'] = curr_compile_flags.copy()
        #     execs[name]['section'] = curr_section

        # if ' '.join(tokens[:2]) == 'configlib':
        #     if len(tokens) < 3:
        #         print("syntax error")
        #     print("configuring lib " + tokens[2])
        #     # tokens = line.split(' ', 3)
        #     # print(tokens)
        #     # if tokens[2] != 'in':
        #         # print('syntax error')
        #     # libs[tokens[1]] = os.path.abspath(tokens[3][:-1])
        #     # print(libs)
        
        # # if tokens[0] == 'compiler_flags':
        # #     if len(tokens) < 3:
        # #         print("syntax error")
        # #     lang = tokens[1]
        # #     if tokens[2] == 'none':
        # #         if len(tokens) > 3:
        # #             print("syntax error")
        # #         # print('no options to %s' % lang)
        # #         curr_compile_flags[lang] = ''
        # #     elif tokens[2] == 'default':
        # #         if len(tokens) < 4:
        # #             print("unnecessary default specification if there is nothing to add")
        # #         # print('adding the rest to %s:' % lang, end=' ')
        # #         # print(' '.join(tokens[3:]))
        # #         curr_compile_flags[lang] = default_flags[lang] + ' '.join(tokens[3:])
        # #     else:
        # #         print('options to %s:' % lang, end=' ')
        # #         # print(' '.join(tokens[2:]))
        # #         curr_compile_flags[lang] = ' '.join(tokens[2:])

        # # if tokens[0] == 'section':
        # #     if len(tokens) < 2:
        # #         print("syntax error")
        # #     curr_section = tokens[1]

        # # if tokens[0] == 'endsection':
        # #     if len(tokens) > 1:
        # #         print("syntax error")
        # #     curr_section = ''
        # # pass
    def gen_ninja(self):
        if sys.platform.startswith('win32'):
            obj_ext = '.obj'
            exe_ext = '.exe'
        elif sys.platform.startswith('linux'):
            obj_ext = '.o'
            exe_ext = ''

        ninja_rules = ''
        ninja_builds = ''
        lang_rules = []
        for target, pack in self.execs.items():
            real_files = []
            # print(target)
            # print(pack)
            for file in pack['build_files']:
                obj_file = ''
                if file.endswith('.c') or file.endswith('.cpp'):
                    local = file
                    while local.startswith('../'):
                        local = local[3:]
                    obj_dir = 'obj/'
                    obj_file = obj_dir + local + obj_ext
                if file.endswith('.c'):
                    if not 'c' in lang_rules:
                        ninja_rules += 'CC = gcc\n'
                        ninja_rules += 'rule compile_c\n'
                        ninja_rules += '  command = $CC ${c_flags} -MMD -MT $out -MF $out.dep -c $in -o $out\n'
                        ninja_rules += '  description = compile(c) $out\n'
                        ninja_rules += '  depfile = $out.dep\n'
                        ninja_rules += '  deps = gcc\n\n'
                        lang_rules.append('c')
                        pass
                    # if pack['section']:
                    obj_dir = 'obj/'
                    #     obj_dir = pack['section'] + '_obj/'
                    #     pass
                    ninja_builds += 'build {0}: compile_c {1}\n'.format(obj_file, file)
                    real_files.append('{0}'.format(obj_file))
                    # if pack['comp_flags']:
                    ninja_builds += '  c_flags = {0}{1}\n'.format(pack['c_only'], pack['compiler_f'])
                        # pass
                    # if 'libs' in pack:
                        # ninja_builds += '  c_flags ='
                        # for lib, lib_path in pack['libs']:
                            # ninja_builds += ' -I%s' % os.path.join(lib_path, 'include')
                        # ninja_builds += '\n'
                        # pass
                    pass
                if file.endswith('.cpp'):
                    if not 'cpp' in lang_rules:
                        ninja_rules += 'CXX = g++\n'
                        ninja_rules += 'rule compile_cpp\n'
                        ninja_rules += '  command = $CXX ${cxx_flags} -MMD -MT $out -MF $out.dep -c $in -o $out\n'
                        ninja_rules += '  description = compile(cpp) $out\n'
                        ninja_rules += '  depfile = $out.dep\n'
                        ninja_rules += '  deps = gcc\n\n'
                        lang_rules.append('cpp')
                        pass
                    obj_dir = 'obj/'
                    ninja_builds += 'build {0}: compile_cpp {1}\n'.format(obj_file, file)
                    real_files.append('{0}'.format(obj_file))
                    ninja_builds += '  cxx_flags = {0} {1}\n'.format(pack['cpp_only'], pack['compiler_f'])
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
            ninja_builds += 'build {0}{1}: link_exe {2}\n'.format(target, exe_ext, ' '.join(real_files))
            # if 'libs' in pack:
            if pack['linker_f'] != '':
                ninja_builds += '  ld_flags = {0}\n'.format(pack['linker_f'])
                # for lib, lib_path in pack['libs']:
                    # ninja_builds += ' -L%s' % os.path.join(lib_path, 'lib')
                # ninja_builds += '\n'
            if pack['linker_libs'] != '':
                ninja_builds += '  ld_libs = {0}\n'.format(pack['linker_libs'])
                # for lib, lib_path in pack['libs']:
                    # ninja_builds += ' -l%s' % lib
                # ninja_builds += '\n'
            pass

        ninja_file = 'builddir = ninja\n'
        ninja_file += ninja_rules
        ninja_file += ninja_builds
        # print(ninja_file)
        # output = open(os.path.join(os.path.dirname(path_to_metal), 'build.ninja'), 'w')
        # output.write(ninja_file)
        # output.close()
        # os.chdir(before)
        return ninja_file

def shuriken(path_to_metal):
    # compiler, linker, libs = get_configs()
    config_files = get_config_files()
    # recurse = False
    before = os.getcwd()
    if os.path.dirname(path_to_metal) != os.getcwd():
        os.chdir(os.path.dirname(path_to_metal))
    # print(os.getcwd())
    # print(path_to_metal)
    # print('hello')
    # libs = {}
    # execs = {}
    # curr_compile_flags = {}
    # curr_section = ''
    # default_flags = {'cpp':'-std=c++17 -Wall -pedantic', 'c':'-std=c99 -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast -Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter -Wfloat-equal -pedantic -ansi'}
    # default_flags = {'cpp':, 'c':}
    # curr_compile_flags = default_flags.copy()
    # walk_entries = []
    # sources = '.'
    # sources.append('.')
    # if recurse:
    #     walk_entries += os.walk(sources[0])
    # else:
    # walk_entries += [(sources, [], os.listdir(sources))]
    # print(path_to_metal)
    par = metal_parser()
    # print(par.execs)
    par.set_found_configs(config_files)
    with open(path_to_metal) as file:
        lines = file.readlines()
        for number, line in enumerate(lines):
            par.metal_line(number, line)

        ######################
        # line = file.readline()
        # while line != '':
        #     tokens = line.split(' ')
        #     if tokens[0].startswith('#'):
        #         line = file.readline()
        #         continue
        #     idx = 0
        #     while idx < len(tokens):
        #         if tokens[idx].endswith('\n'):
        #             tokens[idx] = tokens[idx][:-1]
        #         idx += 1
        #     # print(tokens)
        #     if tokens[0] == 'exec':
        #         if len(tokens) < 3:
        #             print("syntax error")
        #         name = tokens[1]
        #         execs[name] = {}
        #         i = 3
        #         cur_opt = 'selectors'
        #         options = {}
        #         options[cur_opt+'_begin'] = 2
        #         options[cur_opt+'_end'] = i
        #         while i < len(tokens):
        #             if tokens[i] == 'using' or tokens[i] == 'linker_options' or tokens[i] == 'compiler_options':
        #                 cur_opt = tokens[i]
        #                 options[cur_opt+'_begin'] = i + 1
        #             else:
        #                 options[cur_opt+'_end'] = i + 1
        #             i += 1
        #         selectors = tokens[options['selectors_begin']:options['selectors_end']]
        #         # print(selectors)
        #         # need to separate the regex tokens from the future rest
        #         # print(options)
        #         import fnmatch
        #         result = []
        #         for walk_result in walk_entries:
        #             for fn in walk_result[2]:
        #                 fn = os.path.relpath(os.path.join(walk_result[0], fn), '.')
        #                 # print(fn)
        #                 accept = False
        #                 discarted = False
        #                 for sel in selectors:
        #                     negate = sel.startswith('-')
        #                     if negate:
        #                         sel = sel[1:]
        #                     if not fnmatch.fnmatch(fn, sel):
        #                         continue
        #                     if negate:
        #                         discarted = True
        #                     accept = not negate
        #                     # temp = sel
        #                     # negate = temp.startswith('-')
        #                     # if negate:
        #                     #     temp = temp[1:]
        #                     # if not fnmatch.fnmatch(fn, temp):
        #                     #     continue
        #                     # if negate:
        #                     #     discarted = True
        #                     # accept = not negate
        #                 if accept and not discarted:
        #                     result.append(fn)
        #         result.sort()
        #         execs[name]['build_files'] = result
        #         # print('exec', end='')
        #         # for res in result:
        #             # print(' ', end='')
        #             # print(res, end='')
        #         # print()
                
        #         if 'using_begin' in options and 'using_end' in options:
        #             using = tokens[options['using_begin']:options['using_end']]
        #             execs[name]['libs'] = []
        #             for wanted_lib in using:
        #                 if wanted_lib in libs:
        #                     if libs[wanted_lib] == '%fill%':
        #                         print('fill the thing in the file')
        #                     else:
        #                         # print('all right')
        #                         execs[name]['libs'].append((wanted_lib, libs[wanted_lib]))
        #                 else:
        #                     print('couldn\'t find')

        #         if 'compiler_options_begin' in options and 'compiler_options_end' in options:
        #             compiler_options = tokens[options['compiler_options_begin']:options['compiler_options_end']]
        #             # for opt in compiler_options:
        #             #     if opt == 'default':

        #             #     pass
        #             # print(' '.join(compiler_options))
        #             execs[name]['extra_opts'] = ' '.join(compiler_options)
        #         execs[name]['comp_flags'] = curr_compile_flags.copy()
        #         execs[name]['section'] = curr_section

        #     if ' '.join(tokens[:2]) == 'config lib':
        #         if len(tokens) < 3:
        #             print("syntax error")
        #         print("configuring lib " + tokens[2])
        #         # tokens = line.split(' ', 3)
        #         # print(tokens)
        #         # if tokens[2] != 'in':
        #             # print('syntax error')
        #         # libs[tokens[1]] = os.path.abspath(tokens[3][:-1])
        #         # print(libs)
            
        #     # if tokens[0] == 'compiler_flags':
        #     #     if len(tokens) < 3:
        #     #         print("syntax error")
        #     #     lang = tokens[1]
        #     #     if tokens[2] == 'none':
        #     #         if len(tokens) > 3:
        #     #             print("syntax error")
        #     #         # print('no options to %s' % lang)
        #     #         curr_compile_flags[lang] = ''
        #     #     elif tokens[2] == 'default':
        #     #         if len(tokens) < 4:
        #     #             print("unnecessary default specification if there is nothing to add")
        #     #         # print('adding the rest to %s:' % lang, end=' ')
        #     #         # print(' '.join(tokens[3:]))
        #     #         curr_compile_flags[lang] = default_flags[lang] + ' '.join(tokens[3:])
        #     #     else:
        #     #         print('options to %s:' % lang, end=' ')
        #     #         # print(' '.join(tokens[2:]))
        #     #         curr_compile_flags[lang] = ' '.join(tokens[2:])

        #     if tokens[0] == 'section':
        #         if len(tokens) < 2:
        #             print("syntax error")
        #         curr_section = tokens[1]

        #     if tokens[0] == 'endsection':
        #         if len(tokens) > 1:
        #             print("syntax error")
        #         curr_section = ''

        #     # if tokens[0] == 'sources':
        #     #     if len(tokens) < 3:
        #     #         print("syntax error")
        #     #     if tokens[1] != 'in':
        #     #         print('syntax error')
        #     #     for tok in tokens[2:]:
        #     #         if os.path.isdir(tok):
        #     #             walk_entries += [(tok, [], os.listdir(tok))]
        #     #             sources.append(tok)
        #     #         pass
        #     #     pass
            
        #     line = file.readline()
    # print('\n')
    # print(par.execs)

    ninja = par.gen_ninja()
    # ninja_rules = ''
    # ninja_builds = ''
    # lang_rules = []
    # for target, pack in execs.items():
    #     real_files = []
    #     # print(target)
    #     # print(pack)
    #     for file in pack['build_files']:
    #         if file.endswith('.c'):
    #             if not 'c' in lang_rules:
    #                 ninja_rules += 'CC = gcc\n'
    #                 ninja_rules += 'rule compile_c\n'
    #                 ninja_rules += '  command = $CC ${c_flags} ${c_opts} -MMD -MT $out -MF $out.dep -c $in -o $out\n'
    #                 ninja_rules += '  description = compile(c) $out\n'
    #                 ninja_rules += '  depfile = $out.dep\n'
    #                 ninja_rules += '  deps = gcc\n\n'
    #                 lang_rules.append('c')
    #                 pass
    #             obj_dir = 'obj/'
    #             if pack['section']:
    #                 obj_dir = pack['section'] + '_obj/'
    #                 pass
    #             ninja_builds += 'build %s%s%s: compile_c %s\n' % (obj_dir, file, obj_ext, file)
    #             real_files.append('%s%s%s' % (obj_dir, file, obj_ext))
    #             if 'extra_opts' in pack:
    #                 ninja_builds += '  c_opts = %s\n' % pack['extra_opts']
    #                 pass
    #             if pack['comp_flags']:
    #                 ninja_builds += '  c_flags = %s\n' % pack['comp_flags']['c']
    #                 pass
    #             if 'libs' in pack:
    #                 ninja_builds += '  c_flags ='
    #                 for lib, lib_path in pack['libs']:
    #                     ninja_builds += ' -I%s' % os.path.join(lib_path, 'include')
    #                 ninja_builds += '\n'
    #                 pass
    #             pass
    #         if file.endswith('.cpp'):
    #             if not 'cpp' in lang_rules:
    #                 ninja_rules += 'CXX = g++\n'
    #                 ninja_rules += 'rule compile_cpp\n'
    #                 ninja_rules += '  command = $CXX ${cxx_flags} ${c_opts} -MMD -MT $out -MF $out.dep -c $in -o $out\n'
    #                 ninja_rules += '  description = compile(cpp) $out\n'
    #                 ninja_rules += '  depfile = $out.dep\n'
    #                 ninja_rules += '  deps = gcc\n\n'
    #                 lang_rules.append('cpp')
    #                 pass
    #             obj_dir = 'obj/'
    #             if pack['section']:
    #                 obj_dir = pack['section'] + '_obj/'
    #                 pass
    #             ninja_builds += 'build %s%s%s: compile_cpp %s\n' % (obj_dir, file, obj_ext, file)
    #             real_files.append('%s%s%s' % (obj_dir, file, obj_ext))
    #             if 'extra_opts' in pack:
    #                 ninja_builds += '  c_opts = %s\n' % pack['extra_opts']
    #                 pass
    #             if pack['comp_flags']:
    #                 ninja_builds += '  cxx_flags = %s\n' % pack['comp_flags']['cpp']
    #                 pass
    #             if 'libs' in pack:
    #                 ninja_builds += '  cxx_flags ='
    #                 for lib, lib_path in pack['libs']:
    #                     ninja_builds += ' -I%s' % os.path.join(lib_path, 'include')
    #                 ninja_builds += '\n'
    #                 pass
    #             pass
    #         pass
    #     pass
    #     if not 'link' in lang_rules:
    #         ninja_rules += 'LINKER_EXE = g++\n'
    #         ninja_rules += 'rule link_exe\n'
    #         ninja_rules += '  command = $LINKER_EXE ${ld_flags} -o $out $in ${ld_libs}\n'
    #         ninja_rules += '  description = link(exe) $out\n\n'
    #         lang_rules.append('link')
    #         pass
    #     # print(len(real_files))
    #     # if len(real_files > 1)
    #     ninja_builds += 'build %s%s: link_exe %s\n' % (target, exe_ext, ' '.join(real_files))
    #     if 'libs' in pack:
    #         ninja_builds += '  ld_flags ='
    #         for lib, lib_path in pack['libs']:
    #             ninja_builds += ' -L%s' % os.path.join(lib_path, 'lib')
    #         ninja_builds += '\n'
    #         ninja_builds += '  ld_libs ='
    #         for lib, lib_path in pack['libs']:
    #             ninja_builds += ' -l%s' % lib
    #         ninja_builds += '\n'
    #         pass

    # ninja_file = 'builddir = ninja\n'
    # ninja_file += ninja_rules
    # ninja_file += ninja_builds
    # print(ninja_file)
    output = open(os.path.join(os.path.dirname(path_to_metal), 'build.ninja'), 'w')
    output.write(ninja)
    output.close()
    os.chdir(before)

if __name__ == '__main__':
    # executed as a script
    
    # get_configs()
    
    metal_file = os.path.join(os.getcwd(), 'metal')
    if os.path.isfile(metal_file):
        shuriken(metal_file)
    else:
        print('no metal file found')

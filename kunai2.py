from cmd import Cmd
import os
cwd = os.getcwd()

class Kunai(Cmd):
    prompt = os.path.relpath(os.getcwd(), cwd) + ' $ '
    def do_exit(self, inp):
        return True
    known_commands = ['exit', 'quit', 'create', 
'run', 'build', 'in', 'ls', 'dir']    
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
            print('wrong')
        else:
            if hasattr(self, 'do_' + found):
                return getattr(self, 'do_' + found)(tokens[1:])
            else:
                print('unimplemented')
    do_quit = do_exit
    do_EOF = do_exit
    places = [cwd]
    def do_in(self, inp):
        tokens = inp.split()
        print(tokens)
        print(len(tokens))
        if len(tokens) != 1:
            print("error: wrong number of arguments to in")
            print("usage: in [dir]")
        if os.path.isdir(tokens[0]):
            self.places.append(tokens[0])
            os.chdir(tokens[0])
            prompt = os.path.relpath(os.getcwd(), cwd) + ' $ '
        else:
            for place in reversed(self.places):
                idx = self.places.index(place)
                possible_dir = os.path.join(cwd, *self.places[:idx+1], tokens[0])
                if os.path.isdir(possible_dir):
                    self.places = self.places[:idx+1]
                    self.places.append(tokens[0])
                    os.chdir(possible_dir)
                    prompt = os.path.relpath(os.getcwd(), cwd) + ' $ '
                    break

k = Kunai()
k.cmdloop()

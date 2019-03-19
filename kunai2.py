from cmd import Cmd

class Kunai(Cmd):
    prompt = '$ '
    def do_exit(self, inp):
        return True
    known_commands = ['exit', 'quit']    
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

k = Kunai()
k.cmdloop()

from queue import Queue
from threading import Thread


class MiHilo(Thread):
    def __init__(self, stdout):
        self.stdout = stdout
        self.captured = ''
        super(MiHilo, self).__init__()

    def run(self):
        while True:
            self.captured = self.stdout.read()
            print('cap: ' + str(self.captured))

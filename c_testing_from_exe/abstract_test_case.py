import unittest
import subprocess
import os
from pathlib import Path

class PruebaAbstracta(unittest.TestCase):

    def setUp(self):
        self.configVar()
        self.p = subprocess.Popen(self.ejecutable, stdout=subprocess.PIPE, stdin=subprocess.PIPE)
        super().setUp()

    def configVar(self):
        self.ejecutable = "..\\..\\cmake-build-debug\\" + self.get_main_exe() + ".exe"

    def get_main_exe(self):
        raiz = os.getcwd()
        for p in Path(raiz).glob("main*"):
            return p.name[:-2]
        return ""

    def tearDown(self):
        self.p.stdin.close()
        self.p.stdout.close()
        self.p.terminate()
        self.p.kill()

    def entro(self, string_val):
        for i in range(12):
            string_val += b'\n'
        self.p.stdin.write(string_val)
        self.p.stdin.flush()


    def leo(self, cant_chars=None):
        if cant_chars is None:
            return self.p.stdout.read()
        return self.p.stdout.read(cant_chars)

    def veo(self, salida_str):
        self.assertEqual(self.leo(), salida_str)

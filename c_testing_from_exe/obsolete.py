import unittest
import subprocess


class MiTest(unittest.TestCase):

    def setUp(self):
        ejecutable = r"C:\Users\Ivan's PC\Documents\GitHub\MiPrimerRepositrioBorrar\q\bin\Debug\q.exe"
        self.p = subprocess.Popen(ejecutable, stdout=subprocess.PIPE, stdin=subprocess.PIPE)
        # warnings.filterwarnings(action="ignore", message="unclosed",
        #                  category=ResourceWarning)
        super().setUp()

    def tearDown(self):
        self.p.terminate()
        self.p.kill()

    def test_A(self):
        # ejecutable = r"C:\Users\Ivan's PC\Documents\tmp\prueba\bin\Debug\prueba.exe"
        p = self.p
        p.stdin.write(b'1\r\n')
        p.stdin.write(b'3\r\n')
        p.stdin.flush()
        self.assertEqual(p.stdout.read(15), b'\x82Hello world!\r\n')
        self.assertEqual(p.stdout.read(16), b'My value is 1 3')
        p.stdin.close()
        p.stdout.close()

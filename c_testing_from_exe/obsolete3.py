from c_testing_from_exe.abstract_test_case import PruebaAbstracta


class PlantillaPrueba2(PruebaAbstracta):
    def configVar(self):
        self.ejecutable = r"C:\Users\Ivan's PC\Documents\GitHub\MiPrimerRepositrioBorrar\q\bin\Debug\q.exe"

    def test_A(yo):
        yo.entro(b"1\r\n3\r\n")
        yo.veo(b'\x82Hello world!\r\nMy value is 1 3')

    def test_B(yo):
        yo.entro(b"1\r\n4\r\n")
        yo.veo(b'\x82Hello world!\r\nMy value is 1 4')

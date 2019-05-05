from c_testing_from_exe.abstract_test_case import PruebaAbstracta

# Recuerda Compilar con las opciones -static-libgcc y -static-libstdc++
# En CodeBlocks, click en Project -> Build options
# Si compilas sin las opciones en CodeBlocks, tendrás que modificar el código fuente para que coja las opciones

class PlantillaPrueba(PruebaAbstracta):

    def configVar(self):
        # CodeBlocks crea el ejecutable en {RutaFolderProjecto}\bin\Debug\{NombreProyecto}.exe
        self.ejecutable = r"C:\Users\Ivan's PC\PycharmProjects\isc-205_este_si\suma2\bin\Debug\suma2.exe"

    # En yo.veo, solo pon lo que el programa escribe en stdout; NO incluir lo digitado por el usuario en stdin
    def test_A(yo):
        yo.entro(b"1\r\n3\r\n")
        yo.veo(b'\x82Digita 2 #s: La suma es: 4\r\n')

    def test_B(yo):
        yo.entro(b"1\n4\n")
        yo.veo(b'\x82Digita 2 #s: La suma es: 5\r\n')


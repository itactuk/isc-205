from c_testing_from_exe.abstract_test_case import PruebaAbstracta

# Recuerda Compilar con las opciones -static-libgcc y -static-libstdc++
# En CodeBlocks, click en Project -> Build options
# Si compilas sin las opciones en CodeBlocks, tendrás que modificar el código fuente para que coja las opciones

class PlantillaPrueba(PruebaAbstracta):

    def configVar(self):
        # CodeBlocks crea el ejecutable en {RutaFolderProjecto}\bin\Debug\{NombreProyecto}.exe
        self.ejecutable = r"..\suma2\bin\Debug\suma2.exe"

    # En yo.veo, solo pon lo que el programa escribe en stdout; NO incluir lo digitado por el usuario en stdin
    # todas las pruebas tienen que comenzar con test
    def test_suma_positiva(yo):
        yo.entro(
            b"1\r\n"
            b"3\r\n"
        )
        yo.veo(
            b"\x82Digita 2 #s: "
            b"La suma es: 4\r\n"
        )

    def test_suma_negativa(yo):
        yo.entro(
            b"-1\n"
            b"-4\n"
        )
        yo.veo(
            b"\x82Digita 2 #s: "
            b"La suma es: -5\r\n"
        )

    def test_suma_pos_neg(yo):
        yo.entro(
            b"-1\n"
            b"4\n"
        )
        yo.veo(
            b"\x82Digita 2 #s: "
            b"La suma es: 3\r\n"
        )

from c_testing_from_exe.abstract_test_case import PruebaAbstracta


class PlantillaPrueba(PruebaAbstracta):
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

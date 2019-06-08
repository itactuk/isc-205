#include "minunit.h"
#include <math.h>
#include "../ProblemaTeoriaString/comparacion_string.h"

MU_TEST(test_imaginario) {
	mu_assert(isnan(sqrt(-1)),"No es imaginario");
}

MU_TEST(test_agrega_final_elemento) {
	mu_assert_int_eq(2, compara("Hola", 4, "Holass", 6));
}

MU_TEST(test_agrega_inicio_elemento) {
	mu_assert_int_eq(2, compara("Hola", 4, "ssHola", 6));
}

MU_TEST(test_intercambio) {
	mu_assert_int_eq(1, compara("Hola", 4, "Holx", 4));
}

MU_TEST(test_complicado) {
	mu_assert_int_eq(3, compara("aHsola", 6, "Holx", 4));
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_imaginario);
	MU_RUN_TEST(test_agrega_final_elemento);
	MU_RUN_TEST(test_agrega_inicio_elemento);
	MU_RUN_TEST(test_intercambio);
	MU_RUN_TEST(test_complicado);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

#include "minunit.h"
#include "../ProblemaTeoriaString/comparacion_string.h"

MU_TEST(test_iguales) {
	mu_assert_int_eq(0, compara("ho", 2, "ho", 2));
}

MU_TEST(test_diff_tamano) {
	mu_assert_int_eq(1, compara("hos", 3, "ho", 2));
}

MU_TEST(test_intercambio) {
	mu_assert_int_eq(1, compara("has", 3, "hos", 3));
}

MU_TEST(test_complicado) {
	mu_assert_int_eq(3, compara("holsf", 5, "hosda", 5));
	mu_assert_int_eq(4, compara("aholsf", 6, "hosda", 5));
}


MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_iguales);
	MU_RUN_TEST(test_diff_tamano);
	MU_RUN_TEST(test_intercambio);
	MU_RUN_TEST(test_complicado);
}

int main()
{
    MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

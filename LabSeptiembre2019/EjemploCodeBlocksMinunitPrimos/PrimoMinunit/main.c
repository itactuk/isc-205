//
// Created by Ivan Tactuk on 10/3/2019.
//

#include "minunit.h"

#include "../PrimosMain/miLibreria.h"

#define MINUNIT_EPSILON 1E-5

MU_TEST(test_esprimo2) {
    mu_assert_int_eq(1, esprimo(2));
}

MU_TEST(test_esprimo23) {
    mu_assert_int_eq(1, esprimo(23));
}

MU_TEST(test_esprimo16) {
    mu_assert_int_eq(0, esprimo(16));
}

MU_TEST(test_esprimoError) {
    mu_assert_int_eq(-1, esprimo(-4));
}

MU_TEST(test_PromedioVacio) {
    mu_assert_double_eq(2, calc_promedio_numeros_primos(1,1));
}

MU_TEST(test_PromedioPequeno) {
    mu_assert_double_eq(6.5, calc_promedio_numeros_primos(2,5));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_esprimo2);
    MU_RUN_TEST(test_esprimo23);
    MU_RUN_TEST(test_esprimo16);
    MU_RUN_TEST(test_esprimoError);
    MU_RUN_TEST(test_PromedioVacio);
    MU_RUN_TEST(test_PromedioPequeno);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}

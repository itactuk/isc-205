//
// Created by Ivan Tactuk on 6/19/2019.
//

#include <minunit.h>

#include "funciones_recursivas.h"

#define MINUNIT_EPSILON 1E-12

MU_TEST(test_prueba22_aux) {
    mu_assert_int_eq(132, suma_rec_pos_a(22, 0));
}

MU_TEST(test_prueba22) {
    mu_assert_int_eq(132, suma_rec_pos(22));
}

MU_TEST(test_cond_parada) {
    mu_assert_int_eq(0, suma_rec_pos(0));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_prueba22);
    MU_RUN_TEST(test_cond_parada);
    MU_RUN_TEST(test_prueba22_aux);
    
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
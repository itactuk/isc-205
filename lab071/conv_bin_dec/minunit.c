//
// Created by Ivan's PC on 6/13/2019.
//
#include "minunit.h"
#include "conversion.h"

#define MINUNIT_EPSILON 1E-12

MU_TEST(test_pruebamia) {
    mu_assert_int_eq(2, conv(10));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_pruebamia);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}


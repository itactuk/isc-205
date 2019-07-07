//
// Created by Ivan Tactuk on 6/15/2019.
//
#include "leveshtein.h"
#include <minunit.h>



#define MINUNIT_EPSILON 1E-12

MU_TEST(test_hola_hola) {
    char a[] = "hola";
    char b[] = "hola";
    int i=0,j=0;
    while (a[++i]!='\0');
    while (b[++j]!='\0');
    mu_assert_int_eq(0, lev(a,b,i,j));
}

MU_TEST(test_xhola_zhola) {
    char a[] = "xhola";
    char b[] = "zhola";
    int i=0,j=0;
    while (a[++i]!='\0');
    while (b[++j]!='\0');
    mu_assert_int_eq(1, lev(a,b,i,j));
}

MU_TEST(test_xhxla_zhola) {
    char a[] = "xhxla";
    char b[] = "zhola";
    int i=0,j=0;
    while (a[++i]!='\0');
    while (b[++j]!='\0');
    mu_assert_int_eq(2, lev(a,b,i,j));
}

MU_TEST(test_xholax_zhola) {
    char a[] = "xholax";
    char b[] = "zhola";
    int i=0,j=0;
    while (a[++i]!='\0');
    while (b[++j]!='\0');
    mu_assert_int_eq(2, lev(a,b,i,j));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_hola_hola);
    MU_RUN_TEST(test_xhola_zhola);
    MU_RUN_TEST(test_xhxla_zhola);
    MU_RUN_TEST(test_xholax_zhola);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
#include <check.h>
#include "mult.h"

START_TEST(one_one)
{   
    int in1[] = {10};
    int in2[] = {5};
    int result[] = {0};
    int out[] = {50};
    int size = 1;

    multiply(result, in1, in2, size);
    ck_assert_mem_eq(result, out, size * size * sizeof(int));
}
END_TEST

START_TEST(three_three)
{   
    int in1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int in2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int result[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int out[] = {30, 24, 18, 84, 69, 54, 138, 114, 90};
    int size = 3;

    multiply(result, in1, in2, size);
    ck_assert_mem_eq(result, out, size * size * sizeof(int));
}
END_TEST

START_TEST(ones_reg)
{   
    int in1[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    int in2[] = {1, 2, 3, 6, 5, 4, 7, 8, 9};
    int result[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int out[] = {1, 2, 3, 6, 5, 4, 7, 8, 9};
    int size = 3;

    multiply(result, in1, in2, size);
    ck_assert_mem_eq(result, out, size * size * sizeof(int));
}
END_TEST

START_TEST(reg_ones)
{   
    int in2[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    int in1[] = {1, 2, 3, 6, 5, 4, 7, 8, 9};
    int result[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int out[] = {1, 2, 3, 6, 5, 4, 7, 8, 9};
    int size = 3;

    multiply(result, in1, in2, size);
    ck_assert_mem_eq(result, out, size * size * sizeof(int));
}
END_TEST

START_TEST(with_zeroes)
{   
    int in1[] = {1, 2, 3, 4};
    int in2[] = {0, 0, 0, 0};
    int result[] = {0, 0, 0, 0};
    int out[] = {0, 0, 0, 0};
    int size = 2;

    multiply(result, in1, in2, size);
    ck_assert_mem_eq(result, out, size * size * sizeof(int));
}
END_TEST

START_TEST(with_ones)
{   
    int in1[] = {1, 2, 3, 4};
    int in2[] = {1, 1, 1, 1};
    int result[] = {0, 0, 0, 0};
    int out[] = {3, 3, 7, 7};
    int size = 2;

    multiply(result, in1, in2, size);
    ck_assert_mem_eq(result, out, size * size * sizeof(int));
}
END_TEST


Suite* multiply_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("multiply");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, one_one);
    tcase_add_test(tc_pos, three_three);
    tcase_add_test(tc_pos, ones_reg);
    tcase_add_test(tc_pos, reg_ones);
    tcase_add_test(tc_pos, with_zeroes);
    tcase_add_test(tc_pos, with_ones);

    suite_add_tcase(s, tc_pos);
    return s;
}

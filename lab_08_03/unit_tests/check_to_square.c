#include <check.h>
#include "make_square.h"


START_TEST(one)
{
    int in[] = {1};
    int out[] = {1};
    int n = 1, m = 1;

    rebuild_to_square(in, &m, &n);
    ck_assert_mem_eq(in, out, n * m * sizeof(int));
}
END_TEST

START_TEST(squared)
{
    int in[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int out[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int n = 4, m = 4;

    rebuild_to_square(in, &m, &n);
    ck_assert_mem_eq(in, out, n * m * sizeof(int));
}
END_TEST

START_TEST(delete_columns)
{
    int in[] = {7, 4, 9, 7, 8, 8, 9, 1, 6, 5};
    int out[] = {7, 8, 6, 5};
    int n = 5, m = 2;

    rebuild_to_square(in, &m, &n);
    ck_assert_mem_eq(in, out, n * m * sizeof(int));
}
END_TEST

START_TEST(delete_rows)
{
    int in[] = {4, 9, 8, 7, 9, 1};
    int out[] = {4, 9, 8, 7};
    int n = 2, m = 3;

    rebuild_to_square(in, &m, &n);
    ck_assert_mem_eq(in, out, n * m * sizeof(int));
}
END_TEST

START_TEST(one_row)
{
    int in[] = {7, 3, 6, 5};
    int out[] = {3};
    int n = 4, m = 1;

    rebuild_to_square(in, &m, &n);
    ck_assert_mem_eq(in, out, n * m * sizeof(int));
}
END_TEST

START_TEST(one_column)
{
    int in[] = {9, 8, 8, 10};
    int out[] = {8};
    int n = 1, m = 4;

    rebuild_to_square(in, &m, &n);
    ck_assert_mem_eq(in, out, n * m * sizeof(int));
}
END_TEST

Suite* make_square_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("make_square");

    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, one);
    tcase_add_test(tc_pos, squared);
    tcase_add_test(tc_pos, delete_columns);
    tcase_add_test(tc_pos, delete_rows);
    tcase_add_test(tc_pos, one_row);
    tcase_add_test(tc_pos, one_column);

    suite_add_tcase(s, tc_pos);
    return s;
}

#include <check.h>
#include "../lib/lib.h"
#include <stdlib.h>

int res_array[10] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };

START_TEST(test_fibonacci_1)
{
    int array[5];
    int count = 5;

    fib(array, count);

    for (int i = 0; i < 5; i++)
        ck_assert_int_eq(res_array[i], array[i]);
}
END_TEST

START_TEST(test_fibonacci_2)
{
    int array[1];
    int count = 1;

    fib(array, count);

    int res_array[1] = { 0 };

    for (int i = 0; i < 1; i++)
        ck_assert_int_eq(res_array[i], array[i]);
}
END_TEST

START_TEST(test_fibonacci_3)
{
    int array[2];
    int count = 2;

    fib(array, count);

    for (int i = 0; i < 2; i++)
        ck_assert_int_eq(res_array[i], array[i]);
}
END_TEST

START_TEST(first_all_duplicates)
{
    int src_size = 3;
    int dest_size = 1;
    int src[] = {1, 1, 1};
    int *dst = malloc(dest_size * sizeof(int));
    int target[] = {1};

    int err = first_entry(src, src_size, dst, &dest_size);

    ck_assert_int_eq(err, 0);
    ck_assert_mem_eq(dst, target, dest_size * sizeof(int));

    free(dst);
}
END_TEST


// All uniq
START_TEST(first_all_uniq)
{
    int src_size = 3;
    int dest_size = 3;
    int src[] = {1, 2, 3};
    int *dst = malloc(dest_size * sizeof(int));
    int target[] = {1,2,3};

    int err = first_entry(src, src_size, dst, &dest_size);

    ck_assert_int_eq(err, 0);
    ck_assert_mem_eq(dst, target, dest_size * sizeof(int));

    free(dst);
}
END_TEST

// Pair in another place

START_TEST(first_different)
{
    int src_size = 10;
    int dest_size = 6;
    int src[] = {1, 1, 5, 4, 3, 4, 7, 1, 9, 9};
    int *dst = malloc(dest_size * sizeof(int));
    int target[] = {1, 5, 4, 3, 7, 9};

    int err = first_entry(src, src_size, dst, &dest_size);

    ck_assert_int_eq(err, 0);
    ck_assert_mem_eq(dst, target, dest_size * sizeof(int));

    free(dst);
}
END_TEST

// Sourse is null
START_TEST(first_null_src)
{
    int dest_size = 10;
    int err = first_entry(NULL, 10, NULL, &dest_size);

    ck_assert_int_eq(err, 1);

}
END_TEST

// Sourse is empty
START_TEST(first_zero_size)
{
    int dest_size = 10;
    int a[] = {0}; 
    int err = first_entry(a, 0, NULL, &dest_size);

    ck_assert_int_eq(err, 1);

}
END_TEST

Suite *functions_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  FUNCTIONS  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_fibonacci_1);
    tcase_add_test(tc_pos, test_fibonacci_2);
    tcase_add_test(tc_pos, test_fibonacci_3);
    tcase_add_test(tc_pos, first_all_duplicates);
    tcase_add_test(tc_pos, first_all_uniq);
    tcase_add_test(tc_pos, first_different);
    tcase_add_test(tc_pos, first_null_src);
    tcase_add_test(tc_pos, first_zero_size);
    suite_add_tcase(s, tc_pos);

    return s;
}
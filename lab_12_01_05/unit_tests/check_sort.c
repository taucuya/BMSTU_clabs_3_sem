#include <check.h>
#include "../inc/sort.h"

START_TEST(same_int)
{   
    int in[] = {10, 10, 10};
    int out[] = {10, 10, 10};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_int);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(one_int)
{   
    int in[] = {1};
    int out[] = {1};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_int);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(sorted_int)
{   
    int in[] = {12, 34, 45, 67, 78, 90, 123, 1234, 12345};
    int out[] = {12, 34, 45, 67, 78, 90, 123, 1234, 12345};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_int);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(reversed_int)
{   
    int in[] = {12, 10, 8, 6, 4, 2};
    int out[] = {2, 4, 6, 8, 10, 12};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_int);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(sorted_part_int)
{   
    int in[] = {12, 34, 56, 1, 2, 90};
    int out[] = {1, 2, 12, 34, 56, 90};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_int);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(general_int)
{   
    int in[] = {9, 8, 3, 11, 1, 4, 7, 7, 7, 9};
    int out[] = {1, 3, 4, 7, 7, 7, 8, 9, 9, 11};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_int);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST


START_TEST(same_double)
{   
    double in[] = {12.4, 12.4, 12.4};
    double out[] = {12.4, 12.4, 12.4};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_double);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(one_double)
{   
    double in[] = {13.444};
    double out[] = {13.444};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_double);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(sorted_double)
{   
    double in[] = {0.001, -0.02, 0.12, 0.018};
    double out[] = {-0.02, 0.001, 0.018, 0.12};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_double);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(reversed_double)
{   
    double in[] = {13.45, 9.9, 7.364, 4.444};
    double out[] = {4.444, 7.364, 9.9, 13.45};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_double);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(sorted_part_double)
{   
    double in[] = {12.4, 15.89, 19.7, 1.67};
    double out[] = {1.67, 12.4, 15.89, 19.7};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_double);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(general_double)
{   
    double in[] = {12.4, 12.5, 12.3, 12.3, 14.6};
    double out[] = {12.3, 12.3, 12.4, 12.5, 14.6};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_double);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST


START_TEST(same_char)
{   
    char in[] = {'a', 'a', 'a'};
    char out[] = {'a', 'a', 'a'};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_string);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(one_char)
{   
    char in[] = {'o'};
    char out[] = {'o'};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_string);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(register_char)
{   
    char in[] = {'a', 'A'};
    char out[] = {'A', 'a'};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_string);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(sorted_char)
{   
    char in[] = {'a', 'b', 'c'};
    char out[] = {'a', 'b', 'c'};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_string);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(reversed_char)
{   
    char in[] = {'c', 'b', 'a'};
    char out[] = {'a', 'b', 'c'};;
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_string);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(sorted_part_char)
{   
    char in[] = {'c', 'x', 'y', 'z', 'a'};
    char out[] = {'a', 'c', 'x', 'y', 'z'};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_string);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

START_TEST(general_char)
{   
    char in[] = {'q', 'a', 'w', 'c'};
    char out[] = {'a', 'c', 'q', 'w'};
    int nmemb = sizeof(in) / sizeof(in[0]);
    int size = sizeof(in[0]);

    mysort(in, nmemb, size, comp_string);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST



Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("mysort");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, same_int);
    tcase_add_test(tc_pos, one_int);
    tcase_add_test(tc_pos, sorted_int);
    tcase_add_test(tc_pos, reversed_int);
    tcase_add_test(tc_pos, sorted_part_int);
    tcase_add_test(tc_pos, general_int);

    tcase_add_test(tc_pos, same_double);
    tcase_add_test(tc_pos, one_double);
    tcase_add_test(tc_pos, sorted_double);
    tcase_add_test(tc_pos, reversed_double);
    tcase_add_test(tc_pos, sorted_part_double);
    tcase_add_test(tc_pos, general_double);

    tcase_add_test(tc_pos, same_char);
    tcase_add_test(tc_pos, one_char);
    tcase_add_test(tc_pos, register_char);
    tcase_add_test(tc_pos, sorted_char);
    tcase_add_test(tc_pos, reversed_char);
    tcase_add_test(tc_pos, sorted_part_char);
    tcase_add_test(tc_pos, general_char);

    suite_add_tcase(s, tc_pos);
    return s;
}

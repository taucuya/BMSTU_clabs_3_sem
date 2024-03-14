#include <check.h>
#include "sort.h"
#include "item.h"

// One element

START_TEST(one)
{
    itm in[] = { {"abc", 10, 100} };
    itm out[] = { {"abc", 10, 100} };
    int size = 1;
    sort(in, size);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

// Four same elements

START_TEST(same)
{
    itm in[] = { {"abc", 10, 100}, {"abc", 10, 100}, {"abc", 10, 100}, {"abc", 10, 100} };
    itm out[] = { {"abc", 10, 100}, {"abc", 10, 100}, {"abc", 10, 100}, {"abc", 10, 100} };
    int size = 4;
    sort(in, size);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

// Some general test random four elements

START_TEST(some)
{
    itm in[] = { {"abc", 100, 10}, {"def", 10, 10}, {"ghi", 50, 10}, {"jkl", 1000, 10} };
    itm out[] = { {"def", 10, 10}, {"ghi", 50, 10}, {"abc", 100, 10}, {"jkl", 1000, 10} };
    int size = 4;
    sort(in, size);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

// Fully reversed array

START_TEST(reversed)
{
    itm in[] = { {"jkl", 1000, 10}, {"ghi", 500, 10}, {"def", 100, 10}, {"abc", 50, 10} };
    itm out[] = { {"abc", 50, 10}, {"def", 100, 10}, {"ghi", 500, 10}, {"jkl", 1000, 10} };
    int size = 4;
    sort(in, size);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

// Almost correct array

START_TEST(almost_correct)
{
    itm in[] = { {"abc", 10, 10}, {"def", 500, 10}, {"ghi", 1000, 10}, {"jkl", 100, 10} };
    itm out[] = { {"abc", 10, 10}, {"jkl", 100, 10}, {"def", 500, 10}, {"ghi", 1000, 10} };
    int size = 4;
    sort(in, size);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

// Some same elements

START_TEST(some_same)
{
    itm in[] = { {"ghi", 1000, 10}, {"abc", 10, 10}, {"def", 10, 10}, {"jkl", 100, 10} };
    itm out[] = { {"abc", 10, 10}, {"def", 10, 10}, {"jkl", 100, 10}, {"ghi", 1000, 10} };
    int size = 4;
    sort(in, size);
    ck_assert_mem_eq(in, out, sizeof(in));
}
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("sort");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, one);
    tcase_add_test(tc_pos, same);
    tcase_add_test(tc_pos, some);
    tcase_add_test(tc_pos, reversed);
    tcase_add_test(tc_pos, almost_correct);
    tcase_add_test(tc_pos, some_same);

    suite_add_tcase(s, tc_pos);
    return s;
}
#include <check.h>
#include "add.h"

START_TEST(two_to_three)
{   
    int in[] = {1, 2, 3, 4, 0, 0, 0, 0, 0};
    int out[] = {1, 2, 2, 3, 4, 4, 2, 3, 3};
    int beg = 2, end = 3;

    rebuild(in, end, beg);
    
    ck_assert_mem_eq(in, out, end * end * sizeof(int));
}
END_TEST

START_TEST(same)
{   
    int in[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int out[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int beg = 3, end = 3;

    rebuild(in, end, beg);
    ck_assert_mem_eq(in, out, end * end * sizeof(int));
}
END_TEST


Suite* add_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("add");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, two_to_three);
    tcase_add_test(tc_pos, same);

    suite_add_tcase(s, tc_pos);
    return s;
}

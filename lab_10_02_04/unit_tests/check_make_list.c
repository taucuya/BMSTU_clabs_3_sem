#include <check.h>
#include "../inc/act.h"
#include "../inc/list.h"


// positives
// 1

START_TEST(one)
{
    int in = 1;
    num_t *head = NULL;

    make_list(&head, in);
    ck_assert_ptr_eq(head, NULL);
}
END_TEST

// 456

START_TEST(big)
{
    int in = 456;
    num_t *head = NULL;

    num_t *first = create_node(19, 1);
    num_t *second = create_node(3, 1);
    num_t *third = create_node(2, 3);

    first->next = second;
    second->next = third;

    make_list(&head, in);

    int err = compare(&head, &first);

    ck_assert_int_eq(err, 0);

    free_list(&head);
    free_list(&first);
}

// 12

START_TEST(gen)
{
    int in = 12;
    num_t *head = NULL;

    num_t *first = create_node(3, 1);
    num_t *second = create_node(2, 2);

    first->next = second;

    make_list(&head, in);
    int err = compare(&head, &first);

    ck_assert_int_eq(err, 0);

    free_list(&head);
    free_list(&first);
}
END_TEST

Suite* make_list_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("make_list");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, one);
    tcase_add_test(tc_pos, big);
    tcase_add_test(tc_pos, gen);

    suite_add_tcase(s, tc_pos);
    return s;
}
#include <check.h>
#include "../inc/act.h"

// positives
// 1 * 1

START_TEST(one)
{
    num_t *head1 = NULL;
    num_t *head2 = NULL;
    num_t *head_res = NULL;

    multiply(&head1, &head2, &head_res);

    ck_assert_ptr_eq(head_res, NULL);
}
END_TEST

// 456 * 12 = 5472

START_TEST(big)
{
    num_t *head_res = NULL;

    num_t *real = NULL;

    make_list(&real, 5472);

    num_t *first_1 = create_node(19, 1);
    num_t *second_1 = create_node(3, 1);
    num_t *third_1 = create_node(2, 3);

    num_t *first_2 = create_node(3, 1);
    num_t *second_2 = create_node(2, 2);

    first_1->next = second_1;
    second_1->next = third_1;

    first_2->next = second_2;

    multiply(&first_1, &first_2, &head_res);

    int err = compare(&real, &head_res);

    free_list(&first_1);
    free_list(&first_2);
    free_list(&head_res);
    free_list(&real);

    ck_assert_int_eq(err, SUCCESS);
}

// 12 * 1

START_TEST(on_one)
{
    num_t *head = NULL;
    num_t *head_res = NULL;

    num_t *first = create_node(3, 1);
    num_t *second = create_node(2, 2);

    first->next = second;

    multiply(&head, &first, &head_res);

    int err = compare(&first, &head_res);

    free_list(&first);
    free_list(&head_res);

    ck_assert_int_eq(err, SUCCESS);
}
END_TEST

Suite* multiply_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("multiply");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, one);
    tcase_add_test(tc_pos, big);
    tcase_add_test(tc_pos, on_one);

    suite_add_tcase(s, tc_pos);
    return s;
}
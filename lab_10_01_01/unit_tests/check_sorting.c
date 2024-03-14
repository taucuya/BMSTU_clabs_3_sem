#include "../inc/check_sorting.h"

/* Storage mock */
int storage_sorted[] = { 1, 2, 3, 4 };
int storage_identical[] = { 1, 1, 1, 1 };
int storage_random[] = { 7, -1, 8, 0 };

START_TEST(empty)
{
    node_t *head = NULL;
    node_t *head_sorted = sort(head, comparator_price);

    ck_assert_ptr_eq(head_sorted, NULL);
}
END_TEST


START_TEST(single_element)
{
    node_t *first = init_node((void *) &storage_sorted[0]);

    node_t *head_sorted = sort(first, comparator_price);
    ck_assert_int_eq(*(int *) head_sorted->data, storage_sorted[0]);
    list_free(&head_sorted);
}
END_TEST


START_TEST(reversed)
{
    
    node_t *f = init_node((void *) &storage_sorted[0]);
    node_t *t = init_node((void *) &storage_sorted[1]);
    node_t *sec = init_node((void *) &storage_sorted[2]);
    node_t *first = init_node((void *) &storage_sorted[3]);
    first->next = sec;
    sec->next = t;
    t->next = f;
    f->next = NULL;

    node_t *head_sorted = sort(first, comparator_price);

    node_t *fo = init_node((void *) &storage_sorted[3]);
    node_t *th = init_node((void *) &storage_sorted[2]);
    node_t *se = init_node((void *) &storage_sorted[1]);
    node_t *fi = init_node((void *) &storage_sorted[0]);

    fi->next = se;
    se->next = th;
    th->next = fo;
    fo->next = NULL;

    for (size_t i = 0; i < 4; ++i)
    {
        ck_assert_int_eq(*(int *) head_sorted->data, *(int *) fi->data);
    }

    list_free(&fi);
    // list_free(&first);
    list_free(&head_sorted);
}
END_TEST

START_TEST(random_order)
{
    node_t *f = init_node((void *) &storage_random[3]);
    node_t *t = init_node((void *) &storage_random[2]);
    node_t *sec = init_node((void *) &storage_random[1]);
    node_t *first = init_node((void *) &storage_random[0]);
    first->next = sec;
    sec->next = t;
    t->next = f;
    f->next = NULL;

    node_t *head_sorted = sort(first, comparator_price);
    
    node_t *fo = init_node((void *) &storage_random[1]);
    node_t *th = init_node((void *) &storage_random[3]);
    node_t *se = init_node((void *) &storage_random[0]);
    node_t *fi = init_node((void *) &storage_random[2]);

    fi->next = se;
    se->next = th;
    th->next = fo;
    fo->next = NULL;

    ck_assert_int_eq(*(int *) head_sorted->data, *(int *) fi->data);

    list_free(&fi);
    // list_free(&first);
    list_free(&head_sorted);
}
END_TEST

START_TEST(identical)
{
    node_t *f = init_node((void *) &storage_identical[3]);
    node_t *t = init_node((void *) &storage_identical[2]);
    node_t *sec = init_node((void *) &storage_identical[1]);
    node_t *first = init_node((void *) &storage_identical[0]);
    first->next = sec;
    sec->next = t;
    t->next = f;
    f->next = NULL;

    node_t *head_sorted = sort(first, comparator_price);
    
    node_t *fo = init_node((void *) &storage_identical[0]);
    node_t *th = init_node((void *) &storage_identical[1]);
    node_t *se = init_node((void *) &storage_identical[2]);
    node_t *fi = init_node((void *) &storage_identical[3]);

    fi->next = se;
    se->next = th;
    th->next = fo;
    fo->next = NULL;

    for (size_t i = 0; i < 4; ++i)
    {
        ck_assert_int_eq(*(int *) head_sorted->data, *(int *) fi->data);
    }

    list_free(&fi);
    // list_free(&first);
    list_free(&head_sorted);
}
END_TEST

////////////////////////////////////////////////////////////

START_TEST(pop_f_empty)
{
    node_t *head = NULL;
    void *popped_data = pop_front(&head);

    ck_assert_ptr_eq(popped_data, NULL);
}
END_TEST

START_TEST(pop_f_single)
{
    node_t *first = init_node((void *) &storage_identical[0]);

    void *popped_data = pop_front(&first);

    ck_assert_int_eq(*(int*) popped_data, storage_identical[0]);
    list_free(&first);
}
END_TEST

START_TEST(pop_f_multiple)
{
    node_t *s = init_node((void *) &storage_identical[1]);
    node_t *first = init_node((void *) &storage_identical[0]);
    first->next = s;
    s->next = NULL;
    void *popped_data = pop_front(&first);

    ck_assert_int_eq(*(int*) popped_data, storage_identical[0]);
    list_free(&first);
}
END_TEST
////////////////////////////////////////////////////////////

START_TEST(pop_b_empty)
{
    node_t *head = NULL;
    void *popped_data = pop_back(&head);

    ck_assert_ptr_eq(popped_data, NULL);
}
END_TEST

START_TEST(pop_b_single)
{
    node_t *first = init_node((void *) &storage_identical[0]);
    void *popped_data = pop_back(&first);

    ck_assert_int_eq(*(int*) popped_data, storage_identical[0]);
    list_free(&first);
}
END_TEST

START_TEST(pop_b_multiple)
{
    node_t *s = init_node((void *) &storage_identical[0]);
    node_t *first = init_node((void *) &storage_identical[1]);
    first->next = s;
    s->next = NULL;
    void *popped_data = pop_back(&first);

    ck_assert_int_eq(*(int*) popped_data, storage_identical[0]);
    list_free(&first);
}
END_TEST

////////////////////////////////////////////////////////////

START_TEST(insert_empty)
{
    node_t *head = init_node((void *) &storage_identical[0]);
    node_t *new_node = NULL;

    sorted_insert(&new_node, head, comparator_price);

    node_t *head_e = init_node((void *) &storage_identical[0]);

    ck_assert_int_eq(*(int *) head->data, *(int *) head_e->data);

    free(head);
    free(head_e);
}
END_TEST 

START_TEST(insert_middle)
{
    node_t *th = init_node((void *) &storage_sorted[3]);
    node_t *se = init_node((void *) &storage_sorted[2]);
    node_t *fi = init_node((void *) &storage_sorted[0]);

    fi->next = se;
    se->next = th;
    th->next = NULL;

    node_t *new_node = init_node((void *) &storage_sorted[1]);

    sorted_insert(&fi, new_node, comparator_price);

    node_t *f = init_node((void *) &storage_sorted[3]);
    node_t *t = init_node((void *) &storage_sorted[2]);
    node_t *sec = init_node((void *) &storage_sorted[1]);
    node_t *first = init_node((void *) &storage_sorted[0]);
    first->next = sec;
    sec->next = t;
    t->next = f;
    f->next = NULL;

    ck_assert_int_eq(*(int *) fi->data, *(int *) first->data);
    
    list_free(&first);
    list_free(&fi);
}
END_TEST

START_TEST(insert_head)
{
    node_t *th = init_node((void *) &storage_sorted[2]);
    node_t *se = init_node((void *) &storage_sorted[1]);
    node_t *fi = init_node((void *) &storage_sorted[0]);

    fi->next = se;
    se->next = th;
    th->next = NULL;

    node_t *new_node = init_node((void *) &storage_sorted[3]);

    sorted_insert(&fi, new_node, comparator_price);

    node_t *f = init_node((void *) &storage_sorted[3]);
    node_t *t = init_node((void *) &storage_sorted[2]);
    node_t *sec = init_node((void *) &storage_sorted[1]);
    node_t *first = init_node((void *) &storage_sorted[0]);
    first->next = sec;
    sec->next = t;
    t->next = f;
    f->next = NULL;

    ck_assert_int_eq(*(int *) fi->data, *(int *) first->data);
    
    list_free(&first);
    list_free(&fi);
}
END_TEST

START_TEST(insert_tail)
{
    node_t *th = init_node((void *) &storage_sorted[3]);
    node_t *se = init_node((void *) &storage_sorted[2]);
    node_t *fi = init_node((void *) &storage_sorted[1]);

    fi->next = se;
    se->next = th;
    th->next = NULL;

    node_t *new_node = init_node((void *) &storage_sorted[0]);

    sorted_insert(&fi, new_node, comparator_price);

    node_t *f = init_node((void *) &storage_sorted[3]);
    node_t *t = init_node((void *) &storage_sorted[2]);
    node_t *sec = init_node((void *) &storage_sorted[1]);
    node_t *first = init_node((void *) &storage_sorted[0]);
    first->next = sec;
    sec->next = t;
    t->next = f;
    f->next = NULL;

    ck_assert_int_eq(*(int *) fi->data, *(int *) first->data);
    
    list_free(&first);
    list_free(&fi);
}
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Sort");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, empty);
    tcase_add_test(tc_pos, single_element);
    tcase_add_test(tc_pos, reversed);
    tcase_add_test(tc_pos, identical);
    tcase_add_test(tc_pos, random_order);

    suite_add_tcase(s, tc_pos);

    return s;
}

Suite* sort_inserted_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Sort inserted");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, insert_empty);
    tcase_add_test(tc_pos, insert_head);
    tcase_add_test(tc_pos, insert_tail);
    tcase_add_test(tc_pos, insert_middle);

    suite_add_tcase(s, tc_pos);

    return s;
}

Suite* pop_front_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Pop front");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, pop_f_empty);
    tcase_add_test(tc_pos, pop_f_single);
    tcase_add_test(tc_pos, pop_f_multiple);

    suite_add_tcase(s, tc_pos);

    return s;
}

Suite* pop_back_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Pop back");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, pop_b_empty);
    tcase_add_test(tc_pos, pop_b_single);
    tcase_add_test(tc_pos, pop_b_multiple);

    suite_add_tcase(s, tc_pos);

    return s;
}
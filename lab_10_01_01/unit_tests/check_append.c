#include "../inc/check_append.h"



START_TEST(add_to_one)
{
    int in[] = { 1, 2, 3, 4 };
    
    node_t *f = init_node((void *) &in[3]);
    node_t *t = init_node((void *) &in[2]);
    node_t *s = init_node((void *) &in[1]);
    node_t *first = init_node((void *) &in[0]);
    first->next = s;
    s->next = t;
    t->next = f;
    f->next = NULL;

    node_t *head_b = init_node((void *) &in[3]);

    append(&head_b, &first);

    node_t *fi = init_node((void *) &in[3]);
    node_t *five = init_node((void *) &in[3]);
    node_t *fo = init_node((void *) &in[2]);
    node_t *th = init_node((void *) &in[1]);
    node_t *se = init_node((void *) &in[0]);
    fi->next = se;
    se->next = th;
    th->next = fo;
    fo->next = five;
    five->next = NULL;

    int err = cmp(&head_b, &fi);

    ck_assert_int_eq(err, LISTS_EQUAL);
    
    list_free(&head_b);
    list_free(&first);
    list_free(&fi);
}
END_TEST

START_TEST(add_one)
{
    int in[] = { 1, 2, 4, 3 };

    node_t *f = init_node((void *) &in[3]);
    node_t *t = init_node((void *) &in[2]);
    node_t *s = init_node((void *) &in[1]);
    node_t *first = init_node((void *) &in[0]);
    first->next = s;
    s->next = t;
    t->next = f;
    f->next = NULL;

    node_t *head_b = init_node((void *) &in[3]);

    append(&first, &head_b);

    node_t *five = init_node((void *) &in[3]);
    node_t *fo = init_node((void *) &in[3]);
    node_t *th = init_node((void *) &in[2]);
    node_t *se = init_node((void *) &in[1]);
    node_t *fi = init_node((void *) &in[0]);
    fi->next = se;
    se->next = th;
    th->next = fo;
    fo->next = five;
    five->next = NULL;

    int err = cmp(&first, &fi);

    ck_assert_int_eq(err, LISTS_EQUAL);
    
    list_free(&fi);
    list_free(&head_b);
    list_free(&first);
}
END_TEST

START_TEST(empty_b)
{
    int in[] = { 1, 2, 4, 3 };

    node_t *f = init_node((void *) &in[3]);
    node_t *t = init_node((void *) &in[2]);
    node_t *s = init_node((void *) &in[1]);
    node_t *first = init_node((void *) &in[0]);
    first->next = s;
    s->next = t;
    t->next = f;
    f->next = NULL;

    node_t *head_b = NULL;

    append(&first, &head_b);

    node_t *fo = init_node((void *) &in[3]);
    node_t *th = init_node((void *) &in[2]);
    node_t *se = init_node((void *) &in[1]);
    node_t *fi = init_node((void *) &in[0]);
    fi->next = se;
    se->next = th;
    th->next = fo;
    fo->next = NULL;

    int err = cmp(&first, &fi);

    ck_assert_int_eq(err, LISTS_EQUAL);
    
    list_free(&fi);
    list_free(&first);
}
END_TEST

START_TEST(empty_a)
{
    int in[] = { 1, 2, 4, 3 };

    node_t *f = init_node((void *) &in[3]);
    node_t *t = init_node((void *) &in[2]);
    node_t *s = init_node((void *) &in[1]);
    node_t *first = init_node((void *) &in[0]);
    first->next = s;
    s->next = t;
    t->next = f;
    f->next = NULL;

    node_t *head_b = NULL;

    append(&head_b, &first);

    node_t *fo = init_node((void *) &in[3]);
    node_t *th = init_node((void *) &in[2]);
    node_t *se = init_node((void *) &in[1]);
    node_t *fi = init_node((void *) &in[0]);
    fi->next = se;
    se->next = th;
    th->next = fo;
    fo->next = NULL;

    int err = cmp(&head_b, &fi);
    ck_assert_int_eq(err, LISTS_EQUAL);
    
    list_free(&fi);
    list_free(&head_b);
}
END_TEST

START_TEST(empty_both)
{
    node_t *first = NULL;

    node_t *head_b = NULL;

    append(&head_b, &first);

    node_t *fi = NULL;

    int err = cmp(&head_b, &fi);
    ck_assert_int_eq(err, LISTS_EQUAL);
}
END_TEST

START_TEST(gen)
{
    int in[] = { 1, 2, 2, 4 };
    int in2[] = { 5, 3, 12, 4 };

    node_t *f = init_node((void *) &in[3]);
    node_t *t = init_node((void *) &in[2]);
    node_t *s = init_node((void *) &in[1]);
    node_t *first = init_node((void *) &in[0]);
    first->next = s;
    s->next = t;
    t->next = f;
    f->next = NULL;
    
    node_t *f_b = init_node((void *) &in2[3]);
    node_t *t_b = init_node((void *) &in2[2]);
    node_t *s_b = init_node((void *) &in2[1]);
    node_t *first_b = init_node((void *) &in2[0]);
    first_b->next = s_b;
    s_b->next = t_b;
    t_b->next = f_b;
    f_b->next = NULL;

    append(&first, &first_b);

    node_t *eight = init_node((void *) &in2[3]);
    node_t *seven = init_node((void *) &in2[2]);
    node_t *six = init_node((void *) &in2[1]);
    node_t *five = init_node((void *) &in2[0]);
    node_t *four = init_node((void *) &in[3]);
    node_t *three = init_node((void *) &in[2]);
    node_t *two = init_node((void *) &in[1]);
    node_t *one = init_node((void *) &in[0]);
    one->next =two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = NULL;

    for (size_t i = 0; i < 8; ++i)
    {
        ck_assert_int_eq(*(int *) first->data, *(int *) one->data);
    }
    
    list_free(&first);
    list_free(&first_b);
    list_free(&one);
}
END_TEST


Suite* append_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Append");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, add_to_one);
    tcase_add_test(tc_pos, add_one);
    tcase_add_test(tc_pos, gen);
    tcase_add_test(tc_pos, empty_a);
    tcase_add_test(tc_pos, empty_b);
    tcase_add_test(tc_pos, empty_both);

    suite_add_tcase(s, tc_pos);

    return s;
}

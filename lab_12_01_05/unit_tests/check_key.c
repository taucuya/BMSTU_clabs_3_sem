#include <check.h>
#include "../inc/filter.h"
#include "../inc/err.h"


START_TEST(one)
{
    int in[] = {234};
    int *pb_dst, *pe_dst;
    int jump = sizeof(in) / sizeof(in[0]);
    pb_dst = (int *) calloc(jump, sizeof(int));

    int err = key(in, in + jump, &pb_dst, &pe_dst);
    ck_assert_int_eq(err, ERR_EMPTY_FILTER);
    free(pb_dst);
}
END_TEST

START_TEST(no_match)
{
    int in[] = {12, 45, 123, 400, 1000};
    int *pb_dst, *pe_dst;
    int size = sizeof(in) / sizeof(in[0]) - 1;
    pb_dst = (int *) calloc(size, sizeof(int));

    int err = key(in, in + size, &pb_dst, &pe_dst);
    ck_assert_int_eq(err, ERR_EMPTY_FILTER);
    free(pb_dst);
}
END_TEST


START_TEST(first)
{
    int in[] = {4356, 12, 34, 56};
    int out[] = {4356};
    int *pb_dst, *pe_dst;
    int size = sizeof(in) / sizeof(in[0]) - 1;
    int nout = sizeof(out) / sizeof(out[0]);
    pb_dst = (int *) calloc(nout, sizeof(int));

    key(in, in + size, &pb_dst, &pe_dst);
    ck_assert_mem_eq(pb_dst, out, nout * sizeof(int));
    free(pb_dst);
}
END_TEST

START_TEST(prelast)
{
    int in[] = {2, 16, 1000, 34};
    int out[] = {1000};
    int *pb_dst, *pe_dst;
    int size = sizeof(in) / sizeof(in[0]);
    int nout = sizeof(out) / sizeof(out[0]);
    pb_dst = (int *) calloc(nout, sizeof(int));

    key(in, in + size, &pb_dst, &pe_dst);
    ck_assert_mem_eq(pb_dst, out, nout * sizeof(int));
    free(pb_dst);
}
END_TEST

START_TEST(not_last)
{
    int in[] = {13000, 56, 24, 13};
    int out[] = {13000, 56, 24};
    int *pb_dst, *pe_dst;
    int size = sizeof(in) / sizeof(in[0]);
    int nout = sizeof(out) / sizeof(out[0]);
    pb_dst = (int *) calloc(nout, sizeof(int));

    key(in, in + size, &pb_dst, &pe_dst);
    ck_assert_mem_eq(pb_dst, out, nout * sizeof(int));
    free(pb_dst);

}
END_TEST

START_TEST(gen)
{
    int in[] = {14000, 12, 3430, 123, 1000, 700, 2};
    int out[] = {14000, 3430, 1000, 700};
    int *pb_dst, *pe_dst;
    int size = sizeof(in) / sizeof(in[0]);
    int nout = sizeof(out) / sizeof(out[0]);
    pb_dst = (int *) calloc(nout, sizeof(int));

    key(in, in + size, &pb_dst, &pe_dst);
    ck_assert_mem_eq(pb_dst, out, nout * sizeof(int));
    free(pb_dst);
}
END_TEST

Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, one);
    tcase_add_test(tc_neg, no_match);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, first);
    tcase_add_test(tc_pos, prelast);
    tcase_add_test(tc_pos, not_last);
    tcase_add_test(tc_pos, gen);

    suite_add_tcase(s, tc_pos);
    return s;
}

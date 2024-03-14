#include <check.h>
#include "../inc/check_make_list.h"
#include "../inc/check_make_num.h"
#include "../inc/check_multiply.h"
#include "../inc/check_division.h"

#define OK 0
#define FAIL 1
#define EPS 1.0e-5

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = make_list_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = make_num_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = multiply_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = division_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    
    return (no_failed == 0) ? OK : FAIL;    
} 
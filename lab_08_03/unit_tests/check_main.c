#include <check.h>
#include "../inc/check_add.h"
#include "../inc/check_to_square.h"
#include "../inc/check_mult.h"

#define OK 0
#define FAIL 1

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = add_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = make_square_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = multiply_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? OK : FAIL;    
} 
#include <check.h>
#include "check_sort.h"
#include "check_key.h"

#define OK 0
#define FAIL 1
#define EPS 1.0e-5

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = mysort_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = key_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? OK : FAIL;    
} 
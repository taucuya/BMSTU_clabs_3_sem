#include "check_sort.h"

#define OK 0
#define FAIL 1
#define EPS 1.0e-5

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = sort_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? OK : FAIL;    
} 
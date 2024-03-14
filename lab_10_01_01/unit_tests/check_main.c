#include <stdlib.h>
#include <check.h>
#include "../inc/check_sorting.h"
#include "../inc/check_append.h"

/**
 * File "check_sorting.c" contain Unit-tests for several functions:
 *  - sort()
 *  - sort_inserted()
 *  - pop_front()
 * Because this functions relate on each other.
 * 
 * File "check_find.c" contain tests for find() only
 * File "check_remove_duplicates.c" contatin tests for remove_duplicates() only
*/

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    /* sort() */
    s = sort_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    /* sort_inserted() */
    s = sort_inserted_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    /* pop_front() */
    s = pop_front_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    /* pop_back() */
    s = pop_back_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    /* append() */
    s = append_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
     
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

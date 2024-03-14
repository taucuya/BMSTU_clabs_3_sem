#ifndef _CHECK_SORTING_H_
#define _CHECK_SORTING_H_

#include <check.h>

#include "err.h"
#include "gen.h"
#include "funcs.h"

Suite* sort_suite(void);
Suite* sort_inserted_suite(void);
Suite* pop_front_suite(void);
Suite* pop_back_suite(void);

#endif

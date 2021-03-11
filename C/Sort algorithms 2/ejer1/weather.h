#ifndef WEATHER_H
#define WEATHER_H

#include <stdio.h>

#include "array_helpers.h"

typedef unsigned int uint;



int temp_min_historical(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS]);

void temp_max_every_year(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int output[YEARS]);

void press_monthly_every_month(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int output[YEARS]);


#endif
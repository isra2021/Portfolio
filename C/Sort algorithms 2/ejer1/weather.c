#include "weather.h"

int temp_min_historical(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS]){
    int min_t = a[0][0][0][temp_m];
    for(uint years = 0; years < YEARS; years++){
        for(t_month months = 0; months < MONTHS; months++){
            for(uint days = 0; days < DAYS; days++){
                if(min_t > a[years][months][days][temp_m]){
                    min_t = a[years][months][days][temp_m];
                }
            }
        }
    }
    return min_t;
}

static void array_dump2(int a[YEARS]){
    for(uint i = 0; i < YEARS; i++){
        printf("%d\n", a[i]);
    }
}

void temp_max_every_year(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int output[YEARS]){
    int temp_max;
    for(uint years = 0; years < YEARS; years++){
        temp_max = a[years][0][0][temp_M];
        for(t_month months = 0; months < MONTHS; months++){
            for(uint days = 0; days < DAYS; days++){
                if(temp_max < a[years][months][days][temp_M]){
                    temp_max = a[years][months][days][temp_M];
                }
            }
        }
        output[years] = temp_max;
    }
    array_dump2(output);
}

void press_monthly_every_month(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int output[YEARS]){
    int month = 0;
    for(uint years = 0; years < YEARS; years++){
        int prec_max_mensual = 0;
        for(t_month months = 0; months < MONTHS; months++){
			int prec_mensual = 0;
            for(uint days = 0; days < DAYS; days++){
				prec_mensual += a[years][months][days][precip];
			}
			if(prec_max_mensual < prec_mensual){
				prec_max_mensual = prec_mensual;
                month = months;
			}
		}
		output[years] = month;
	}
    array_dump2(output);
}

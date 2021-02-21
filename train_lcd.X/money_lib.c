/*
 * File:   money_lib.c
 * Author: eigo
 *
 * Created on 2021/02/21, 17:28
 */


#include <xc.h>
#include "money_lib.h"

uint16_t calc_money(struct Date date){
    //17
    if(date.hour > REGULAR_HOUR){
        uint16_t hour = (uint16_t)date.hour;
        uint16_t min = (uint16_t)date.min;
        return ((hour - REGULAR_HOUR) * HOUR_4_MONEY) +  (MIN_4_MONEY * min) - (MIN_4_MONEY * 20);
    }else{
        return 777777770;
    }
}

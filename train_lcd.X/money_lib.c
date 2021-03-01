/*
 * File:   money_lib.c
 * Author: eigo
 *
 * Created on 2021/02/21, 17:28
 */


#include <xc.h>
#include "money_lib.h"

uint8_t regular_flg = 0;

uint16_t calc_money(struct Date date){
    uint16_t hour = (uint16_t)date.hour;
    uint16_t min = (uint16_t)date.min;
    if(date.hour > REGULAR_HOUR){
        regular_flg = 1;
    }
    else if(date.hour == REGULAR_HOUR && date.min >= 20){
        regular_flg = 1;
    }else{
        regular_flg = 0;
    }
    
    //17
    if(regular_flg){        
        return ((hour - REGULAR_HOUR) * HOUR_4_MONEY) +  (MIN_4_MONEY * min) - (MIN_4_MONEY * 20);
    }else{
        return ((hour - 8) * HOUR_4_MONEY) + (MIN_4_MONEY * min) - (MIN_4_MONEY * 40);
    }
}

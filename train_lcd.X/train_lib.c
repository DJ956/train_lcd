/*
 * File:   train.c
 * Author: eigo
 *
 * Created on January 4, 2021, 5:39 PM
 */


#include <xc.h>
#include "train_lib.h"


void get_next(struct train *next, uint8_t hour, uint8_t min){
    uint8_t idx = 0;
    uint16_t now_min = ((uint16_t)hour * 60) + min;
    
    for(uint8_t i = 0; i < LEN(trains); i++){
        uint16_t t_min = ((uint16_t)trains[i].hour * 60) + trains[i].min;
        
        if(now_min < t_min){
            idx = i;
            break;
        }
    }
    
    next->idx = idx;
    next->hour = trains[idx].hour;
    next->min = trains[idx].min;
}
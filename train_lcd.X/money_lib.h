/* 
 * File:   money_lib.h
 * Author: eigo
 *
 * Created on 2021/02/21, 17:27
 */

#ifndef MONEY_LIB_H
#define	MONEY_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "DS3231.h"
    
const uint16_t REGULAR_HOUR = 17;

const uint16_t MIN_4_MONEY = 27;
const uint16_t HOUR_4_MONEY = 1620;

uint16_t calc_money(struct Date date);


#ifdef	__cplusplus
}
#endif

#endif	/* MONEY_LIB_H */


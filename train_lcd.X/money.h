
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "DS3231.h"

const uint16_t REGULAR_HOUR = 17;

const uint16_t MIN_4_MONEY = 27;
const uint16_t HOUR_4_MONEY = 1620;

uint16_t calc_money(struct Date date);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


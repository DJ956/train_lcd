
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    #define LEN(array) (sizeof(array)/sizeof(array[0]))
    
    struct train{        
        uint8_t hour;
        uint8_t min;
    };
    
    struct train trains[] = {
        {6, 15}, {6,25},  {6,49},
        {7,1},   {7,13},  {7,25},  {7,49},
        {8,1},   {8,13},  {8,25},  {8,37},
        {9, 1},  {9,25},  {9,49},
        {10,13}, {10,37},
        {11,1},  {11,25}, {11,49},
        {12,13}, {12,37},
        {13,1},  {13,25}, {13,49},
        {14,13}, {14,37},
        {15,1},  {15,25}, {15,49},
        {16,13}, {16,37}, {16,49},
        {17,1},  {17,13}, {17,25}, {17,37}, {17,49},
        {18,1},  {18,13}, {18,25}, {18,37}, {18,49},
        {19,1},  {19,13}, {19,25},  {19,37}, {19,49},
        {20,13}, {20,37},
        {21,1},  {21,24}, {21,48},
        {22,18},
    };
    
    void get_next(struct train *next, uint8_t hour, uint8_t min);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


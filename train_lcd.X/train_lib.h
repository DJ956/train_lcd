
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    #define LEN(array) (sizeof(array)/sizeof(array[0]))
    
    struct train{
        uint8_t idx;
        uint8_t hour;
        uint8_t min;
    };
    
    struct train trains[] = {
        {1, 17, 25},
        {2, 17, 37},
        {3, 17, 49},
        {4, 18, 1},
        {5, 18, 37},
        {6, 18, 49},
        {7, 19, 1},
        {8, 19, 25},
        {9, 19, 37},
        {10, 19, 49},
        {11, 20, 13},
        {12, 20, 37},
        {13, 21, 1},
        {14, 21, 24},
        {15, 21, 48},
        {16, 22, 18},
    };
    
    void get_next(struct train *next, uint8_t hour, uint8_t min);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


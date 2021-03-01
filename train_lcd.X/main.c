#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include "lcd_lib.h"
#include "train_lib.h"
#include "DS3231.h"
#include "money_lib.h"

#define TRAIN_MODE 0
#define REMAING_MODE 30
#define MONEY_MODE 45

void print_train(struct train next, struct train next1);
void print_remaing(struct Date date, struct train next);
void print_money(struct Date date, uint16_t money);

uint16_t money;
char line[16];

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    WPUB = 0x24;
    OPTION_REGbits.nWPUEN = 0;
    
    SSP2ADD = 0x13;    
    SSP2CON1 = 0x28;
    SSP2CON2 = 0x0;
    SSP2STAT = 0;
    
    lcd_init();
    lcd_backlight();
    lcd_set_cursor(0, 0);
    
    struct Date date;    
    date.year = 21;
    date.month = 3;
    date.day = 1;
    date.hour = 21;
    date.min = 46;
    date.sec = 0;
    
    money = 0;
    
    //write_date(&date);
        
    struct train next;
    struct train next1;
    while(1)
    {        
        read_date(&date);
        __delay_ms(10);
        get_next(&next, date.hour, date.min);
        get_next(&next1, next.hour, next.min);
                        
        if(date.sec == TRAIN_MODE){
            print_train(next, next1);
            continue;
        }
        
        if(date.sec == REMAING_MODE){
            print_remaing(date, next);
            continue;
        }
        
        if(date.sec == MONEY_MODE){
            money = calc_money(date);
            print_money(date, money);       
            continue;
        }
                
    }
}


void print_train(struct train next, struct train next1){       
    lcd_clear();
    
    sprintf(line, "KW > MT %02d:%02d", next.hour, next.min);
    lcd_set_cursor(0, 0);    
    lcd_print(line);
    
    sprintf(line, "KW > MT %02d:%02d", next1.hour, next1.min);
    lcd_set_cursor(0, 1);    
    lcd_print(line);
}

void print_remaing(struct Date date, struct train next){    
    lcd_clear();
    
    uint16_t now_min = ((uint16_t)date.hour * 60) + date.min;
    uint16_t next_min = ((uint16_t)next.hour * 60) + next.min;
    
    sprintf(line, "KW > MT %02d:%02d", next.hour, next.min);
    lcd_set_cursor(0, 0);    
    lcd_print(line);
    
    sprintf(line, "%d min left", (next_min - now_min));
    lcd_set_cursor(0, 1);    
    lcd_print(line);      
    
    //5min left then led on
    if((next_min - now_min) < 5){
        
    }
}

void print_money(struct Date date, uint16_t money){  
    lcd_clear();
    
    sprintf(line, "Time :%02d:%02d", date.hour, date.min);
    lcd_set_cursor(0, 0);        
    lcd_print(line);
    
    sprintf(line, "Money:%dYEN", money);
    lcd_set_cursor(0, 1);        
    lcd_print(line);       
}
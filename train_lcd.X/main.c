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
void init_char();

uint16_t money;
char line1[16];
char line2[16];

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
    date.month = 2;
    date.day = 21;
    date.hour = 18;
    date.min = 6;
    date.sec = 0;
    
    money = 0;
    
    write_date(&date);
        
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

void init_char(){    
    /*
    for(uint8_t i = 0; i < 16; i++){
        line1[i] = ' ';
        line2[i] = ' ';
    }
     * */
}

void print_train(struct train next, struct train next1){   
    init_char();
    sprintf(line1, "KW > MT %02d:%02d", next.hour, next.min);    
    sprintf(line2, "KW > MT %02d:%02d", next1.hour, next1.min);
            
    lcd_clear();
    
    lcd_set_cursor(0, 0);    
    lcd_print(line1);
    
    lcd_set_cursor(0, 1);    
    lcd_print(line2);
}

void print_remaing(struct Date date, struct train next){    
    init_char();
    uint16_t now_min = ((uint16_t)date.hour * 60) + date.min;
    uint16_t next_min = ((uint16_t)next.hour * 60) + next.min;
    
    sprintf(line1, "KW > MT %02d:%02d", next.hour, next.min);    
    sprintf(line2, "Remaining %d min", (next_min - now_min));
    
    lcd_clear();    
    
    lcd_set_cursor(0, 0);    
    lcd_print(line1);
    
    lcd_set_cursor(0, 1);    
    lcd_print(line2);
}

void print_money(struct Date date, uint16_t money){  
    init_char();
    sprintf(line1, "Time:%02d:%02d", date.hour, date.min);
    sprintf(line2, "Money:%dYEN", money);
        
    lcd_clear();
    
    lcd_set_cursor(0, 0);        
    lcd_print(line1);
    
    lcd_set_cursor(0, 1);        
    lcd_print(line2);
}
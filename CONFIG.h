#ifndef _CONFIG_H
#define _CONFIG_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#define F_CPU (16000000)
#define F_CPU_INSTRUCTION (1)
#define INPUT (0)
#define OUTPUT (1)
#define LOW (0)
#define HIGH (1)

#ifndef TRUE
#define FALSE (0)
#define TRUE (!FALSE)
#endif

#define RTURN_NORMAL (0)
#define RETURN_ERROR (1)

#define INTERRUPT_Timer_0_Overflow TIMER0_OVF_vect
#define INTERRUPT_Timer_1_Overflow TIMER1_OVF_vect
#define INTERRUPT_Timer_2_Overflow TIMER2_OVF_vect

#define INTERRUPT_Timer_0_Comparematch TIMER0_COMP_vect
#define INTERRUPT_Timer_1_Comparematch TIMER1_COMP_vect
#define INTERRUPT_Timer_2_Comparematch TIMER2_COMP_vect

#define INTERRUPT_USART_Rx_Tx (4)
#define INTERRUPT_CAN_c515C (17)

#define ERROR_SCH_TOO_MANY_TASKS (1)
#define ERROR_SCH_CANNOT_DELETE_TASK (2)

#define ERROR_SCH_WAITING_FOR_SLAVE_TO ACK (0xAA)
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER (0xAA)

#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START (0xA0)
#define ERROR_SCH_LOST_SLAVE (0x80)

#define ERROR_I2C_WRITE_BYTE_AT24C64 (11)
#define ERROR_I2C_READ_BYTE_AT24C64 (12)
#define ERROR_I2C_WRITE_BYTE (13)
#define ERROR_I2C_READ_BYTE (14)

#define ERROR_USART_TI (21)
#define ERROR_USART_WRITE_CHAR (22)

#define GIE() sei()
#define GID() cli()

#define SW_DELAY_ms(t) _delay_ms(t)
#define SW_DELAY_us(t) _delay_us(t)

// from AVR035: Efficient C Coding for AVR
#define _BV(n) (1<<n)
#define SET_BIT(reg,bit) (reg |= (1<<bit))
#define CLEAR_BIT(reg,bit) (reg &= ~(1<<bit))
#define TOGGLE_BIT(reg,bit) (reg ^= (1<<bit))
#define ROR(reg,bit) (reg = (reg>>bit | reg<<8-bit))
#define ROL(reg,bit) (reg = (reg<<bit | reg>>8-bit))
#define BIT_IS_SET(reg,bit) (reg & (1<<bit))
#define BIT_IS_CLEAR(reg,bit) (!(reg & (1<<bit)))

typedef char int8;
typedef short int16;
typedef long int32;
typedef long long int64;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef unsigned char tByte;
typedef unsigned short tWord;
typedef unsigned long tLong;

typedef union
{
    struct
    {
        uint8 BIT0:1;
        uint8 BIT1:1;
        uint8 BIT2:1;
        uint8 BIT3:1;
        uint8 BIT4:1;
        uint8 BIT5:1;
        uint8 BIT6:1;
        uint8 BIT7:1;
    }sBITS;
    uint8 BYTE:8;
}uREG;

#endif /* _CONFIG_H */

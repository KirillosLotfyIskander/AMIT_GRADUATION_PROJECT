#ifndef _PORT_H
#define _PORT_H

//#define SCH_REPORT_ERROR
#ifdef SCH_REPORT_ERROR
#define ERROR_port PORTA
#endif

//IR--------------------------------------------
#define IR_DREG (DDRA)
#define IR_OREG (PORTA)
#define IR_IREG (PINA)
#define SENSOR_R (1<<5)
#define SENSOR_L (1<<4)
//IR--------------------------------------------

//US--------------------------------------------
#define US_DREG (DDRA)
#define US_OREG (PORTA)
#define US_IREG (PINA)
#define TRIG_R (1<<1)
#define ECHO_R (1<<0)
#define TRIG_L (1<<3)
#define ECHO_L (1<<2)
//US--------------------------------------------

//MTR-------------------------------------------
#define MTR_DREG1 (DDRD)
#define MTR_OREG1 (PORTD)
#define MTR_IREG1 (PIND)
#define OUT1 (1<<2)
#define OUT2 (1<<3)
#define OUT3 (1<<6)
#define OUT4 (1<<7)

#define MTR_DREG2 (DDRD)
#define MTR_OREG2 (PORTD)
#define MTR_IREG2 (PIND)
#define ENA (1<<4)
#define ENB (1<<5)
//MTR-------------------------------------------

#endif /* _PORT_H */

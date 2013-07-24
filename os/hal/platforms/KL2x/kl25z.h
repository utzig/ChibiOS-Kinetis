#ifndef _KL25Z_H_
#define _KL25Z_H_

typedef struct {

  __IO uint32_t SOPT1;
  __IO uint32_t SOPT1CFG;
       uint32_t RESERVED0[1023];
  __IO uint32_t SOPT2;
  __I  uint32_t RESERVED1[1];
  __IO uint32_t SOPT4;
  __IO uint32_t SOPT5;
       uint32_t RESERVED2[1];
  __IO uint32_t SOPT7;
       uint32_t RESERVED3[2];
  __IO uint32_t SDID;
       uint32_t RESERVED4[3];
  __IO uint32_t SCGC4;
  __IO uint32_t SCGC5;
  __IO uint32_t SCGC6;
  __IO uint32_t SCGC7;
  __IO uint32_t CLKDIV1;
       uint32_t RESERVED5[1];
  __IO uint32_t FCFG1;
  __IO uint32_t FCFG2;
       uint32_t RESERVED6[1];
  __IO uint32_t UIDMH;
  __IO uint32_t UIDML;
  __IO uint32_t UIDL;
       uint32_t RESERVED7[39];
  __IO uint32_t COPC;
  __IO uint32_t SRVCOP;

} SIM_TypeDef;

typedef struct {

  __IO uint32_t PCR0;
  __IO uint32_t PCR1;
  __IO uint32_t PCR2;
  __IO uint32_t PCR3;
  __IO uint32_t PCR4;
  __IO uint32_t PCR5;
  __IO uint32_t PCR6;
  __IO uint32_t PCR7;
  __IO uint32_t PCR8;
  __IO uint32_t PCR9;
  __IO uint32_t PCR10;
  __IO uint32_t PCR11;
  __IO uint32_t PCR12;
  __IO uint32_t PCR13;
  __IO uint32_t PCR14;
  __IO uint32_t PCR15;
  __IO uint32_t PCR16;
  __IO uint32_t PCR17;
  __IO uint32_t PCR18;
  __IO uint32_t PCR19;
  __IO uint32_t PCR20;
  __IO uint32_t PCR21;
  __IO uint32_t PCR22;
  __IO uint32_t PCR23;
  __IO uint32_t PCR24;
  __IO uint32_t PCR25;
  __IO uint32_t PCR26;
  __IO uint32_t PCR27;
  __IO uint32_t PCR28;
  __IO uint32_t PCR29;
  __IO uint32_t PCR30;
  __IO uint32_t PCR31;
  __IO uint32_t GPCLR;
  __IO uint32_t GPCHR;
       uint32_t RESERVED0[6];
  __IO uint32_t ISFR;

} PORT_TypeDef;

typedef struct {

  __IO uint8_t  C1;
  __IO uint8_t  C2;
  __IO uint8_t  C3;
  __IO uint8_t  C4;
  __IO uint8_t  C5;
  __IO uint8_t  C6;
  __IO uint8_t  S;
       uint8_t  RESERVED0[1];
  __IO uint8_t  SC;
       uint8_t  RESERVED1[1];
  __IO uint8_t  ATCVH;
  __IO uint8_t  ATCVL;
  __IO uint8_t  C7;
  __IO uint8_t  C8;
  __IO uint8_t  C9;
  __IO uint8_t  C10;

} MCG_TypeDef;

typedef struct {

  __IO uint32_t CR;

} OSC_TypeDef;

/****************************************************************/
/*                  Peripheral memory map                       */
/****************************************************************/
#define SIM_BASE                0x40047000
#define PORTA_BASE              0x40049000
#define PORTB_BASE              0x4004A000
#define PORTC_BASE              0x4004B000
#define PORTD_BASE              0x4004C000
#define PORTE_BASE              0x4004D000
#define MCG_BASE                0x40064000
#define OSC_BASE                0x40065000

/****************************************************************/
/*                 Peripheral declaration                       */
/****************************************************************/
#define SIM                     ((SIM_TypeDef  *)  SIM_BASE)
#define PORTA                   ((PORT_TypeDef  *) PORTA_BASE)
#define PORTB                   ((PORT_TypeDef  *) PORTB_BASE)
#define PORTC                   ((PORT_TypeDef  *) PORTC_BASE)
#define PORTD                   ((PORT_TypeDef  *) PORTD_BASE)
#define PORTE                   ((PORT_TypeDef  *) PORTE_BASE)
#define MCG                     ((MCG_TypeDef  *)  MCG_BASE)
#define OSC                     ((OSC_TypeDef  *)  OSC_BASE)

#endif

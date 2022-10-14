
/*Guard to protect my file */
#ifndef BIT_MATH_H
#define BIT_MATH_H

/* clear nth bit of port*/ 
#define   CLR(REG,BITNO)	(REG &=(~(1<<BITNO)))
/* set nth bit of port */
#define   SET(REG,BITNO)	(REG |=(1<<BITNO))
/* toggle nth bit of port */
#define   TOG(REG,BITNO)	(REG ^=(1<<BITNO))
/* read the value of nth bit */
#define GET(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


/* set the lower nipple */
#define   SET_LN(VAR)	(VAR |=0X0F)
/* set the high nipple */
#define   SET_HN(VAR)	(VAR |=0XF0)
/* clear the lower nipple */
#define   CLR_LN(VAR)	(VAR &= (~(0X0F)))
/* clear the high nipple */
#define   CLR_HN(VAR)	(VAR &= (~(0XF0)))
/* circular shift  */
#define   CSH(VAR)	(VAR = (VAR<<1)|(VAR>>7))

#endif

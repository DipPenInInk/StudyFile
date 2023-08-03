

/*
 * base_typedef.h
 *
 *  Created on: 2022.06.14
 *      Author: lyd
 *    Describe：Make macro definitions for basic data types
 */

#ifndef BASE_TYPEDEF_H_
#define BASE_TYPEDEF_H_




// basic data type
typedef signed char	     s8;
typedef unsigned char	 u8 ;

typedef short            s16;
typedef unsigned short   u16;

typedef long             s32;
typedef unsigned long    u32;

typedef struct state8bit_code1bit
{
    u8 ce1_0 : 1;
    u8 ce1_1 : 1;
    u8 ce1_2 : 1;
    u8 ce1_3 : 1;
    u8 ce1_4 : 1;
    u8 ce1_5 : 1;
    u8 ce1_6 : 1;
    u8 ce1_7 : 1;
}se8b_ce1b;

typedef union state_word8bit 
{
	se8b_ce1b cwd8;
    u8 uwd8;
    s8 swd8;
}se_wd8b;

typedef struct state16bit_code8bit
{
    se_wd8b ce8_0;
    se_wd8b ce8_1;
}se16b_ce8b;

typedef union state_word16bit 
{
	se16b_ce8b cwd16;
    u16 uwd16;
    s16 swd16;
}se_wd16b;


typedef struct state32bit_code8bit
{
    se_wd8b ce8_0;
    se_wd8b ce8_1;
    se_wd8b ce8_2;
    se_wd8b ce8_3;
}se32b_ce8b;

typedef struct state32bit_code16bit
{
    se_wd16b ce16_0;
    se_wd16b ce16_1;
}se32b_ce16b;


typedef union state_word32b 
{
    se32b_ce8b  sc8wd32;
    se32b_ce16b sc16wd32;
    u32         uwd32;
    s32         swd32;
    float       fwd32;
}se_wd32b;



#endif /* BASE_TYPEDEF_H_ */

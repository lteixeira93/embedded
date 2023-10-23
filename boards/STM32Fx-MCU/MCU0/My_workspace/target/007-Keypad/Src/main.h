#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdint.h>

typedef struct
{
  /* 0 Bits */
  uint32_t GPIOA_EN     : 1;
  uint32_t GPIOB_EN     : 1;
  uint32_t GPIOC_EN     : 1;
  uint32_t GPIOD_EN     : 1;
  uint32_t GPIOE_EN     : 1;
  uint32_t GPIOF_EN     : 1;
  uint32_t GPIOG_EN     : 1;
  uint32_t GPIOH_EN     : 1;
  uint32_t GPIOI_EN     : 1;
  /* 9 Bits */
  uint32_t reserved0    : 3;
  /* 12 Bits */
  uint32_t CRC_EN       : 1;
  /* 13 Bits */
  uint32_t reserved1    : 3;
  uint32_t reserved2    : 2;
  /* 18 Bits */
  uint32_t BKPSRAM_EN   : 1;
  /* 19 Bits */
  uint32_t reserved3    : 1;
  /* 20 Bits */
  uint32_t CCMDATA_EN   : 1;
  /* 21 Bits */
  uint32_t DMA1_EN      : 1;
  uint32_t DMA2_EN      : 1;
  /* 23 Bits */
  uint32_t reserved4    : 2;
  /* 25 Bits */
  uint32_t ETHMAC_EN    : 1;
  uint32_t ETHMACTX_EN  : 1;
  uint32_t ETHMACRX_EN  : 1;
  uint32_t ETHMACPTP_EN : 1;
  /* 29 Bits */
  uint32_t OTGHS_EN     : 1;
  uint32_t OTGHSU_EN    : 1;
  /* 31 Bits */
  uint32_t reserved5    : 1;
  /* 32 Bits - 4 Bytes*/
}RCC_AHB1ENR_t;

typedef struct
{
  /* 0 Bits */
  uint32_t MODER0       : 2;
  uint32_t MODER1       : 2;
  uint32_t MODER2       : 2;
  uint32_t MODER3       : 2;
  uint32_t MODER4       : 2;
  uint32_t MODER5       : 2;
  uint32_t MODER6       : 2;
  uint32_t MODER7       : 2;
  uint32_t MODER8       : 2;
  uint32_t MODER9       : 2;
  uint32_t MODER10      : 2;
  uint32_t MODER11      : 2;
  uint32_t MODER12      : 2;
  uint32_t MODER13      : 2;
  uint32_t MODER15      : 2;
  /* 32 Bits - 4 Bytes*/
}GPIOx_MODE_t;

typedef struct
{
  /* 0 Bits */
  uint32_t IDR0         : 1;
  uint32_t IDR1         : 1;
  uint32_t IDR2         : 1;
  uint32_t IDR3         : 1;
  uint32_t IDR4         : 1;
  uint32_t IDR5         : 1;
  uint32_t IDR6         : 1;
  uint32_t IDR7         : 1;
  uint32_t IDR8         : 1;
  uint32_t IDR9         : 1;
  uint32_t IDR10        : 1;
  uint32_t IDR11        : 1;
  uint32_t IDR12        : 1;
  uint32_t IDR13        : 1;
  uint32_t IDR14        : 1;
  uint32_t IDR15        : 1;
  /* 16 Bits */
  uint32_t reserved0    : 16;
  /* 32 Bits - 4 Bytes*/
}GPIOx_IDR_t;

typedef struct
{
  /* 0 Bits */
  uint32_t ODR0         : 1;
  uint32_t ODR1         : 1;
  uint32_t ODR2         : 1;
  uint32_t ODR3         : 1;
  uint32_t ODR4         : 1;
  uint32_t ODR5         : 1;
  uint32_t ODR6         : 1;
  uint32_t ODR7         : 1;
  uint32_t ODR8         : 1;
  uint32_t ODR9         : 1;
  uint32_t ODR10        : 1;
  uint32_t ODR11        : 1;
  uint32_t ODR12        : 1;
  uint32_t ODR13        : 1;
  uint32_t ODR14        : 1;
  uint32_t ODR15        : 1;
  /* 16 Bits */
  uint32_t reserved0    : 16;
  /* 32 Bits - 4 Bytes*/
}GPIOx_ODR_t;

typedef struct
{
  /* 0 Bits */
  uint32_t PUPDR0       : 2;
  uint32_t PUPDR1       : 2;
  uint32_t PUPDR2       : 2;
  uint32_t PUPDR3       : 2;
  uint32_t PUPDR4       : 2;
  uint32_t PUPDR5       : 2;
  uint32_t PUPDR6       : 2;
  uint32_t PUPDR7       : 2;
  uint32_t PUPDR8       : 2;
  uint32_t PUPDR9       : 2;
  uint32_t PUPDR10      : 2;
  uint32_t PUPDR11      : 2;
  uint32_t PUPDR12      : 2;
  uint32_t PUPDR13      : 2;
  uint32_t PUPDR15      : 2;
  /* 32 Bits - 4 Bytes*/
}GPIOx_PUPDR_t;

#endif // _MAIN_H_

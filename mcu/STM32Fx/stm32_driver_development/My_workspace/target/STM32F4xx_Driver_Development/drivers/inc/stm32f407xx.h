#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include <stddef.h>

/* Volatile Alias */
#define __vo volatile

/* ARM CORTEX Mx Processor NVIC ISERx register adresses */
#define NVIC_ISER0                  ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1                  ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2                  ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3                  ((__vo uint32_t*)0xE000E10C)

/* ARM CORTEX Mx Processor NVIC ICERx register adresses */
#define NVIC_ICER0                  ((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1                  ((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2                  ((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3                  ((__vo uint32_t*)0xE000E18C)

/* ARM CORTEX Mx Processor NVIC Priority register adresses */
#define NVIC_IPR_BASE_ADDR          ((__vo uint32_t*)0xE000E400)

/* ARM CORTEX Mx Processor NVIC Priority register adresses */
#define NUMBER_PR_BITS_IMPLEMENTED  4

/* Generic Macros */
#define ENABLE                      1
#define DISABLE                     0
#define SET                         ENABLE
#define RESET                       DISABLE
#define GPIO_PIN_SET                SET
#define GPIO_PIN_RESET              RESET

/* Memory Adresses */
#define FLASH_BASE_ADDR             0x08000000U     // Flash memory start address (RM-PG-74)
#define SRAM1_BASE_ADDR             0x20000000U     // SRAM1 memory start address
#define SRAM2_BASE_ADDR             0x2001C000U     // SRAM2 memory start address (112KB (FROM SRAM1) * 1024 + 0x20000000 (FROM SRAM1 BASE ADDRESS))
#define ROM_BASE_ADDR               0x1FFF0000U     // ROM system memory start address
#define SRAM                        SRAM1_BASE_ADDR // SRAM

/* Bus Addresses */
#define PERIPH_BASE                 0x40000000U     // Peripherals base address
#define APB1_PERIPH_BASE_ADDR       PERIPH_BASE     // APB1 start address
#define APB2_PERIPH_BASE_ADDR       0x40010000U     // APB2 start address
#define AHB1_PERIPH_BASE_ADDR       0x40020000U     // AHB1 start address
#define AHB2_PERIPH_BASE_ADDR       0x50000000U     // AHB2 start address

/* Peripheral Addresses on AHB1 Bus */
#define GPIOA_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0x0000)     // GPIO-A base address
#define GPIOB_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0x0400)     // GPIO-B base address
#define GPIOC_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0x0800)     // GPIO-C base address
#define GPIOD_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0x0C00)     // GPIO-D base address
#define GPIOE_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0x1000)     // GPIO-E base address
#define GPIOF_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0x1400)     // GPIO-F base address
#define GPIOG_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0x1800)     // GPIO-G base address
#define GPIOH_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0x1C00)     // GPIO-H base address
#define GPIOI_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0x2000)     // GPIO-I base address
#define GPIOJ_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0x2400)     // GPIO-J base address
#define CRC_BASE_ADDR               (AHB1_PERIPH_BASE_ADDR + 0x3000)     // CRC base address
#define RCC_BASE_ADDR               (AHB1_PERIPH_BASE_ADDR + 0x3800)     // RCC base address
#define FLASH_INTF_BASE_ADDR        (AHB1_PERIPH_BASE_ADDR + 0x3C00)     // Flash interface base address
#define BKPSRAM_BASE_ADDR           (AHB1_PERIPH_BASE_ADDR + 0x4000)     // BKPSRAM base address
#define DMA1_BASE_ADDR              (AHB1_PERIPH_BASE_ADDR + 0x6000)     // DMA1 base address
#define DMA2_BASE_ADDR              (AHB1_PERIPH_BASE_ADDR + 0x6400)     // DMA2 base address
#define ETHERNET_MAC_BASE_ADDR      (AHB1_PERIPH_BASE_ADDR + 0x8000)     // ETH_MAC base address
#define DMA2D_BASE_ADDR             (AHB1_PERIPH_BASE_ADDR + 0xB000)     // DMA2D base address
#define USB_OTG_HS_BASE_ADDR        0x40040000U                          // USB_OTG_HS base address

/* Peripheral Addresses on APB1 Bus */
#define I2C1_BASE_ADDR				      (APB1_PERIPH_BASE_ADDR + 0x5400)
#define I2C2_BASE_ADDR				      (APB1_PERIPH_BASE_ADDR + 0x5800)
#define I2C3_BASE_ADDR				      (APB1_PERIPH_BASE_ADDR + 0x5C00)
#define SPI2_BASE_ADDR				      (APB1_PERIPH_BASE_ADDR + 0x3800)
#define SPI3_BASE_ADDR				      (APB1_PERIPH_BASE_ADDR + 0x3C00)
#define USART2_BASE_ADDR				    (APB1_PERIPH_BASE_ADDR + 0x4400)
#define USART3_BASE_ADDR				    (APB1_PERIPH_BASE_ADDR + 0x4800)
#define UART4_BASE_ADDR				      (APB1_PERIPH_BASE_ADDR + 0x4C00)
#define UART5_BASE_ADDR				      (APB1_PERIPH_BASE_ADDR + 0x5000)

/* Peripheral Addresses on AHB2 Bus */
#define USB_OTG_FS_BASE_ADDR        0x50000000U                          // USB_OTG_FS base address
#define DCMI_BASE_ADDR              0x50050000U                          // DCMI base address
#define CRYP_BASE_ADDR              0x50060000U                          // CRYP base address
#define HASH_BASE_ADDR              0x50060400U                          // HASH base address
#define RNG_BASE_ADDR               0x50060800U                          // RNG base address

/* Peripheral Addresses on APB2 Bus */
#define EXTI_BASE_ADDR				      (APB2_PERIPH_BASE_ADDR + 0x3C00)
#define SPI1_BASE_ADDR				      (APB2_PERIPH_BASE_ADDR + 0x3000)
#define SPI4_BASE_ADDR				      (APB2_PERIPH_BASE_ADDR + 0x3400)
#define SYSCFG_BASE_ADDR        		(APB2_PERIPH_BASE_ADDR + 0x3800)
#define USART1_BASE_ADDR				    (APB2_PERIPH_BASE_ADDR + 0x1000)
#define USART6_BASE_ADDR				    (APB2_PERIPH_BASE_ADDR + 0x1400)

/* Peripheral Addresses on AHB3 Bus */
#define FSMC_CRTL_BASE_ADDR         0xA0000000U                          // FSMC control register base address

/* ============================================================= */

/* GPIO Registers */
typedef struct
{
  __vo uint32_t MODER;              // 0x00U  GPIO port mode register                      
  __vo uint32_t OTYPER;             // 0x04U  GPIO port output type register   
  __vo uint32_t OSPEEDR;            // 0x08U  GPIO port output speed register
  __vo uint32_t PUPDR;              // 0x0CU  GPIO port pull-up/pull-down register
  __vo uint32_t IDR;                // 0x10U  GPIO port input data register
  __vo uint32_t ODR;                // 0x14U  GPIO port output data register
  __vo uint32_t BSRR;               // 0x18U  GPIO port bit set/reset register
  __vo uint32_t LCKR;               // 0x1CU  GPIO port configuration lock register 
  __vo uint32_t AFR[2];             // 0x20U (Low) <-> 0x24U (High) GPIO alternate function high-low register
}GPIO_REGS_t;

/* RCC Registers */
typedef struct
{
  __vo uint32_t CR;                 // Address offset: 0x00
  __vo uint32_t PLLCFGR;            // Address offset: 0x04
  __vo uint32_t CFGR;               // Address offset: 0x08
  __vo uint32_t CIR;                // Address offset: 0x0C
  __vo uint32_t AHB1RSTR;           // Address offset: 0x10
  __vo uint32_t AHB2RSTR;           // Address offset: 0x14
  __vo uint32_t AHB3RSTR;           // Address offset: 0x18
  uint32_t      RESERVED0;          // Reserved
  __vo uint32_t APB1RSTR;           // Address offset: 0x20
  __vo uint32_t APB2RSTR;           // Address offset: 0x24
  uint32_t      RESERVED1[2];       // Reserved
  __vo uint32_t AHB1ENR;            // Address offset: 0x30
  __vo uint32_t AHB2ENR;            // Address offset: 0x34
  __vo uint32_t AHB3ENR;            // Address offset: 0x38
  uint32_t      RESERVED2;          // Reserved
  __vo uint32_t APB1ENR;            // Address offset: 0x40
  __vo uint32_t APB2ENR;            // Address offset: 0x44
  uint32_t      RESERVED3[2];       // Reserved
  __vo uint32_t AHB1LPENR;          // Address offset: 0x50
  __vo uint32_t AHB2LPENR;          // Address offset: 0x54
  __vo uint32_t AHB3LPENR;          // Address offset: 0x58
  uint32_t      RESERVED4;          // Reserved
  __vo uint32_t APB1LPENR;          // Address offset: 0x60
  __vo uint32_t APB2LPENR;          // Address offset: 0x64
  uint32_t      RESERVED5[2];       // Reserved
  __vo uint32_t BDCR;               // Address offset: 0x70
  __vo uint32_t CSR;                // Address offset: 0x74
  uint32_t      RESERVED6[2];       // Reserved
  __vo uint32_t SSCGR;              // Address offset: 0x80
  __vo uint32_t PLLI2SCFGR;         // Address offset: 0x84
  __vo uint32_t PLLSAICFGR;         // Address offset: 0x88
  __vo uint32_t DCKCFGR;            // Address offset: 0x8C
  __vo uint32_t CKGATENR;           // Address offset: 0x90
  __vo uint32_t DCKCFGR2;           // Address offset: 0x94
}RCC_REGS_t;

typedef struct
{
  __vo uint32_t IMR;                // Address offset: 0x00
  __vo uint32_t EMR;                // Address offset: 0x04
  __vo uint32_t RTSR;               // Address offset: 0x08
  __vo uint32_t FTSR;               // Address offset: 0x0C
  __vo uint32_t SWIER;              // Address offset: 0x10
  __vo uint32_t PR;                 // Address offset: 0x14
}EXTI_REGS_t;;

/* I2C Registers */
typedef struct
{
  __vo uint32_t CR1;                // 0x00U  I2C Control register 1                     
  __vo uint32_t CR2;                // 0x04U  I2C Control register 2     
  __vo uint32_t OAR1;               // 0x08U  Own address register 1
  __vo uint32_t OAR2;               // 0x0CU  Own address register 2
  __vo uint32_t DR;                 // 0x10U  Data register
  __vo uint32_t SR1;                // 0x14U  Status register 1
  __vo uint32_t SR2;                // 0x18U  Status register 2
  __vo uint32_t CCR;                // 0x1CU  Clock control register
  __vo uint32_t TRISE;              // 0x20U  TRISE register
  __vo uint32_t FLTR;               // 0x24U  FLTR register
}I2C_REGS_t;

/* SPI Registers */
typedef struct
{
  __vo uint32_t CR1;                // 0x00U  SPI Control register 1                     
  __vo uint32_t CR2;                // 0x04U  SPI Control register 2     
  __vo uint32_t SR;                 // 0x08U  Status register 2
  __vo uint32_t DR;                 // 0x0CU  Data register
  __vo uint32_t CRCPR;              // 0x10U  SPI CRC polynomial register
  __vo uint32_t RXCRCR;             // 0x14U  SPI RX CRC register
  __vo uint32_t TXCRCR;             // 0x18U  SPI TX CRC register
  __vo uint32_t I2SCFGR;            // 0x1CU  Config control register
  __vo uint32_t I2SPR;              // 0x20U  Prescaler
}SPI_REGS_t;

/* SYSCFG Registers */
typedef struct
{
  __vo uint32_t MEMRMP;             // Address offset: 0x00
  __vo uint32_t PMC;                // Address offset: 0x04
  __vo uint32_t EXTICR[4];          // Address offset: 0x08-0x14
  uint32_t      RESERVED1[2];       // Reserved, 0x18-0x1C
  __vo uint32_t CMPCR;              // Address offset: 0x20
}SYSCFG_REGS_t;

/* USART Registers */
typedef struct
{
	__vo uint32_t SR;         			  // Address offset: 0x00
	__vo uint32_t DR;         			  // Address offset: 0x04
	__vo uint32_t BRR;        			  // Address offset: 0x08
	__vo uint32_t CR1;        			  // Address offset: 0x0C
	__vo uint32_t CR2;        			  // Address offset: 0x10
	__vo uint32_t CR3;        			  // Address offset: 0x14
	__vo uint32_t GTPR;       			  // Address offset: 0x18
}USART_REGS_t;

/* ============================================================= */

#define GPIOA  				              ((GPIO_REGS_t*)GPIOA_BASE_ADDR)
#define GPIOB  				              ((GPIO_REGS_t*)GPIOB_BASE_ADDR)
#define GPIOC  				              ((GPIO_REGS_t*)GPIOC_BASE_ADDR)
#define GPIOD  				              ((GPIO_REGS_t*)GPIOD_BASE_ADDR)
#define GPIOE  				              ((GPIO_REGS_t*)GPIOE_BASE_ADDR)
#define GPIOF  				              ((GPIO_REGS_t*)GPIOF_BASE_ADDR)
#define GPIOG  				              ((GPIO_REGS_t*)GPIOG_BASE_ADDR)
#define GPIOH  				              ((GPIO_REGS_t*)GPIOH_BASE_ADDR)
#define GPIOI  				              ((GPIO_REGS_t*)GPIOI_BASE_ADDR)
#define GPIOJ  				              ((GPIO_REGS_t*)GPIOJ_BASE_ADDR)

#define RCC 				                ((RCC_REGS_t*)RCC_BASE_ADDR)
#define EXTI				                ((EXTI_REGS_t*)EXTI_BASE_ADDR)
#define SYSCFG				              ((SYSCFG_REGS_t*)SYSCFG_BASE_ADDR)

#define SPI1  				              ((SPI_REGS_t*)SPI1_BASE_ADDR)
#define SPI2  				              ((SPI_REGS_t*)SPI2_BASE_ADDR)
#define SPI3  				              ((SPI_REGS_t*)SPI3_BASE_ADDR)
#define SPI4  				              ((SPI_REGS_t*)SPI4_BASE_ADDR)

#define I2C1  				              ((I2C_REGS_t*)I2C1_BASE_ADDR)
#define I2C2  				              ((I2C_REGS_t*)I2C2_BASE_ADDR)
#define I2C3  				              ((I2C_REGS_t*)I2C3_BASE_ADDR)

#define USART1  			              ((USART_REGS_t*)USART1_BASE_ADDR)
#define USART2  			              ((USART_REGS_t*)USART2_BASE_ADDR)
#define USART3  			              ((USART_REGS_t*)USART3_BASE_ADDR)
#define UART4  				              ((USART_REGS_t*)UART4_BASE_ADDR)
#define UART5  				              ((USART_REGS_t*)UART5_BASE_ADDR)
#define USART6  			              ((USART_REGS_t*)USART6_BASE_ADDR)

/* Interrupt Request Number - NVIC Positions */
#define IRQ_NO_EXTI0	              6
#define IRQ_NO_EXTI1	              7
#define IRQ_NO_EXTI2	              8
#define IRQ_NO_EXTI3	              9
#define IRQ_NO_EXTI4	              10
#define IRQ_NO_EXTI9_5	            23
#define IRQ_NO_EXTI15_10            40

/* Interrupt Priority Number */
#define NVIC_IRQ_PRIORITY_0         0
#define NVIC_IRQ_PRIORITY_1         1
#define NVIC_IRQ_PRIORITY_2         2
#define NVIC_IRQ_PRIORITY_3         3
#define NVIC_IRQ_PRIORITY_4         4
#define NVIC_IRQ_PRIORITY_5         5
#define NVIC_IRQ_PRIORITY_6         6
#define NVIC_IRQ_PRIORITY_7         7
#define NVIC_IRQ_PRIORITY_8         8
#define NVIC_IRQ_PRIORITY_9         9
#define NVIC_IRQ_PRIORITY_10        10
#define NVIC_IRQ_PRIORITY_11        11
#define NVIC_IRQ_PRIORITY_12        12
#define NVIC_IRQ_PRIORITY_13        13
#define NVIC_IRQ_PRIORITY_14        14
#define NVIC_IRQ_PRIORITY_15        15

/* ============================================================= */

/* Clock Enable Macro AHB1 - GPIOA */
#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= (1 << 0))
/* Clock Disable Macro AHB1 - GPIOA */
#define GPIOA_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 0))

/* Clock Enable Macro AHB1 - GPIOB */
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= (1 << 1))
/* Clock Disable Macro AHB1 - GPIOB */
#define GPIOB_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 1))

/* Clock Enable Macro AHB1 - GPIOC */
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= (1 << 2))
/* Clock Disable Macro AHB1 - GPIOC */
#define GPIOC_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 2))

/* Clock Enable Macro AHB1 - GPIOD */
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= (1 << 3))
/* Clock Disable Macro AHB1 - GPIOD */
#define GPIOD_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 3))

/* Clock Enable Macro AHB1 - GPIOE */
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= (1 << 4))
/* Clock Disable Macro AHB1 - GPIOE */
#define GPIOE_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 4))

/* Clock Enable Macro AHB1 - GPIOF */
#define GPIOF_PCLK_EN() (RCC->AHB1ENR |= (1 << 5))
/* Clock Disable Macro AHB1 - GPIOF */
#define GPIOF_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 5))

/* Clock Enable Macro AHB1 - GPIOG */
#define GPIOG_PCLK_EN() (RCC->AHB1ENR |= (1 << 6))
/* Clock Disable Macro AHB1 - GPIOG */
#define GPIOG_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 6))

/* Clock Enable Macro AHB1 - GPIOH */
#define GPIOH_PCLK_EN() (RCC->AHB1ENR |= (1 << 7))
/* Clock Disable Macro AHB1 - GPIOH */
#define GPIOH_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 7))

/* Clock Enable Macro AHB1 - GPIOI */
#define GPIOI_PCLK_EN() (RCC->AHB1ENR |= (1 << 8))
/* Clock Disable Macro AHB1 - GPIOI */
#define GPIOI_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 8))

/* ============================================================= */

/* Clock Enable Macros APB1 - USART1 */
#define USART_PCLK_EN()   (RCC->APB1ENR |= (1 << 4))
/* Clock Disable Macros APB1 - USART1 */
#define USART_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 4)) 

/* ============================================================= */

/* Clock Enable Macros APB2 - SPI1 */
#define SPI1_PCLK_EN()   (RCC->APB2ENR |= (1 << 12)) 
/* Clock Disable Macros APB2 - SPI1 */
#define SPI1_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 12)) 

/* Clock Enable Macros APB2 - SPI4 */
#define SPI4_PCLK_EN()   (RCC->APB2ENR |= (1 << 13)) 
/* Clock Disable Macros APB1 - SPI4 */
#define SPI4_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 13)) 

/* Clock Enable Macros APB1 - SPI2 */
#define SPI2_PCLK_EN()   (RCC->APB1ENR |= (1 << 14)) 
/* Clock Disable Macros APB1 - SPI2 */
#define SPI2_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 14)) 

/* Clock Enable Macros APB1 - SPI3 */
#define SPI3_PCLK_EN()   (RCC->APB1ENR |= (1 << 15)) 
/* Clock Disable Macros APB1 - SPI3 */
#define SPI3_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 15)) 


/* ============================================================= */

/* Clock Enable Macros APB2 - SYSCFG */
#define SYSCFG_PCLK_EN()   (RCC->APB2ENR |= (1 << 14)) 

/* ============================================================= */

/* Clock Enable Macros APB1 - I2C1 */
#define I2C_PCLK_EN()   (RCC->APB1ENR |= (1 << 21)) 
/* Clock Disable Macros APB1 - I2C1 */
#define I2C_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 21)) 

/* ============================================================= */

/* Reset GPIO Peripheral Macros AHB1 - GPIOA - DO-WHILE - MORE THAN 1 STATEMENTS IN ONE MACRO */
#define GPIOA_REG_RESET() do {(RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));} while(0)

/* Reset GPIO Peripheral Macros AHB1 - GPIOB */
#define GPIOB_REG_RESET() do {(RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));} while(0)

/* Reset GPIO Peripheral Macros AHB1 - GPIOC */
#define GPIOC_REG_RESET() do {(RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));} while(0)

/* Reset GPIO Peripheral Macros AHB1 - GPIOD */
#define GPIOD_REG_RESET() do {(RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));} while(0)

/* Reset GPIO Peripheral Macros AHB1 - GPIOE */
#define GPIOE_REG_RESET() do {(RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));} while(0)

/* Reset GPIO Peripheral Macros AHB1 - GPIOF */
#define GPIOF_REG_RESET() do {(RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5));} while(0)

/* Reset GPIO Peripheral Macros AHB1 - GPIOG */
#define GPIOG_REG_RESET() do {(RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6));} while(0)

/* Reset GPIO Peripheral Macros AHB1 - GPIOH */
#define GPIOH_REG_RESET() do {(RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));} while(0)

/* Reset GPIO Peripheral Macros AHB1 - GPIOI */
#define GPIOI_REG_RESET() do {(RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8));} while(0)

/* Reset GPIO Peripheral Macros AHB1 - GPIOI */
#define GPIOB_BASE_ADDR_TO_CODE(pHANDLEpGPIOx)  ((pHANDLEpGPIOx == GPIOA) ? 0 :\
                                                 (pHANDLEpGPIOx == GPIOB) ? 1 :\
                                                 (pHANDLEpGPIOx == GPIOC) ? 2 :\
                                                 (pHANDLEpGPIOx == GPIOD) ? 3 :\
                                                 (pHANDLEpGPIOx == GPIOE) ? 4 :\
                                                 (pHANDLEpGPIOx == GPIOF) ? 5 :\
                                                 (pHANDLEpGPIOx == GPIOG) ? 6 :\
                                                 (pHANDLEpGPIOx == GPIOH) ? 7 :0)

/* ============================================================= */

#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx_spi_driver.h"

#endif /* INC_STM32F407XX_H_ */

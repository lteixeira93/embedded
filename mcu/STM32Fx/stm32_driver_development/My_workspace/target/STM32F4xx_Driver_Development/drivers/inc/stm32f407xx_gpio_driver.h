#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/* 
@GPIO_PIN_NUMBER
GPIO Pin possible Modes 
*/
#define GPIO_PIN_NUM_0      0
#define GPIO_PIN_NUM_1      1
#define GPIO_PIN_NUM_2      2
#define GPIO_PIN_NUM_3      3
#define GPIO_PIN_NUM_4      4
#define GPIO_PIN_NUM_5      5
#define GPIO_PIN_NUM_6      6
#define GPIO_PIN_NUM_7      7
#define GPIO_PIN_NUM_8      8
#define GPIO_PIN_NUM_9      9
#define GPIO_PIN_NUM_10     10
#define GPIO_PIN_NUM_11     11
#define GPIO_PIN_NUM_12     12
#define GPIO_PIN_NUM_13     13
#define GPIO_PIN_NUM_14     14
#define GPIO_PIN_NUM_15     15

/* 
@GPIO_PIN_MODES
GPIO Pin possible Modes 
*/
#define GPIO_MODE_IN        0
#define GPIO_MODE_OUT       1
#define GPIO_MODE_ALTFN     2
#define GPIO_MODE_ANALOG    3

// Interrupt Modes TO-DO: Set EXTI Register
#define GPIO_MODE_IT_FT     4           // Input Falling Edge Interrupt
#define GPIO_MODE_IT_RT     5           // Input Rising Edge Interrupt
#define GPIO_MODE_IT_RFT    6           // Input Rising Falling Edge Interrupt

/* 
@GPIO_PIN_SPEED
GPIO Pin possible output speeds 
*/
#define GPIO_SPEED_LOW      0
#define GPIO_SPEED_MEDIUM   1
#define GPIO_SPEED_FAST     2
#define GPIO_SPEED_HIGH     3

/* 
@GPIO_PIN_PULL_UP_DOWN
GPIO Pin possible Pull Up/Down 
*/
#define GPIO_NO_PUPD        0
#define GPIO_PIN_PU         1
#define GPIO_PIN_PD         2

/* 
@GPIO_PIN_TYPES
GPIO Pin possible output types 
*/
#define GPIO_OP_TYPE_PP     0           // Push Pull
#define GPIO_OP_TYPE_OD     1           // Open Drain

typedef struct
{
    uint8_t GPIO_PinNumber;             // Possible values from @GPIO_PIN_NUMBER
    uint8_t GPIO_PinMode;               // Possible values from @GPIO_PIN_MODES
    uint8_t GPIO_PinSpeed;              // Possible values from @GPIO_PIN_SPEED
    uint8_t GPIO_PinPuPdCtrl;           // Possible values from @GPIO_PIN_PULL_UP_DOWN
    uint8_t GPIO_PinOPType;             // Possible values from @GPIO_PIN_TYPES
    uint8_t GPIO_PinAltFunMode;         
}GPIO_PinConfig_t;

typedef struct
{
    GPIO_REGS_t *pGPIOx;                // Pointer to hold the base address of GPIO peripheral in format (GPIO_REGS_t*)
    GPIO_PinConfig_t GPIO_PinConfig;    // Holds GPIO pin configuration settings
}GPIO_Handle_t;

/* APIs */
/* ============================================================= */
/* Clock Configuration */
void GPIO_PeripheralClockControl(GPIO_REGS_t *pGPIOx, uint8_t EnorDi);

/* GPIO Configuration */
void GPIO_Init_Modes(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_REGS_t *pGPIOx);

/* Read/Write Configuration */
uint8_t GPIO_ReadFromInputPin(GPIO_REGS_t *pGPIOx, uint8_t pinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_REGS_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_REGS_t *pGPIOx, uint8_t pinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_REGS_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_REGS_t *pGPIOx, uint8_t pinNumber);

/* Interrupt (IRQ/ISR) Configuration */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);

void GPIO_IRQHandling(uint8_t pinNumber);

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
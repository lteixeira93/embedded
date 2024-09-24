#include <string.h>
#include "stm32f407xx.h"

#define LOW          0
#define HIGH         1
#define BTN_PRESSED  LOW

void delay (void) {
    for (uint32_t i = 0; i < 500000; i++);
}

int main(void) {
    // # Test 1: LED toggling with PUSH PULL configuration
    /* GPIO_Handle_t gpioLED;

    gpioLED.pGPIOx = GPIOD;
    gpioLED.GPIO_PinConfig.GPIO_PinNumber    = GPIO_PIN_NUM_6;
    gpioLED.GPIO_PinConfig.GPIO_PinMode      = GPIO_MODE_OUT;
    gpioLED.GPIO_PinConfig.GPIO_PinSpeed     = GPIO_SPEED_FAST;
    gpioLED.GPIO_PinConfig.GPIO_PinOPType    = GPIO_OP_TYPE_PP;
    gpioLED.GPIO_PinConfig.GPIO_PinPuPdCtrl  = GPIO_NO_PUPD;    // Output already uses PUSH PULL

    GPIO_PeripheralClockControl(GPIOD, ENABLE);
    GPIO_Init_Modes(&gpioLED);

    while (1) {
        GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NUM_6);
        delay();
    } */

    // # Test 2: LED toggling with OPEN DRAIN configuration
    // GPIO_Handle_t gpioLED;

    // gpioLED.pGPIOx = GPIOD;
    // gpioLED.GPIO_PinConfig.GPIO_PinNumber    = GPIO_PIN_NUM_6;
    // gpioLED.GPIO_PinConfig.GPIO_PinMode      = GPIO_MODE_OUT;
    // gpioLED.GPIO_PinConfig.GPIO_PinSpeed     = GPIO_SPEED_FAST;
    // gpioLED.GPIO_PinConfig.GPIO_PinOPType    = GPIO_OP_TYPE_OD;

    // /* LED Will blink with low intensity because the high value of pull up resistor (40kohm) */
    // // gpioLED.GPIO_PinConfig.GPIO_PinPuPdCtrl  = GPIO_PIN_PU;
    // gpioLED.GPIO_PinConfig.GPIO_PinPuPdCtrl  = GPIO_NO_PUPD;

    // GPIO_PeripheralClockControl(GPIOD, ENABLE);
    // GPIO_Init_Modes(&gpioLED);

    // while (1) {
    //     GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NUM_6);
    //     delay();
    // }

    /* # Test 3: Handling on board LED and Button */
    // GPIO_Handle_t gpioLED, gpioButton;

    // GPIO_PeripheralClockControl(GPIOA, ENABLE);
    // GPIO_PeripheralClockControl(GPIOE, ENABLE);

    // gpioLED.pGPIOx    = GPIOA;
    // gpioButton.pGPIOx = GPIOE;

    // /* Onboard LED Config - PA6 */
    // gpioLED.GPIO_PinConfig.GPIO_PinNumber   = GPIO_PIN_NUM_6;
    // gpioLED.GPIO_PinConfig.GPIO_PinMode     = GPIO_MODE_OUT;
    // gpioLED.GPIO_PinConfig.GPIO_PinSpeed    = GPIO_SPEED_FAST;
    // gpioLED.GPIO_PinConfig.GPIO_PinOPType   = GPIO_OP_TYPE_PP;
    // gpioLED.GPIO_PinConfig.GPIO_PinPuPdCtrl = GPIO_NO_PUPD;    // Output already uses PUSH PULL    
    // GPIO_Init_Modes(&gpioLED);

    // /* Onboard LED Config - PA7 */
    // gpioLED.GPIO_PinConfig.GPIO_PinNumber   = GPIO_PIN_NUM_7;
    // gpioLED.GPIO_PinConfig.GPIO_PinMode     = GPIO_MODE_OUT;
    // gpioLED.GPIO_PinConfig.GPIO_PinSpeed    = GPIO_SPEED_FAST;
    // gpioLED.GPIO_PinConfig.GPIO_PinOPType   = GPIO_OP_TYPE_PP;
    // gpioLED.GPIO_PinConfig.GPIO_PinPuPdCtrl = GPIO_NO_PUPD;    // Output already uses PUSH PULL    
    // GPIO_Init_Modes(&gpioLED);

    // /* Onboard Button Config - PE3 */
    // gpioButton.GPIO_PinConfig.GPIO_PinNumber   = GPIO_PIN_NUM_3;
    // gpioButton.GPIO_PinConfig.GPIO_PinMode     = GPIO_MODE_IN;
    // gpioButton.GPIO_PinConfig.GPIO_PinSpeed    = GPIO_SPEED_FAST;
    // gpioButton.GPIO_PinConfig.GPIO_PinPuPdCtrl = GPIO_PIN_PU;
    // GPIO_Init_Modes(&gpioButton);

    // while (1) {
    //     if(GPIO_ReadFromInputPin(GPIOE, GPIO_PIN_NUM_3) == 0) {
    //         delay();
    //         GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NUM_6);          
    //     }
    //     GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NUM_7);    
    //     delay();      
    // }

    /* # Test 4: Handling IRQ Button (PE3) */
    GPIO_Handle_t gpioLED, gpioButton;
    
    memset(&gpioLED, 0, sizeof(gpioLED));
    memset(&gpioButton, 0, sizeof(gpioButton));

    /* Onboard LED Config - PE1 */
    gpioLED.pGPIOx    = GPIOE; // PE1
    gpioLED.GPIO_PinConfig.GPIO_PinNumber      = GPIO_PIN_NUM_1;
    gpioLED.GPIO_PinConfig.GPIO_PinMode        = GPIO_MODE_OUT;
    gpioLED.GPIO_PinConfig.GPIO_PinSpeed       = GPIO_SPEED_FAST;
    gpioLED.GPIO_PinConfig.GPIO_PinOPType      = GPIO_OP_TYPE_PP;
    gpioLED.GPIO_PinConfig.GPIO_PinPuPdCtrl    = GPIO_NO_PUPD;    // Output already uses PUSH PULL    

    /* Onboard Button Config - PE3 */
    gpioButton.pGPIOx = GPIOE; // PE3
    gpioButton.GPIO_PinConfig.GPIO_PinNumber   = GPIO_PIN_NUM_3;
    gpioButton.GPIO_PinConfig.GPIO_PinMode     = GPIO_MODE_IT_FT;
    gpioButton.GPIO_PinConfig.GPIO_PinSpeed    = GPIO_SPEED_FAST;
    gpioButton.GPIO_PinConfig.GPIO_PinPuPdCtrl = GPIO_PIN_PU;

    /* Init clock on peripherals */
    GPIO_PeripheralClockControl(GPIOE, ENABLE);

    /* Init peripherals */
    GPIO_Init_Modes(&gpioButton);
    GPIO_Init_Modes(&gpioLED);

    /* IRQ Configuring */
    GPIO_IRQPriorityConfig(IRQ_NO_EXTI3, NVIC_IRQ_PRIORITY_15);
    GPIO_IRQConfig(IRQ_NO_EXTI3, ENABLE);

    while(1);
    
    return 0;
}

/* Overriding weak attribute in EXTI0_IRQHandler */
/* 
The address of EXTI0_IRQHandler will be store at vector address of the corresponding IRQ Number
This is done automatically by startup code.
*/
void EXTI3_IRQHandler(void) {
    delay();
    GPIO_IRQHandling(GPIO_PIN_NUM_3); // Clearing pending register from EXTI line
    GPIO_ToggleOutputPin(GPIOE, GPIO_PIN_NUM_1);
}

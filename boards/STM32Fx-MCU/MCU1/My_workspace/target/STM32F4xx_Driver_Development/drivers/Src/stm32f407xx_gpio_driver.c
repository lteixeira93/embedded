#include "stm32f407xx_gpio_driver.h"

/* APIs */
/* ============================================================= */
/*********************************************************************
 * @fn      		  - GPIO_PeripheralClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 *
 * @return            - none
 *
 * @Note              - none

 */
void GPIO_PeripheralClockControl(GPIO_REGS_t *pGPIOx, uint8_t EnorDi) {
    if (EnorDi == ENABLE) {
        if (pGPIOx == GPIOA) {
            GPIOA_PCLK_EN();
        }else if (pGPIOx == GPIOB) {
            GPIOB_PCLK_EN();
        }else if (pGPIOx == GPIOC) {
            GPIOC_PCLK_EN();
        }else if (pGPIOx == GPIOD) {
            GPIOD_PCLK_EN();
        }else if (pGPIOx == GPIOE) {
            GPIOE_PCLK_EN();
        }else if (pGPIOx == GPIOF) {
            GPIOF_PCLK_EN();
        }else if (pGPIOx == GPIOG) {
            GPIOG_PCLK_EN();
        }else if (pGPIOx == GPIOH) {
            GPIOH_PCLK_EN();
        }else if (pGPIOx == GPIOI) {
            GPIOI_PCLK_EN();
        }        
    }else {
        if (pGPIOx == GPIOA) {
            GPIOA_PCLK_DI();
        }else if (pGPIOx == GPIOB) {
            GPIOB_PCLK_DI();
        }else if (pGPIOx == GPIOC) {
            GPIOC_PCLK_DI();
        }else if (pGPIOx == GPIOD) {
            GPIOD_PCLK_DI();
        }else if (pGPIOx == GPIOE) {
            GPIOE_PCLK_DI();
        }else if (pGPIOx == GPIOF) {
            GPIOF_PCLK_DI();
        }else if (pGPIOx == GPIOG) {
            GPIOG_PCLK_DI();
        }else if (pGPIOx == GPIOH) {
            GPIOH_PCLK_DI();
        }else if (pGPIOx == GPIOI) {
            GPIOI_PCLK_DI();
        }     
    }    
}

/*********************************************************************
 * @fn      		  - GPIO_Init_Modes
 *
 * @brief             - This function initializes GPIOs
 *
 * @param[in]         - 
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_Init_Modes(GPIO_Handle_t *pGPIOHandle) {
    uint32_t temp = 0;
   
    if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG) {
        /* Configuring Mode */
        temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));    
        pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        pGPIOHandle->pGPIOx->MODER |= temp;
    }else {
        /* Interrupt Mode */
        if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT) {
            /* Configuring Falling trigger selection register FTSR */
            EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            /* Clearing RTSR bit */
            EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }
        else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT) {
            /* Configure Rising trigger selection register RTSR */
            EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            /* Clearing FTSR bit */
            EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }
        else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT) {
            /* Configuring Falling/Rising trigger selection registers */
            EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }

        // Configuring the GPIO port selection in SYSCFG_EXTICR
        uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
        uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;

        // Configuring GPIO port selection in SYSCFG_EXTICR
        SYSCFG_PCLK_EN();

        uint8_t portcode = GPIOB_BASE_ADDR_TO_CODE(pGPIOHandle->pGPIOx);

        SYSCFG->EXTICR[temp1] |= portcode << (temp2 *4);

        // Enabling EXTI Interrupt delivery using IMR
        EXTI->IMR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        
    }
    
    /* Configuring Speed */
    temp = 0;
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;

    /* Configuring Pull Resistor */
    temp = 0;
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdCtrl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->PUPDR |= temp;
    
    /* Configuring output type */
    temp = 0;
    temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER |= temp;

    /* Configuring alternate function mode */
    if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN) {
        uint8_t temp0 = 0, temp1 = 0;
        temp0 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8; // Getting array location for alternate function
        temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8; // Getting bit position for alternate function
        pGPIOHandle->pGPIOx->AFR[temp0] &= ~(0xF << (4 * temp1));
        pGPIOHandle->pGPIOx->AFR[temp0] |= pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp1);
    }

}

/*********************************************************************
 * @fn      		  - GPIO_DeInit
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_DeInit(GPIO_REGS_t *pGPIOx) {
    if (pGPIOx == GPIOA) {
        GPIOA_REG_RESET();
    }else if (pGPIOx == GPIOB) {
        GPIOB_REG_RESET();
    }else if (pGPIOx == GPIOC) {
        GPIOC_REG_RESET();
    }else if (pGPIOx == GPIOD) {
        GPIOD_REG_RESET();
    }else if (pGPIOx == GPIOE) {
        GPIOE_REG_RESET();
    }else if (pGPIOx == GPIOF) {
        GPIOF_REG_RESET();
    }else if (pGPIOx == GPIOG) {
        GPIOG_REG_RESET();
    }else if (pGPIOx == GPIOH) {
        GPIOH_REG_RESET();
    }else if (pGPIOx == GPIOI) {
        GPIOI_REG_RESET();
    }
}

/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -   0 or 1
 *
 * @Note              -

 */
uint8_t GPIO_ReadFromInputPin(GPIO_REGS_t *pGPIOx, uint8_t pinNumber) {
    uint8_t value;
    value = (uint8_t)((pGPIOx->IDR >> pinNumber) & 0x000000001);
    
    return value;
}

/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
uint16_t GPIO_ReadFromInputPort(GPIO_REGS_t *pGPIOx) {
    uint16_t value;
    value = pGPIOx->IDR;
    
    return value;
}

/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutputPin(GPIO_REGS_t *pGPIOx, uint8_t pinNumber, uint8_t value) {
    if (value == GPIO_PIN_SET) {
        /* code */
        pGPIOx->ODR |= (1 << pinNumber); 
    }else {
        pGPIOx->ODR &= ~(1 << pinNumber); 
    }    
}

/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutputPort(GPIO_REGS_t *pGPIOx, uint16_t value) {
        pGPIOx->ODR |= value; 
}

/*********************************************************************
 * @fn      		  - GPIO_ToggleOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_ToggleOutputPin(GPIO_REGS_t *pGPIOx, uint8_t pinNumber) {
    pGPIOx->ODR ^= (1 << pinNumber);
}

/*********************************************************************
 * @fn      		  - GPIO_IRQConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t EnorDi) {
    if (EnorDi == ENABLE)
    {
        if (IRQNumber <= 31) {
            // ISER0 [0:31]
            *NVIC_ISER0 |= (1 << IRQNumber);
        } 
        else if (IRQNumber > 31 && IRQNumber < 64) {
            // ISER1 [32:63]
            *NVIC_ISER1 |= (1 << (IRQNumber % 32));
        }
        else if (IRQNumber >= 64 && IRQNumber < 96) {
            // ISER2 [64:95]
            *NVIC_ISER2 |= (1 << (IRQNumber % 64));
            
        }  
    }
    else {
        if (IRQNumber <= 31) {
            // ICER0
            *NVIC_ICER0 |= (1 << IRQNumber);
        } 
        else if (IRQNumber > 31 && IRQNumber < 64) {
            // ICER1
            *NVIC_ICER1 |= (1 << (IRQNumber % 32));            
        }
        else if (IRQNumber >= 64 && IRQNumber < 96) {
            // ICER2
            *NVIC_ICER2 |= (1 << (IRQNumber % 64));            
        }  
    }
    
}

/*********************************************************************
 * @fn      		  - GPIO_IRQPriorityConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority) {
    // FInd IPR register
    uint8_t iprx = IRQNumber / 4;
    uint8_t iprx_section = IRQNumber % 4;

    uint8_t shift_ammount = (8 * iprx_section) + (8 - NUMBER_PR_BITS_IMPLEMENTED);
    *(NVIC_IPR_BASE_ADDR + iprx) |= (IRQPriority << shift_ammount);
}

/*********************************************************************
 * @fn      		  - GPIO_IRQHandling
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQHandling(uint8_t pinNumber) {
    // Clear Pending Register corresponding to pin number
    if (EXTI->PR & (1 << pinNumber)) {
        // Clear
        EXTI->PR |= (1 << pinNumber);
    }
}
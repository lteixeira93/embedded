#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_

#include "stm32f407xx.h"

typedef struct
{
    uint8_t SPI_DeviceMode;
    uint8_t SPI_BUsConfig;
    uint8_t SPI_SCLKSpeed;
    uint8_t SPI_DFF;
    uint8_t SPI_CPOL;     
    uint8_t SPI_CPHA;
    uint8_t SPI_SSM;
}SPI_Config_t;

typedef struct
{
    SPI_REGS_t *pSPIx;                  // Pointer to hold the base address of SPI peripheral in format (SPI_REGS_t*)
    SPI_Config_t SPI_PinConfig;         // Holds SPI pin configuration settings
}SPI_Handle_t;

/* APIs */
/* ============================================================= */
/* Clock Configuration */
void SPI_PeripheralClockControl(SPI_REGS_t *pSPIx, uint8_t EnorDi);

/* SPI Configuration */
void SPI_Init_Modes(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_REGS_t *pSPIx);

/* Data Send and Receive */
void SPI_SendData(SPI_REGS_t *pSPIx, uint8_t *pTXBuffer, uint32_t lenght);
void SPI_ReceiveData(SPI_REGS_t *pSPIx, uint8_t *pRXBuffer, uint32_t lenght);

/* Interrupt (IRQ/ISR) Configuration */
void SPI_IRQConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pSPIHandle);

#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
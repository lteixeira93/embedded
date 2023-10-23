#include "stm32f407xx_spi_driver.h"

/* APIs */
/* ============================================================= */
/*********************************************************************
 * @fn      		  - SPI_PeripheralClockControl
 *
 * @brief             - 
 *
 * @param[in]         - 
 * @param[in]         - 
 *
 * @return            - 
 *
 * @Note              - 

 */
void SPI_PeripheralClockControl(SPI_REGS_t *pSPIx, uint8_t EnorDi) {
    if (EnorDi == ENABLE) {
        if (pSPIx == SPI1) {
            SPI1_PCLK_EN();
        }else if (pSPIx == SPI2) {
            SPI2_PCLK_EN();
        }else if (pSPIx == SPI3) {
            SPI3_PCLK_EN();
        }else if (pSPIx == SPI4) {
            SPI4_PCLK_EN();
        }
    }else {
        if (pSPIx == SPI1) {
            SPI1_PCLK_DI();
        }else if (pSPIx == SPI2) {
            SPI2_PCLK_DI();
        }else if (pSPIx == SPI3) {
            SPI3_PCLK_DI();
        }else if (pSPIx == SPI4) {
            SPI4_PCLK_DI();
        }
    }    
}

/*********************************************************************
 * @fn      		  - SPI_Init_Modes
 *
 * @brief             - 
 *
 * @param[in]         - 
 * @param[in]         - 
 *
 * @return            - 
 *
 * @Note              - 

 */
void SPI_Init_Modes(SPI_Handle_t *pSPIHandle) {}

/*********************************************************************
 * @fn      		  - SPI_DeInit
 *
 * @brief             - 
 *
 * @param[in]         - 
 * @param[in]         - 
 *
 * @return            - 
 *
 * @Note              - 

 */
void SPI_DeInit(SPI_REGS_t *pSPIx) {}

/*********************************************************************
 * @fn      		  - SPI_SendData
 *
 * @brief             - 
 *
 * @param[in]         - 
 * @param[in]         - 
 *
 * @return            - 
 *
 * @Note              - 

 */
void SPI_SendData(SPI_REGS_t *pSPIx, uint8_t *pTXBuffer, uint32_t lenght) {}

/*********************************************************************
 * @fn      		  - SPI_ReceiveData
 *
 * @brief             - 
 *
 * @param[in]         - 
 * @param[in]         - 
 *
 * @return            - 
 *
 * @Note              - 

 */
void SPI_ReceiveData(SPI_REGS_t *pSPIx, uint8_t *pRXBuffer, uint32_t lenght) {}

/*********************************************************************
 * @fn      		  - SPI_IRQConfig
 *
 * @brief             - 
 *
 * @param[in]         - 
 * @param[in]         - 
 *
 * @return            - 
 *
 * @Note              - 

 */
void SPI_IRQConfig(uint8_t IRQNumber, uint8_t EnorDi) {}

/*********************************************************************
 * @fn      		  - SPI_IRQPriorityConfig
 *
 * @brief             - 
 *
 * @param[in]         - 
 * @param[in]         - 
 *
 * @return            - 
 *
 * @Note              - 

 */
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority) {}

/*********************************************************************
 * @fn      		  - SPI_IRQHandling
 *
 * @brief             - 
 *
 * @param[in]         - 
 * @param[in]         - 
 *
 * @return            - 
 *
 * @Note              - 

 */
void SPI_IRQHandling(SPI_Handle_t *pSPIHandle) {}

/**
 ******************************************************************************
 * The MIT License (MIT)
 * Copyright (C) 2017 Microsoft Corp. 
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "IRDA_class.h"
#include "pinNames.h"
#include "PeripheralPins.h"


IRDA_HandleTypeDef IrdaHandle;
void USART3_IRQHandler( void )
{
    HAL_IRDA_IRQHandler( &IrdaHandle );
}


IRDASensor::IRDASensor()
{
}

IRDASensor::~IRDASensor()
{
}




uint8_t IRDASensor::init()
{
    OSStatus err = kNoErr;

    pinmap_pinout( PB_10, PinMap_UART_TX );
    pin_mode( PB_10, PushPullNoPull );

    __HAL_RCC_USART3_CLK_ENABLE( );

    __HAL_RCC_USART3_FORCE_RESET( );
    __HAL_RCC_USART3_RELEASE_RESET( );

    IrdaHandle.Instance = USART3;

    IrdaHandle.Init.BaudRate = 38400;
    IrdaHandle.Init.WordLength = UART_WORDLENGTH_8B;
    IrdaHandle.Init.Parity = UART_PARITY_NONE;
    IrdaHandle.Init.Mode = UART_MODE_TX_RX;
    IrdaHandle.Init.Prescaler = 1;
    IrdaHandle.Init.IrDAMode = IRDA_POWERMODE_NORMAL;

    /* Enable and set I2Sx Interrupt to a lower priority */
    HAL_NVIC_SetPriority( USART3_IRQn, 0x0F, 0x00 );
    NVIC_SetVector( USART3_IRQn, (uint32_t) & USART3_IRQHandler );
    HAL_NVIC_EnableIRQ( USART3_IRQn );

    err = HAL_IRDA_Init( &IrdaHandle );
    return err;    
}


unsigned char IRDASensor::IRDA_Transmit( unsigned char *pData, int size, int timeout)
{
    return HAL_IRDA_Transmit(&IrdaHandle, (uint8_t *)pData, (uint16_t)size, (uint32_t)timeout);
}

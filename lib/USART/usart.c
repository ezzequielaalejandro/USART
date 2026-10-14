#include "usart.h"

void usart_init(USART_TypeDef * USARTx, uint32_t baudrate){ //inicializo la comunicacion

    if(USARTx = 1) { RCC -> APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN; //PRENDO CLOCKS
                     GPIOA -> CRH &= ~(0XF << (9%8 * 4)); //TX
                     GPIOA -> CRH |= (0x3 << (9%8 * 4)); //TX

                     GPIOA -> CRH &= ~(0XF << (10%8 * 4)); //RX
                     GPIOA -> CRH |= (0X4 << (10%8 * 4)); //RX

                    clock_72MHz();

                     float velocidad = (16 * baudrate) / 72000000; //formula
                     int valor_mantissa = velocidad; //me quedo con la parte entera del float
                     int valor_fraction = (velocidad - valor_mantissa) * 100; //al restar float con int me queda la parte fraccional
                     valor_mantissa = (valor_mantissa << 4); //desplazo 4 bits de la parte entera para que entren los bits de la parte fraccional
                     USARTx -> BRR |= (valor_mantissa | valor_fraction); //uso un OR para "SUMAR" ambos conjuntos de bits y entren los 16 en el registro

                    }
                    
                    if(USARTx = 2) { RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
                     RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
                     GPIOA -> CRL &= ~(0XF << 2); //TX
                     GPIOA -> CRL |= (0x3 << 2); //TX

                     GPIOA -> CRL &= ~(0XF << 3); //RX
                     GPIOA -> CRL |= (0X4 << 3); //RX

                     float velocidad = (16 * baudrate) / 36000000; //formula
                     int valor_mantissa = velocidad; //me quedo con la parte entera del float
                     int valor_fraction = (velocidad - valor_mantissa) * 100; //al restar float con int me queda la parte fraccional
                     valor_mantissa = (valor_mantissa << 4); //desplazo 4 bits de la parte entera para que entren los bits de la parte fraccional
                     USARTx -> BRR |= (valor_mantissa | valor_fraction); //uso un OR para "SUMAR" ambos conjuntos de bits y entren los 16 en el registro

                }

                if(USARTx = 3) { RCC -> APB1ENR |= RCC_APB1ENR_USART3EN;
                     RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN; 
                     GPIOB -> CRH &= ~(0XF << (10%8 * 4)); //TX
                     GPIOB -> CRH |= (0x3 << (10%8 * 4)); //TX

                     GPIOB -> CRH &= ~(0XF << (11%8 * 4)); //RX
                     GPIOB -> CRH |= (0X4 << (11%8 * 4)); //RX           
                     
                     float velocidad = (16 * baudrate) / 36000000; //formula
                     int valor_mantissa = velocidad; //me quedo con la parte entera del float
                     int valor_fraction = (velocidad - valor_mantissa) * 100; //al restar float con int me queda la parte fraccional
                     valor_mantissa = (valor_mantissa << 4); //desplazo 4 bits de la parte entera para que entren los bits de la parte fraccional
                     USARTx -> BRR |= (valor_mantissa | valor_fraction); //uso un OR para "SUMAR" ambos conjuntos de bits y entren los 16 en el registro
                    }
                    
                  
                USARTx -> CR1 |= USART_CR1_UE; //ENCIENDO EL USART
                  
                USARTx -> CR1 &= ~USART_CR1_PCE; //apago la correccion de errores

                USARTx -> CR1 |= USART_CR1_TE; //PRENDO TRANSMISOR
                USARTx -> CR1 |= USART_CR1_RE; //PRENDO RECEPTOR

                //valor de bit de parada por default es 00 que es lo estandar para saber cual es el bit de parada
}

void usart_send_char(USART_TypeDef * USARTx, uint8_t data){
    while(!(USARTx -> SR & USART_SR_TXE));
        USARTx -> DR = data;
}

void usart_send_string(USART_TypeDef *USARTx, char* txt){
     
    while(txt) {
        usart_send_char(USARTx, txt);
        txt++;
    }
}

uint8_t usart_receive_char(USART_TypeDef * USARTx){
    
    while(!(USARTx -> SR & USART_SR_RXNE));
        
    return  USARTx -> DR;

}
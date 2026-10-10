#include "usart.h"

void usart_init(USART_TypeDef * USARTx, uint32_t baudrate){ //inicializo la comunicacion

    if(USARTx = 1) { RCC -> APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN; //PRENDO CLOCKS
                     GPIOA -> CRH &= ~(0XF << (9%8 * 4)); //TX
                     GPIOA -> CRH |= (0x3 << (9%8 * 4)); //TX

                     GPIOA -> CRH &= ~(0XF << (10%8 * 4)); //RX
                     GPIOA -> CRH |= (0X4 << (10%8 * 4)); //RX

                      float velocidad = (16 * baudrate) / 72000000; //formula
                    int valor_mantissa = velocidad; //me quedo con la parte entera del float
                    int valor_fraction = (velocidad - valor_mantissa) * 100; //al restar float con int me queda la parte fraccional
                    valor_mantissa = (valor_mantissa << 4); //desplazo 4 bits de la parte entera para que entren los bits de la parte fraccional
                    USART1 -> BRR |= (valor_mantissa | valor_fraction); //uso un OR para "SUMAR" ambos conjuntos de bits y entren los 16 en el registro
                    
                    USART1 -> CR1 |= USART_CR1_UE; //ENCIENDO EL USART
                }

    if(USARTx = 2) { RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
                     RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
                     GPIOA -> CRL &= ~(0XF << 2); //TX
                     GPIOA -> CRL |= (0x3 << 2); //TX

                     GPIOA -> CRL &= ~(0XF << 3); //RX
                     GPIOA -> CRL |= (0X4 << 3); //RX

                    float velocidad = (16 * baudrate) / 32000000; //formula
                    int valor_mantissa = velocidad; //me quedo con la parte entera del float
                    int valor_fraction = (velocidad - valor_mantissa) * 100; //al restar float con int me queda la parte fraccional
                    valor_mantissa = (valor_mantissa << 4); //desplazo 4 bits de la parte entera para que entren los bits de la parte fraccional
                    USART2 -> BRR |= (valor_mantissa | valor_fraction); //uso un OR para "SUMAR" ambos conjuntos de bits y entren los 16 en el registro
                    
                    USART2 -> CR1 |= USART_CR1_UE; //ENCIENDO EL USART
                }

    if(USARTx = 3) { RCC -> APB1ENR |= RCC_APB1ENR_USART3EN;
                     RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN; 
                     GPIOB -> CRH &= ~(0XF << (10%8 * 4)); //TX
                     GPIOB -> CRH |= (0x3 << (10%8 * 4)); //TX

                     GPIOB -> CRH &= ~(0XF << (11%8 * 4)); //RX
                     GPIOB -> CRH |= (0X4 << (11%8 * 4)); //RX

                     float velocidad = (16 * baudrate) / 32000000; //formula
                     int valor_mantissa = velocidad; //me quedo con la parte entera del float
                     int valor_fraction = (velocidad - valor_mantissa) * 100; //al restar float con int me queda la parte fraccional
                     valor_mantissa = (valor_mantissa << 4); //desplazo 4 bits de la parte entera para que entren los bits de la parte fraccional
                     USART1 -> BRR |= (valor_mantissa | valor_fraction); //uso un OR para "SUMAR" ambos conjuntos de bits y entren los 16 en el registro
                    
                     USART3 -> CR1 |= USART_CR1_UE; //ENCIENDO EL USART

                     USART3 -> CR1 |= USART_CR1_PCE; //enciendo la correccion de errores

                     if(USART3 -> CR1 |= (10 >> 10) & 1 ){} //leo el bit de PCE para saber si activo

                     /*¿¿¿¿QUIEN DETERMINA SI EL BIT DE PARIDAD TIENEN QUE SER PAR O IMPAR????*/
                    }

}
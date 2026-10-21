#include "stm32f103xb.h"
#include "usart.h"

int main(){
    usart_init(USART1, 115200);
    
    usart_send_char(USART1, 'a');
    while(1){
    }
}
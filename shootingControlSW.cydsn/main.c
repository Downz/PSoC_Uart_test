/*
En tidlig version af PWM motorstyring til projekt.
Vi kan her styre PWM til test.
I den færdige prototype skal vi have skrevet det her om til én setPWM() funktion, 
som RPIen kan kalde for at ændre, hvor langt der bliver skudt. 

GUIDE TIL TEST:
i, I, d og D ændrer PWM signalet med henholdsvis 1%, 10% -1% og -10%.
Brug 0 til at sætte PWM til 0%.
Hvis i oplever problemer med motoren hakker, så sæt clockPWMfreq op i topDesign. 
Bemærk, hvis i forsøger at sætte PWM signalet over/under 100%/0%, så dør baby.

*/
#include "PWMFuncs.h"
#include "project.h"

CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);
void decreasePWM(int x);
void increasePWM(int x);
void setPWM0(void);
int counter = 0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
    PWM_1_Start();
    setPWM0();
    
    UART_1_PutString("DC-Motor-PWM application started\r\n");
    UART_1_PutString("0: Set PWM to 0%\r\n");
    UART_1_PutString("d: Decrease PWM by 1% \r\n");
    UART_1_PutString("i: Increase PWM by 1% \r\n");
    UART_1_PutString("D: Decrease PWM by 10% \r\n");
    UART_1_PutString("I: Increase PWM by 10% \r\n");

    
    for(;;)
    {
        counter ++;
        UART_1_PutString("Hej Per!\n\r\n");
        CyDelay(2000);
    }
    
}

CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived);
        handleByteReceived(byteReceived);
        bytesToRead--;
    }
}

void handleByteReceived(uint8_t byteReceived)
{
        LED_Write(1);
    
    
    switch(byteReceived)
    {
        case 'd' :
        {
            decreasePWM(1);
        }
        break;
        case 'i' :
        {
            increasePWM(1);
        }
        break;
        case 'D' :
        {
            decreasePWM(10);
        }
        break;
        case 'I' :
        {
            increasePWM(10);
        }
        break;
        case '0' :
        {
           setPWM0();  
        }
        break;
        default :
        {
            // nothing
        }
        break;
    }
    
    //CyDelay(1000);
    LED_Write(0);
}


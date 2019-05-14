#include "SetPWM.h"


/*
   uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived);
*/

int setPWM(int PWM)
{
int8_t pwm_duty_val = PWM_1_ReadCompare();
pwm_duty_val = PWM;
PWM_1_WriteCompare(pwm_duty_val);
return pwm_duty_val;
}
/*
uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        int PWMRead = byteReceived;
        UART_1_PutString("Sætter PWM til ", PWMRead);
        int8_t pwm_duty_val = PWM_1_ReadCompare();
        pwm_duty_val = PWMRead;
        PWM_1_WriteCompare(pwm_duty_val);
        bytesToRead--;
*/

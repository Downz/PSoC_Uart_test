#include "PWMFuncs.h"
#include "project.h"

void decreasePWM(int x)
{
    UART_1_PutString("Decreasing PWM\r\n");
    int8_t pwm_duty_val = PWM_1_ReadCompare();
    pwm_duty_val -= x;
    PWM_1_WriteCompare(pwm_duty_val);
}

void increasePWM(int x)
{
    UART_1_PutString("Increasing PWM\r\n");
    int8_t pwm_duty_val = PWM_1_ReadCompare();
    pwm_duty_val += x;
    PWM_1_WriteCompare(pwm_duty_val);
}

void setPWM0()
{
    UART_1_PutString("Setting PWM 0\r\n");
    int8_t pwm_duty_val = 0;
    PWM_1_WriteCompare(pwm_duty_val);
}

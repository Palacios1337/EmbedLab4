#include <msp430.h>
int main(void)
{
    WDTCTL = WDT_ADLY_1000;  // WDT 250ms
    P6OUT &= ~BIT6; // sets the LED off initially
    P6DIR |= BIT6;
    PM5CTL0 &= ~LOCKLPM5;
    SFRIE1 |= WDTIE;
    _enable_interrupts(); // enables the interrupt
    while (1); // allows the code to continue running
}
 #pragma vector=WDT_VECTOR
__interrupt void wdtled(void)
{
            P6OUT^=BIT6; // interrupt which allows the blinking LED
}

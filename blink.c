// First example msp 430

#include <msp430g2553.h>

// configure clocks
void configure_clocks()
{
    // Stop watchdog
    WDTCTL = WDTPW + WDTHOLD;
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
}

// delay in microseconds
void delay_us(unsigned int us)
{
    while (us)
    {
        // 1 for 1 Mhz set 16 for 16 MHz
        __delay_cycles(16);
        us--;
    }
}

// delay in miliseconds
void delay_ms(unsigned int ms)
{
    while (ms)
    {
        // 1000 for 1MHz and 16000 for 16MHz
        __delay_cycles(16000);
        ms--;
    }
}
 
int main(void)
{

    configure_clocks();

    /* set P1 direction */
    P1DIR |= 0x41;

    /* leds off */
    P1OUT = 0x40;

    while(1)
    {
        /* toggle leds */
        P1OUT ^= 0x41;

        /* delay */
        delay_ms(500);
    }
  
}

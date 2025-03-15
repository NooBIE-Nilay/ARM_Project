#include <lpc214x.h>   
// Settings: Short jumper J17. Put DIP2 in Off position.
// Result: observe the toggling of LED's D10 to D13 From Left To Right & Vice Versa

unsigned int delay;

void delay_ms(unsigned int time) {
    for (delay = 0; delay < time * 1000; delay++); 
}

int main() {
    PINSEL1 = 0x00000000;  // Configure P0.16 to P0.19 as GPIO // PINSELx 0->PORT0 0-15;1-> PORT0 16-31; 2-> PORT1 16-31
    IO0DIR  = 0x000F0000;  // Set P0.16 to P0.19 as Output // 1->OUTPUT; 0->INPUT

    while (1) {
        // Left to Right Pattern (D10 → D11 → D12 → D13)
        for (int i = 16; i <= 19; i++) {
            IO0CLR = (1 << i);  // Turn ON LED (active-low)
            delay_ms(300);      // Wait
            IO0SET = (1 << i);  // Turn OFF LED 
        }

        // Right to Left Pattern (D13 → D12 → D11 → D10)
        for (int i = 19; i >= 16; i--) {
            IO0CLR = (1 << i);  // Turn ON LED
            delay_ms(300);      // Wait
            IO0SET = (1 << i);  // Turn OFF LED
        }
    }
}
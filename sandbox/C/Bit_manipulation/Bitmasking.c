#include <stdio.h>

// Helper function to print bits so you can see what's happening
void printBinary(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main() {
    // Initial state: 10101010 (Some LEDs are on)
    unsigned char led_register = 0x48; 

    printf("Initial:  ");

    led_register |= (1 << 3);
    led_register &= ~(1 << 6);
    led_register ^= (1 << 0);

    printBinary(led_register);

    // 1. TODO: Turn ON the 4th LED (Bit 3)
    // Hint: led_register = led_register | (1 << 3);

    // 2. TODO: Turn OFF the 7th LED (Bit 6)
    // Hint: Use &= and ~
    
    // 3. TODO: Toggle the 1st LED (Bit 0)
    // Hint: Use ^=

    printf("Final:    ");
    printBinary(led_register);

    return 0;
}

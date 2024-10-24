#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h> // For getch()

// Define bitmap for character 'A'
unsigned char A_bitmap[8] = {
    0b00011000,
    0b00100100,
    0b00100100,
    0b00111100,
    0b00100100,
    0b00100100,
    0b00000000,
    0b00000000
};

// Function to draw character using bitmap
void drawCharacter(int x, int y, unsigned char bitmap[8], int color) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (bitmap[i] & (1 << (7 - j))) { // Check if bit is set
                putpixel(x + j, y + i, color);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;

    // Initialize the graphics system
    initgraph(&gd, &gm, "");

    // Draw character 'A' at position (100, 100)
    drawCharacter(100, 100, A_bitmap, YELLOW);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0; // Return success
}

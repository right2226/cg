#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h> // For getch()

// Function to draw character 'A' using stroke method
void drawStrokeA(int x, int y, int color) {
    // Draw the character 'A'
    setcolor(color);
    line(x + 20, y + 50, x + 40, y + 50); // Base
    line(x + 10, y + 50, x + 20, y);     // Left diagonal
    line(x + 20, y, x + 30, y);          // Top
    line(x + 30, y + 50, x + 40, y + 50); // Base
    line(x + 10, y + 50, x + 30, y + 50); // Middle bar
}

int main() {
    int gd = DETECT, gm;

    // Initialize the graphics system
    initgraph(&gd, &gm, "");

    // Draw character 'A' at position (100, 100)
    drawStrokeA(100, 100, YELLOW);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0; // Return success
}

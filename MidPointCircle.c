#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h> // For getch()

void drawCircle(int xCenter, int yCenter, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius; // Initial decision parameter

    // Draw the initial points
    putpixel(xCenter + x, yCenter + y, 4); // Right
    putpixel(xCenter - x, yCenter + y, 4); // Left
    putpixel(xCenter + x, yCenter - y, 4); // Top
    putpixel(xCenter - x, yCenter - y, 4); // Bottom
    putpixel(xCenter + y, yCenter + x, 4); // Diagonal 1
    putpixel(xCenter - y, yCenter + x, 4); // Diagonal 2
    putpixel(xCenter + y, yCenter - x, 4); // Diagonal 3
    putpixel(xCenter - y, yCenter - x, 4); // Diagonal 4

    while (x < y) {
        x++;
        
        // Update decision parameter
        if (p < 0) {
            p += 2 * x + 1; // Move to the next point in the same row
        } else {
            y--;
            p += 2 * (x - y) + 1; // Move to the next point in the next row
        }

        // Draw the points
        putpixel(xCenter + x, yCenter + y, 4);
        putpixel(xCenter - x, yCenter + y, 4);
        putpixel(xCenter + x, yCenter - y, 4);
        putpixel(xCenter - x, yCenter - y, 4);
        putpixel(xCenter + y, yCenter + x, 4);
        putpixel(xCenter - y, yCenter + x, 4);
        putpixel(xCenter + y, yCenter - x, 4);
        putpixel(xCenter - y, yCenter - x, 4);
    }
}

int main() {
    int gd = DETECT, gm;

    // Initialize the graphics system
    initgraph(&gd, &gm, "");

    int xCenter = 200; // Center x-coordinate
    int yCenter = 200; // Center y-coordinate
    int radius = 100;  // Circle radius

    // Draw the circle
    drawCircle(xCenter, yCenter, radius);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0; // Return success
}

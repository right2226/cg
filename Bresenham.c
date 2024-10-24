#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h> // For getch()

int main() {
    int x1, y1, x2, y2, dx, dy, steps, x, y, p, gd = DETECT, gm;

    // Initialize the graphics system
    initgraph(&gd, &gm, "");

    // Define the endpoints of the line
    x1 = 100; 
    y1 = 200; 
    x2 = 150; 
    y2 = 300;

    // Calculate differences
    dx = x2 - x1;
    dy = y2 - y1;

    // Determine the steps needed
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increments
    float xinc = (float)dx / steps;
    float yinc = (float)dy / steps;

    // Initial point
    x = x1;
    y = y1;

    // Bresenham's algorithm
    putpixel(x, y, 4); // Plot the starting pixel
    p = 2 * dy - dx; // Initial decision parameter

    for (int i = 0; i < steps; i++) {
        x += xinc; // Increment x
        y += yinc; // Increment y
        
        // If the decision parameter is negative, choose the lower pixel
        if (p < 0) {
            p += 2 * dy; // Update decision parameter
        } else {
            y += 1; // Move to the next row
            p += 2 * (dy - dx); // Update decision parameter
        }
        
        putpixel(round(x), round(y), 4); // Plot the pixel
    }

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0; // Return success
}

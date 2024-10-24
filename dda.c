#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h> // For getch()

int main() {
    int x1, y1, x2, y2, dx, dy, steps, x, y, i;
    float xinc, yinc, gd = DETECT, gm;

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

    // Determine steps required for generating pixels
    steps = (abs(dx) >= abs(dy)) ? abs(dx) : abs(dy);

    // Calculate increment in x and y for each step
    xinc = (float)dx / steps; 
    yinc = (float)dy / steps;

    // Initial point
    x = x1;
    y = y1;

    // Plotting the line
    for (i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), 4); // Plot pixel and round the coordinates
        x += xinc; // Increment x
        y += yinc; // Increment y
    }

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0; // Return success
}
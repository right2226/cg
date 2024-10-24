#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h> // For getch()

void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    // Get the color of the pixel at (x, y)
    int currentColor = getpixel(x, y);

    // Check if the current pixel is not the boundary color and not filled
    if (currentColor != boundaryColor && currentColor != fillColor) {
        // Set the pixel to the fill color
        putpixel(x, y, fillColor);

        // Recursively call boundaryFill for neighboring pixels
        boundaryFill(x + 1, y, fillColor, boundaryColor); // Right
        boundaryFill(x - 1, y, fillColor, boundaryColor); // Left
        boundaryFill(x, y + 1, fillColor, boundaryColor); // Down
        boundaryFill(x, y - 1, fillColor, boundaryColor); // Up
    }
}

int main() {
    int gd = DETECT, gm;

    // Initialize the graphics system
    initgraph(&gd, &gm, "");

    // Draw a rectangle to fill
    rectangle(100, 100, 300, 300);

    // Define colors
    int fillColor = YELLOW;       // Color to fill with
    int boundaryColor = WHITE;    // Color of the boundary

    // Call the boundary fill algorithm
    boundaryFill(150, 150, fillColor, boundaryColor); // Starting point inside the rectangle

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0; // Return success
}

#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h> // For getch()

void floodFill(int x, int y, int fillColor, int boundaryColor) {
    // Get the color of the pixel at (x, y)
    int currentColor = getpixel(x, y);

    // Check if the current pixel is not the boundary color and not filled
    if (currentColor != boundaryColor && currentColor != fillColor) {
        // Set the pixel to the fill color
        putpixel(x, y, fillColor);

        // Recursively call floodFill for neighboring pixels
        floodFill(x + 1, y, fillColor, boundaryColor); // Right
        floodFill(x - 1, y, fillColor, boundaryColor); // Left
        floodFill(x, y + 1, fillColor, boundaryColor); // Down
        floodFill(x, y - 1, fillColor, boundaryColor); // Up
    }
}

int main() {
    int gd = DETECT, gm;

    // Initialize the graphics system
    initgraph(&gd, &gm, "");

    // Draw a shape (e.g., a rectangle) to fill
    rectangle(100, 100, 300, 300);

    // Define colors
    int fillColor = YELLOW;       // Color to fill with
    int boundaryColor = WHITE;    // Color of the boundary

    // Call the flood fill algorithm starting from a point inside the rectangle
    floodFill(150, 150, fillColor, boundaryColor);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0; // Return success
}

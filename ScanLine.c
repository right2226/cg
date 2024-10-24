#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct {
    int x, y;
} Point;

typedef struct {
    int x;
    float ymax, ymin, slope;
} Edge;

Edge edges[MAX_VERTICES]; // Edge table
int edgeCount = 0;

// Function to add edges to the edge table
void addEdge(int x1, int y1, int x2, int y2) {
    if (y1 > y2) {
        edges[edgeCount].x = x2; 
        edges[edgeCount].ymax = y1; 
        edges[edgeCount].ymin = y2; 
        edges[edgeCount].slope = (float)(x2 - x1) / (y2 - y1);
    } else {
        edges[edgeCount].x = x1; 
        edges[edgeCount].ymax = y2; 
        edges[edgeCount].ymin = y1; 
        edges[edgeCount].slope = (float)(x1 - x2) / (y1 - y2);
    }
    edgeCount++;
}

// Function to fill the polygon using the Scan Line Algorithm
void scanLineFill() {
    for (int y = 0; y < getmaxy(); y++) {
        int count = 0;
        int xValues[MAX_VERTICES];

        // Find intersections for each edge
        for (int i = 0; i < edgeCount; i++) {
            if (y >= edges[i].ymin && y <= edges[i].ymax) {
                xValues[count++] = edges[i].x;
                edges[i].x += edges[i].slope; // Update x for next scan
            }
        }

        // Sort xValues
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (xValues[j] > xValues[j + 1]) {
                    int temp = xValues[j];
                    xValues[j] = xValues[j + 1];
                    xValues[j + 1] = temp;
                }
            }
        }

        // Fill between pairs of xValues
        for (int i = 0; i < count; i += 2) {
            if (i + 1 < count) {
                for (int x = xValues[i]; x <= xValues[i + 1]; x++) {
                    putpixel(x, y, YELLOW);
                }
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;

    // Initialize the graphics system
    initgraph(&gd, &gm, "");

    // Define a polygon by its vertices
    Point polygon[MAX_VERTICES] = {
        {150, 100}, {200, 50}, {250, 100}, {250, 200}, {200, 150}, {150, 200}
    };
    int vertexCount = 6;

    // Draw the polygon
    for (int i = 0; i < vertexCount; i++) {
        line(polygon[i].x, polygon[i].y, polygon[(i + 1) % vertexCount].x, polygon[(i + 1) % vertexCount].y);
        addEdge(polygon[i].x, polygon[i].y, polygon[(i + 1) % vertexCount].x, polygon[(i + 1) % vertexCount].y);
    }

    // Fill the polygon
    scanLineFill();

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0; // Return success
}

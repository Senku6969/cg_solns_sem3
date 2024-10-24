#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// Function to rotate a line segment defined by points (x1, y1) and (x2, y2)
// around a midpoint (midx, midy) by a specified angle (deg) and color
void rotate(int x1, int y1, int x2, int y2, int midx, int midy, int deg, int color) {
    
    double c = cos(deg * 3.14 / 180);
    double s = sin(deg * 3.14 / 180);
    
    // Apply the rotation transformation
    int X1 = floor(x1 * c - y1 * s + midx * (1 - c) + midy * s);
    int Y1 = floor(y1 * c + x1 * s + midy * (1 - c) - midx * s);
    int X2 = floor(x2 * c - y2 * s + midx * (1 - c) + midy * s);
    int Y2 = floor(y2 * c + x2 * s + midy * (1 - c) - midx * s);

    // Shift the rotated line to a new position
    int shiftx = 150;
    int shifty = 0;

    // Set the drawing color and draw the rotated line
    setcolor(color);
    line(X1 + shiftx, Y1 + shifty, X2 + shiftx, Y2 + shifty);
}

// Flood fill function to fill a connected area with a new color
void ff(int x, int y, int oc, int nc) {
    // Check if the current pixel is of the original color
    if (getpixel(x, y) == oc) {
        putpixel(x, y, nc);  // Change the pixel to the new color
        // Recursively fill neighboring pixels
        ff(x + 1, y, oc, nc);
        ff(x - 1, y, oc, nc);
        ff(x, y + 1, oc, nc);
        ff(x, y - 1, oc, nc);
    }
}


void main() {
    int gd = DETECT, gm;
    int midx, midy, x[10], y[10], i, oc, nc, deg;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    // Define coordinates for the initial cylinder drawing
    y[0] = midy - 60;  x[0] = midx - 30;
    y[1] = midy - 55;  x[1] = midx - 40;
    y[2] = midy - 50;  x[2] = midx - 30;
    y[3] = midy - 50;  x[3] = midx + 30;
    y[4] = midy - 55;  x[4] = midx + 40;
    y[5] = midy - 60;  x[5] = midx + 30;
    y[6] = midy + 45;  x[6] = midx - 40;
    y[7] = midy + 50;  x[7] = midx - 30;
    y[8] = midy + 50;  x[8] = midx + 30;
    y[9] = midy + 45;  x[9] = midx + 40;

    // Draw the initial cylinder using lines
    for (i = 0; i < 5; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);  // Draw side lines
        if (i >= 1 && i <= 4) {
            line(x[i], y[i], x[i + 5], y[i + 5]);  // Draw connecting lines
            if (i != 4) line(x[i + 5], y[i + 5], x[i + 6], y[i + 6]);
        }
    }
    line(x[0], y[0], x[5], y[5]);  // Close the cylinder

    // Filling color in the defined area
    oc = 0;  // Original color to replace
    nc = 9;  // New color to fill
    ff(midx, midy, oc, nc);  // Fill the center
    delay(500);
    ff(midx + 38, midy + 43, oc, nc);  // Fill other parts
    delay(500);
    ff(midx - 38, midy - 43, oc, nc);  // Fill other parts
    delay(500);
    ff(midx, midy - 52, oc, nc);  // Fill other parts
    delay(500);

    // Prompt user for the degree of rotation
    printf("Enter the degree by which it should rotate: ");
    scanf("%d", &deg);
    nc = 15;  // New color for the rotated lines

    // Call the rotate function for each segment of the cylinder
    for (i = 0; i < 5; i++) {
        rotate(x[i], y[i], x[i + 1], y[i + 1], midx, midy, deg, nc);  // Rotate side lines
        if (i >= 1 && i <= 4) {
            rotate(x[i], y[i], x[i + 5], y[i + 5], midx, midy, deg, nc);  // Rotate connecting lines
            if (i != 4) rotate(x[i + 5], y[i + 5], x[i + 6], y[i + 6], midx, midy, deg, nc);
        }
    }
    rotate(x[0], y[0], x[5], y[5], midx, midy, deg, nc);  // Rotate closing line

    getch();  
    closegraph();  
}

#include <stdio.h>
#include <graphics.h>
#include <math.h>

void bresenhamLine(int x1, int y1, int x2, int y2, int style) {
    int dx, dy, p, x, y, xEnd, yEnd, steps;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    
    // Decision variable
    p = 2 * dy - dx;

    // Check which coordinates are bigger and swap to get start and end points
    if (x1 > x2) {
        x = x2;
        y = y2;
        xEnd = x1;
        yEnd = y1;
    } else {
        x = x1;
        y = y1;
        xEnd = x2;
        yEnd = y2;
    }

    putpixel(x, y, WHITE);  // Place the initial point

    steps = 0;  
    while (x < xEnd) {
        x++;  //x increment 
        // Horizontal only x
        if (p < 0) {
            p += 2 * dy;
        } else {  // Diagonal increment
            y++;
            p += 2 * (dy - dx);
        }

        // Depending on the style, decide whether to draw the pixel or not
        switch (style) {
            case 1:  // Dotted Line
                if (steps % 2 == 0)
                    putpixel(x, y, WHITE);
                break;
            case 2:  // Dashed Line
                if (steps % 8 != 0)  // Draws 4 skips 2 pixels
                    putpixel(x, y, WHITE);
                break;
            case 3:  // Thick Line
                putpixel(x, y, WHITE);
                putpixel(x, y + 1, WHITE);  // Add thickness by drawing adjacent pixels
                putpixel(x, y - 1, WHITE);
                break;
            default:  // Default to solid line
                putpixel(x, y, WHITE);
        }
        steps++;
    }
}

void drawMenu() {
    printf("\nChoose Line Style:");
    printf("\n1. Dotted Line");
    printf("\n2. Dashed Line");
    printf("\n3. Thick Line");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, choice;

    initgraph(&gd, &gm, "");

    do {
        drawMenu();
        scanf("%d", &choice);

        if (choice == 4)
            break;

        // Take line coordinates from the user
        printf("Enter the coordinates of the start point (x1, y1): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the end point (x2, y2): ");
        scanf("%d %d", &x2, &y2);

        // Draw the line according to the chosen style
        cleardevice();  // Clear the screen before drawing a new line
        bresenhamLine(x1, y1, x2, y2, choice);

    } while (choice != 4);

    closegraph();
    return 0;
}

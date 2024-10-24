#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void dotted(int r, int xc, int yc, int c);
void dashed(int r, int xc, int yc, int c);
void thick(int r, int xc, int yc, int c);

void dotted(int r, int xc, int yc, int c) {
    int x = 0;
    int y = r;
    int p = 1 - r; // initial decision parameter

    while (x < y) {
        if (x % 2 == 0) { 
            putpixel(xc + x, yc + y, c);
            putpixel(xc + y, yc + x, c);
            putpixel(xc + y, yc - x, c);
            putpixel(xc + x, yc - y, c);
            putpixel(xc - x, yc - y, c);
            putpixel(xc - y, yc - x, c);
            putpixel(xc - y, yc + x, c);
            putpixel(xc - x, yc + y, c);
        }
        if (p < 0) { // inc x (horizontally)
            p = p + (2 * x) + 1;
            x++;
        } else { // inc (diagonally) x, y
            p = p + (2 * x) - (2 * y) + 1;
            y--;
            x++;
        }
    }
}

void dashed(int r, int xc, int yc, int c) {
    int x = 0;
    int y = r;
    int p = 1 - r;
    while (x < y) {
        if (x % 6 != 0) { // dashed
            putpixel(xc + x, yc + y, c);
            putpixel(xc + y, yc + x, c);
            putpixel(xc + y, yc - x, c);
            putpixel(xc + x, yc - y, c);
            putpixel(xc - x, yc - y, c);
            putpixel(xc - y, yc - x, c);
            putpixel(xc - y, yc + x, c);
            putpixel(xc - x, yc + y, c);
        }
        if (p < 0) {
            p = p + (2 * x) + 1;
            x++;
        } else {
            p = p + (2 * x) - (2 * y) + 1;
            y--;
            x++;
        }
    }
}

void thick(int r, int xc, int yc, int c) {
    int x = 0;
    int y = r;
    int p = 1 - r;
    while (x < y) {
        putpixel(xc + x, yc + y, c);
        putpixel(xc + y, yc + x, c);
        putpixel(xc + y, yc - x, c);
        putpixel(xc + x, yc - y, c);
        putpixel(xc - x, yc - y, c);
        putpixel(xc - y, yc - x, c);
        putpixel(xc - y, yc + x, c);
        putpixel(xc - x, yc + y, c);

        if (p < 0) {
            p = p + (2 * x) + 1;
            x++;
        } else {
            p = p + (2 * x) - (2 * y) + 1;
            y--;
            x++;
        }
    }
}

void main() {
    int gm, gd = DETECT;
    int xc, yc, r, ch, i;
    clrscr();
    initgraph(&gd, &gm, "..\\BGI");

    printf("Enter the coordinates of center of circle: ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the radius of circle: ");
    scanf("%d", &r);

    do {
        printf("1. Dotted\n2. Dashed\n3. Thick\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                dotted(r, xc, yc, WHITE);
                break;
            case 2:
                dashed(r, xc, yc, WHITE);
                break;
            case 3:
                for (i = 0; i < 4; i++)
                thick(r + i, xc, yc, WHITE);
                break;
            case 4:
                closegraph();
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 4);
}

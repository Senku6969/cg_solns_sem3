#include <graphics.h>
#include <dos.h>
#include <conio.h>

//plot the rainbow using MPT
void plotCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void drawCircle(int xc, int yc, int r) {
    int x, y, d;
    x = 0;
    y = r;
    d = 1 - r;

    plotCirclePoints(xc, yc, x, y);

    while (x < y) {
        x++;
        if (d < 0) {
            d = d + 2 * x + 1;
        } else {
            y--;
            d = d + 2 * (x - y) + 1;
        }
        plotCirclePoints(xc, yc, x, y);
    }
}

int main() {
    int xc = 300, yc = 400;
    int i;
    int gd = DETECT, gm;

    int colors[] = {MAGENTA, BLUE, CYAN, GREEN, YELLOW, LIGHTRED, RED};
    int radii[] = {30, 50, 70, 90, 110, 130, 150};

    initgraph(&gd, &gm, "..\\BGI");

    line(150, 400, 450, 400); //bottom line

    for (i=0;i<7;i++)
    {
        drawCircle(xc, yc, radii[i]);
        setfillstyle(SOLID_FILL, colors[i]);
        floodfill(xc, yc - radii[i] + 10, WHITE);
        delay(500);
    }

    getch();
    closegraph();
    return 0;
}

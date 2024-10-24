#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int main() {
    int i, ch, gd = DETECT, gm,thick,j;
    int x1, y1, x2, y2;
    float x, y, dx, dy, steps;

    initgraph(&gd, &gm, "..\\BGI");

    printf("Enter the start coordinate of line: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the end coordinate of line: ");
    scanf("%d%d", &x2, &y2);
    printf("Select one:\n1. Dotted line\n2. Dashed line\n3. Thick line\n");
    scanf("%d", &ch);

    dx = (float)(x2 - x1);
    dy = (float)(y2 - y1);
    steps = fabs(dx) >= fabs(dy) ? fabs(dx) : fabs(dy);
    dx /= steps;
    dy /= steps;
    x = x1;
    y = y1;

    switch(ch) {
	case 1: // Dotted line
	    for(i = 0; i <= steps; i++) {
		if (i % 2 == 0) {
		    putpixel(x, y, RED);
		}
		x += dx;
		y += dy;
	    }
	    break;

	case 2: // Dashed line
	    for(i = 0; i <= steps; i++) {
		if (i % 8 != 0) {
		    putpixel(x, y, RED); // Dash after every 7 points
		}
		x += dx;
		y += dy;
	    }
	    break;

	case 3: // Thick line
	    printf("Enter thickness: ");
	    scanf("%d", &thick);
	    for(i = 0; i <= steps; i++) {
		for(j = -thick / 2; j <= thick / 2; j++) {
		    putpixel(x, y + j, RED);
		}
		x += dx;
		y += dy;
	    }
	    break;
    }

    getch();
    closegraph();
    return 0;
}

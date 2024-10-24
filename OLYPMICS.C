#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, "C:\\turboc3\\BGI"); 

    // Draw the first circle (top-left)
    setcolor(WHITE);
    circle(200, 200, 50); // Outer circle
    setfillstyle(SOLID_FILL, BLUE); // Fill color is set to blue
    floodfill(200, 200, WHITE); // Flood fill inside the outer circle
    circle(200, 200, 45); // Inner circle
    setfillstyle(SOLID_FILL, BLACK); // Inner fill color is set to black
    floodfill(200, 200, WHITE); // Flood fill inside the inner circle

    // Draw the second circle (top-center)
    setcolor(WHITE);
    circle(340, 200, 50); 
    setfillstyle(SOLID_FILL, RED); 
    floodfill(340, 200, WHITE);
    circle(340, 200, 45);
    setfillstyle(SOLID_FILL, BLACK); 
    floodfill(340, 200, WHITE); 

    // Draw the third circle (top-right)
    setcolor(WHITE);
    circle(480, 200, 50); 
    setfillstyle(SOLID_FILL, GREEN); 
    floodfill(480, 200, WHITE); 
    circle(480, 200, 45);
    setfillstyle(SOLID_FILL, BLACK); 
    floodfill(480, 200, WHITE);

    // Draw the fourth circle (bottom-left)
    setcolor(WHITE);
    circle(270, 250, 50);
    setfillstyle(SOLID_FILL, CYAN); 
    floodfill(270, 250, WHITE);
    circle(270, 250, 45); 
    setfillstyle(SOLID_FILL, BLACK); 
    floodfill(270, 250, WHITE); 

    // Draw the fifth circle (bottom-right)
    setcolor(WHITE);
    circle(410, 250, 50); 
    setfillstyle(SOLID_FILL, YELLOW); 
    floodfill(410, 250, WHITE); 
    circle(410, 250, 45);
    setfillstyle(SOLID_FILL, BLACK); 
    floodfill(410, 250, WHITE); 

    // Additional filling for connections between circles (cyan and yellow fill)
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(242, 210, WHITE); // Cyan flood fill to the left of center
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(298, 210, WHITE); // Cyan flood fill to the right of center
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(382, 210, WHITE); // Yellow flood fill to the left of center
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(437, 210, WHITE); // Yellow flood fill to the right of center

    getch();
    closegraph(); 
}

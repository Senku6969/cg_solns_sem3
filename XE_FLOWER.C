#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>

int main() 
{ 
    int gd = DETECT, gm, i, r; 
    initgraph(&gd, &gm, "c:\\turboc3\\bgi"); 

    r = 400; 
    setbkcolor(5); // Set background color
    setcolor(13);  // Set drawing color

    // Draw arcs in a circular pattern
    for (i = 0; i < 360; i += 30) 
    { 
        arc(320 + floor(r * cos(3.142 * i / 180)), 
            240 - floor(r * sin(3.142 * i / 180)), 
            120 + i + 30, 120 + i + 120 - 30, 
            r); 
        
        arc(320 + ceil(r * cos(3.142 * i / 180)), 
            240 - ceil(r * sin(3.142 * i / 180)), 
            120 + i + 30, 120 + i + 120 - 30, 
            r); 
        
        arc(320 + (r * cos(3.142 * i / 180)), 
            240 - (r * sin(3.142 * i / 180)), 
            120 + i + 30, 120 + i + 120 - 30, 
            r); 
    } 

    r /= 2; 

    // Fill sections with alternating colors
    for (i = 0; i < 720; i += 15) 
    { 
        setfillstyle(1, 15); 
        if (i % 2 == 0) 
            floodfill(320 + r * cos(3.142 * i / 180), 
                      240 - r * sin(3.142 * i / 180), 
                      13); 
    } 

    // Draw the central filled ellipse
    setfillstyle(1, 14); 
    fillellipse(320, 240, 50, 50); 

    getch(); 
    closegraph(); 
    return 0; 
}

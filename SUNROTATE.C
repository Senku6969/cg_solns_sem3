#include <stdio.h> 
#include <graphics.h> 
#include <conio.h> 
#include <dos.h> 
#include <math.h> 

void rotation(int arr[8], int midx, int midy, int deg, int color) 
{
    int result[8]; // Array to store the rotated coordinates.
    double c = cos(deg * 3.14 / 180); // Calculate cosine of the angle.
    double s = sin(deg * 3.14 / 180); // Calculate sine of the angle.

    // Apply 2D rotation for each vertex of the triangle.
    //The triangle has 3 vertices, so the function applies the 2D rotation formula to each of these vertices + same last vertices (so r[6] and r[7])

    result[0] = floor(arr[0] * c - arr[1] * s + midx * (1 - c) + midy * s); 
    result[1] = floor(arr[0] * s + arr[1] * c + midy * (1 - c) - midx * s); 

    result[2] = floor(arr[2] * c - arr[3] * s + midx * (1 - c) + midy * s); 
    result[3] = floor(arr[2] * s + arr[3] * c + midy * (1 - c) - midx * s); 

    result[4] = floor(arr[4] * c - arr[5] * s + midx * (1 - c) + midy * s); 
    result[5] = floor(arr[4] * s + arr[5] * c + midy * (1 - c) - midx * s); 

    result[6] = result[0]; 
    result[7] = result[1]; 

    setcolor(color); // Set the color of the polygon. (YELLOW here)
    drawpoly(4, result); // Draw the rotated polygon with 4 points.

    //ye yellow outer dega pura ---
    //setfillstyle(SOLID_FILL, color);
    //fillpoly(4,result);   
}


void main() 
{
    int gd = DETECT, gm;
    int i,j; 
    int arr[] = {290, 370, 350, 370, 320, 440, 290, 370}; // TRIANGLE CORDINATES !!! (starting ending same)
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 

    // draw yellow circle and fill w/ yellow color
    setcolor(YELLOW); 
    circle(320, 240, 100); 
    setfillstyle(SOLID_FILL, YELLOW); 
    floodfill(320, 240, YELLOW);

    // rotation animation looop.
    for (i = 0; i <= 360; i += 5)
    {
	// Rotate the triangle by a multiple of 45 degrees around the circle.
	for (j = 0; j <= 360; j += 45)
	{
	    rotation(arr, 320, 240, j + i, 14); // Rotate and draw the triangle.
	}
	delay(300); // Pause for half a second.

	// Erase the previous triangles by drawing them in black (background color).
	for (j = 0; j <= 360; j += 45)
	{
	    rotation(arr, 320, 240, j + i, 0);  //black color (gayab)
	}
    }

    getch();
    closegraph();
}

#include <stdio.h> 
#include <conio.h> 
#include <graphics.h> 
#include <dos.h> 
#include <math.h> 

// Function to rotate a triangle by a specified degree
void rotateT(int arr[], int deg) 
{ 
    int midx = 320; 
    int midy = 240; 
    double c = cos(deg * 3.14 / 180); 
    double s = sin(deg * 3.14 / 180); 
    int i; 
    int draw[8]; 

    // Rotate each vertex of the triangle
    for (i = 0; i < 8; i += 2) 
    { 
        draw[i] = floor(arr[i] * c - arr[i + 1] * s + midx * (1 - c) + midy * s); 
        draw[i + 1] = floor(arr[i] * s + arr[i + 1] * c + midy * (1 - c) - midx * s); 
    } 
    
    setcolor(BLUE); 
    setfillstyle(SOLID_FILL, 3); 
    drawpoly(4, draw); 
    floodfill(draw[0] + 5, draw[1] + 1, BLUE); 
}

// Function to rotate a base shape
void rotateB(int arr[], int deg) 
{ 
    int midx = 320; 
    int midy = 240; 
    double c = cos(deg * 3.14 / 180); 
    double s = sin(deg * 3.14 / 180); 
    int i; 
    int draw[10]; 

    // Rotate each vertex of the base shape
    for (i = 0; i < 10; i += 2) 
    { 
        draw[i] = floor(arr[i] * c - arr[i + 1] * s + midx * (1 - c) + midy * s); 
        draw[i + 1] = floor(arr[i] * s + arr[i + 1] * c + midy * (1 - c) - midx * s); 
    } 
    
    setcolor(BLUE); 
    setfillstyle(SOLID_FILL, 11); 
    drawpoly(5, draw); 
    floodfill(draw[0] + 5, draw[1] + 1, BLUE); 
}

// Function to scale a triangle
void scalingT(int arr[], int Sx, int Sy) 
{ 
    int i; 
    int draw[8]; 
    int midx = 320; 
    int midy = 240; 

    // Scale each vertex of the triangle
    for (i = 0; i < 8; i += 2) 
    { 
        draw[i] = arr[i] * Sx + midx * (1 - Sx) + 100; 
        draw[i + 1] = arr[i + 1] * Sy + midy * (1 - Sy); 
    } 
    
    setcolor(BLUE); 
    drawpoly(4, draw); 
}

// Function to scale a base shape
void scalingB(int arr[], int Sx, int Sy) 
{ 
    int i; 
    int draw[10]; 
    int midx = 320; 
    int midy = 240; 

    // Scale each vertex of the base shape
    for (i = 0; i < 10; i += 2) 
    { 
        draw[i] = arr[i] * Sx + midx * (1 - Sx) + 100; 
        draw[i + 1] = arr[i + 1] * Sy + midy * (1 - Sy); 
    } 
    
    setcolor(BLUE); 
    drawpoly(5, draw); 
}

void main() 
{ 
    int gd = DETECT, gm; 
    int base[] = {320, 300, 360, 320, 320, 340, 280, 320, 320, 300}; 
    int trR[] = {320, 240, 360, 320, 320, 300, 320, 240}; 
    int trL[] = {280, 320, 320, 300, 320, 240, 280, 320}; 
    
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
     
    setbkcolor(11); // Set background color
    setfillstyle(SOLID_FILL, WHITE); 
    setcolor(WHITE); 

    // Draw the initial shapes
    line(320, 240, 320, 300); 
    line(320, 300, 280, 320); 
    line(280, 320, 320, 240); 
    floodfill(321, 251, WHITE); 
      
    setfillstyle(SOLID_FILL, 3); 
    setcolor(3); 
    drawpoly(5, base); 
    floodfill(321, 311, 3); 

    setfillstyle(SOLID_FILL, 11); 
    setcolor(11); 
    drawpoly(4, trR); 
    floodfill(321, 251, 11); 

    setcolor(BLUE); 
    line(320, 240, 320, 300); 
    line(320, 300, 280, 320); 
    line(280, 320, 320, 240); 
    drawpoly(5, base); 
    drawpoly(4, trR); 

    getch(); 
    
    // Perform rotation on triangles and base shape
    rotateT(trR, 180); 
    rotateT(trL, 180); 
    rotateB(base, 180); 
    getch(); 
    
    // Perform scaling on triangles and base shape
    scalingT(trR, 2, 2); 
    scalingT(trL, 2, 2); 
    scalingB(base, 2, 2); 

    getch(); 
    closegraph(); 
} 

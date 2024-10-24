#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

void main()
{
	int gd = DETECT, gm, i;
	initgraph(&gd, &gm, "..\\BGI");

for(i=0;i<240;i=i+10){
   cleardevice();

  //pole
  setcolor(WHITE);
  setfillstyle(SOLID_FILL,BROWN);
  rectangle(105,100,125,400);
  floodfill(112,250,WHITE);

  //flagg
  setcolor(YELLOW);
  rectangle(125,340-i,225,360-i);
  setfillstyle(SOLID_FILL,YELLOW);
  floodfill(126,341-i,YELLOW);

  setcolor(WHITE);
  rectangle(125,360-i,225,380-i);
  setfillstyle(SOLID_FILL,WHITE);
  floodfill(126,361-i,WHITE);

  setcolor(GREEN);
  rectangle(125,380-i,225,400-i);
  setfillstyle(SOLID_FILL,GREEN);
  floodfill(126,381-i,GREEN);

  setcolor(BLUE);
  circle(175,370-i,10);
  setfillstyle(SOLID_FILL,BLUE);
  floodfill(175,375-i,BLUE);
  delay(300);
}
getch();
closegraph();
}


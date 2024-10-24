#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

void main()
{
	int gd = DETECT, gm, i;
	initgraph(&gd, &gm, "..\\BGI");

	for(i=0; i<30; i++)
	{
		cleardevice();
		setcolor(WHITE);

		circle(180,180,50);

		if(i%2 == 0)
		{
			circle(155, 168,10);
			circle(202, 168, 10);

			arc(180,193, 180, 360, 25);
			line(200, 240, 215, 215);
		}
		else
		{
			line(145, 168, 165, 168);
			line(192, 168, 212, 168);
			arc(180, 193, 210, 330, 25);
			line(200, 240, 220, 230);
		}
		line(180, 175, 180, 190);
		line(180, 205, 180, 250);
		line(180, 225, 160, 240);
		line(180, 225, 200, 240);
		delay(500);

	}
	getch();
	closegraph();
}

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int main()
{
  int i,gd=DETECT,gm;
  initgraph(&gd,&gm,"..\\BGI");

  for(i=0;i<50;i++)
  {
  cleardevice();
  line(250+i,300-i,300+i,200-i);
  line(300+i,200-i,350+i,300-i);
  line(350+i,300-i,300+i,400-i);
  line(300+i,400-i,250+i,300-i);
  line(300+i,200-i,300+i,400-i);
  line(250+i,300-i,350+i,300-i);
  ellipse(250+i,300-i,270,360,50,100);

  delay(100);
  }
  getch();
  closegraph();
  return 0;
}
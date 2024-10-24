#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int main()
{
  int i,gd=DETECT,gm;
  initgraph(&gd,&gm,"..\\BGI");

  for(i=0;i<100;i++)
  {
  cleardevice();
  //main boat
  line(200+i,200,400+i,200);
  line(200+i,200,250+i,240);
  line(250+i,240,350+i,240);
  line(350+i,240,400+i,200);

  //tail
  line(240+i,200,255+i,180);
  line(255+i,180,270+i,200);

  delay(100);
  }

  getch();
  closegraph();
  return 0;
}
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int main(){

  int i, gd = DETECT,gm;
initgraph(&gd,&gm,"C://TURBOC3//BGI");


 while(!kbhit()){
   for(i = 0; i<= 50; i++){
     cleardevice();

	 //ballooooooon
     setcolor(RED);
     setfillstyle(SOLID_FILL,RED);
     fillellipse(100-i,100-i,25,50);

     //border
     setcolor(WHITE);
     ellipse(100-i,100-i,0,360,26,51);  //-1 in height width

     //rope (left right)
     ellipse(90-i,150-i,270,360,12,50);
     ellipse(90-i,250-i,90,180,12,50); 

   delay(100);
  }

 }
  getch();
  closegraph();

  return 0;

}
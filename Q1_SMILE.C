#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

int main(){

int i,gd = DETECT,gm;

  initgraph(&gd,&gm,"C://TURBOC3//BGI");

       setcolor(YELLOW);
       circle(300,300,50);
       setfillstyle(SOLID_FILL,YELLOW);
       floodfill(300,300,YELLOW);  //circle face

       setcolor(0);
       setfillstyle(SOLID_FILL,0);
       arc(300,300,190,350,35);  //smile


    while(!kbhit()){

    for(i = -10;i<10;i++){
       setcolor(YELLOW);
       setfillstyle(SOLID_FILL,YELLOW);
       fillellipse(280+i-1,285,3,6);
       fillellipse(325+i-1,285,3,6);


      // Set the color to black to erase the previous eye position left to right eye movement -10 to 10 (niche wale me 10 to -10 ie right to left movement of the eyes)
       setcolor(BLACK);
       setfillstyle(SOLID_FILL,BLACK);
       fillellipse(280+i,285,3,6);
       fillellipse(325+i,285,3,6);

      // for smile animation
      if(i%2==0){
	setcolor(YELLOW);
	arc(300,300,190,350,35); //show full smile
	setcolor(0);
	arc(300,300,210,330,35); //remove partial smile (same in niche code)
      }
      else{
	setcolor(YELLOW);
	arc(300,300,210,330,35);
	setcolor(0);
	arc(300,300,190,350,35);
      }

      delay(500);
    }

    for(i = 10; i>=-10; i--){
      setcolor(YELLOW);
       setfillstyle(SOLID_FILL,YELLOW);
       fillellipse(280+i+1,285,3,6);
       fillellipse(325+i+1,285,3,6);

       setcolor(BLACK);
       setfillstyle(SOLID_FILL,BLACK);
       fillellipse(280+i,285,3,6);
       fillellipse(325+i,285,3,6);

      // for smile animation
      if(i%2==0){
	setcolor(YELLOW);
	arc(300,300,190,350,35); //show full smile
	setcolor(0);
	arc(300,300,210,330,35); //remove partial smile (same in niche code)
      }
      else{
	setcolor(YELLOW);
	arc(300,300,210,330,35);
	setcolor(0);
	arc(300,300,190,350,35);
      }

      delay(500);
    }
  }
  getch();
  closegraph();
  return 0;
}

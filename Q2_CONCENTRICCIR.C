#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

int main (){
int gd=DETECT,gm;
int x,y,r,dp,i,n;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

printf("enter number of con circles:");
scanf("%d",&n);

for(i=1;i<=n;i++){
printf("enter radius of circle %d:",i);
scanf("%d",&r);
x=0;
y=r;
dp=1-r;
	while(y>=x){
		putpixel(320+x,240+y,15);
		putpixel(320+x,240-y,15);
		putpixel(320-x,240+y,15);
		putpixel(320-x,240-y,15);
		putpixel(320+y,240+x,15);
		putpixel(320+y,240-x,15);
		putpixel(320-y,240+x,15);
		putpixel(320-y,240-x,15);

	if(dp<0){
	dp+=(2*x)+1;
	}
	else{
	y=y-1;
	dp+=(2*x)-(2*y)+1;
	}
	x+=1;
	}
r=0;
}
getch();
closegraph();
return 0;
}
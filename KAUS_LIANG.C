#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void main()
{
	int i,gd=DETECT,gm;
	int x1,y1,x2,y2,xmin,xmax,ymin,ymax,xx1,xx2,yy1,yy2,dx,dy;
	float t1,t2,p[4],q[4],temp;
	x1=y1=120;
	x2=y2=300;
	xmin=ymin=100;
	xmax=ymax=250;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	clrscr();
	rectangle(400,100,550,250);
	line(420,120,860,550);

	printf("\nLine after clipping\t\t\t\tLine Before Clipping\n");

	rectangle(xmin,ymin,xmax,ymax);
	dx=x2-x1;
	dy=y2-y1;

	p[0]=-dx;
	p[1]=dx;
	p[2]=-dy;
	p[3]=dy;
	q[0]=x1-xmin;
	q[1]=xmax-x1;
	q[2]=y1-ymin;
	q[3]=ymax-y1;

	for(i=0;i<4;i++)
	{
	   if(p[i]==0)
	   {
		printf("Line is parallel to clipping boundary");          

	//If q[i] >= 0, the line lies inside or on the boundary
		if(q[i]>=0) 
		{

			//i < 2: This condition refers to the vertical boundaries (left and right)
		   if(i<2)
		   {
		       if(y1<ymin)
		       {
			   y1=ymin;
		       }
		       if(y2>ymax)
		       {
			   y2=ymax;
		       }
		       line(x1,y1,x2,y2);            
		   }

			//i > 1: This condition refers to the horizontal boundaries (bottom and top).
		   if(i>1)
		   {
			if(x1<xmin)
			{
			    x1=xmin;
			}
			if(x2>xmax)
			{
			    x2=xmax;
			}
			line(x1,y1,x2,y2);
		   }
		}
	   }
	}

	//t1 and t2 help find the range where the line is inside the clipping window
	t1 = 0;
	t2 = 1;
	for(i = 0; i < 4; i++) 
	{
    	temp = q[i] / p[i];
    	if (p[i] < 0) 
		{
        	t1 = max(t1, temp);  
    	} 

		else 
		{
        	t2 = min(t2, temp);  
    	}
	}	

	//If t1 is less than t2, line is partially inside the clipping window
	if(t1<t2)
	{

		xx1=x1+t1*p[1]; 
		xx2=x1+t2*p[1];
		yy1=y1+t1*p[3];
		yy2=y1+t2*p[3];

		line(xx1,yy1,xx2,yy2); //draw clipped line
		delay(100);
	}

	getch();
	closegraph();
}

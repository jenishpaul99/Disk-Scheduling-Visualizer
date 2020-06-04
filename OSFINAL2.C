#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
//Visualization
  int r,l,index,n,i,gd=DETECT,gm,count=50,temp,y,z;
  char c[10],d[10];
  int j,g,k,q,x,init,a[8],b[9];
void swap(int *a,int*b)
	{
	 int temp;
	 temp=*a;
	 *a=*b;
	 *b=temp;
	}
int sign(int a)
	{
	 if(a>0)
	  return 1;
	 else if(a<0)
	  return -1;
	 else
	  return 0;
	}
void bresenham(int x1,int y1,int x2,int y2,int col)
	{
	 int d,inc1,inc2,i,dx,dy,x,y,flag,s1,s2;
	 dx=abs(x2-x1);
	 dy=abs(y2-y1);
	 x=x1;
	 y=y1;
	 s1=sign(x2-x1);
	 s2=sign(y2-y1);
	  if(dy>dx)
	   {
	    swap(&dx,&dy);
	    flag=1;
	   }
	  else
	   flag=0;
	  d=2*dy-dx;
	  inc1=2*dy;
	  inc2=2*(dy-dx);
	  putpixel(x,y,5);
	 for(i=1;i<=dx;i++)
	  {
	   if(d<0)
	    {
	     if(flag==1)
	      y=y+s2;
	     else
	      x=x+s1;
	     d=d+inc1;
	    }
	    else
	     {
	      y=y+s2;
	      x=x+s1;
	      d=d+inc2;
	     }
	    col=10;
	    putpixel(x,y,col);
	    delay(3);
	  }
	}
void clook()
{

settextstyle(1,0,3);
outtextxy(310,370,"CLOOK");
settextstyle(0,0,1);
count=50;
b[0]=init;
  for(i=0;i<n+1;i++)
  {
	 for(j=0;j<n;j++)
	 {
	  if(b[j]>b[j+1])
	  {
	  temp=b[j];
	  b[j]=b[j+1];
	  b[j+1]=temp;
	  }
	 }
  }
  for(i=0;i<n+1;i++)
  {
  if(b[i]==init)
  {
  index=i;
  break;
  }
  }
  line(0,50,600,50);
  for(k=0;k<=600;k+=30)
  {
   line(k,48,k,52);
   g=k/3;
   itoa(g,c,10);
   outtextxy(k,37,c);
  }
 for(i=index;i<n+1-1;i++)
 {

 bresenham(3*b[i],count,3*b[i+1],count+30,15);
 itoa(b[i],c,10);
 outtextxy(3*b[i]+5,count+13,c);
 fillellipse(3*b[i], count, 3, 3);
 count+=30;
 }
 itoa(b[i],c,10);
 outtextxy(3*b[i]+5,count-13,c);
 bresenham(3*b[n+1-1],count,3*b[0],count+30,15);
 fillellipse(3*b[i], count, 3, 3);
 count+=30;
 for(j=0;j<index-1;j++)
 {
 bresenham(3*b[j],count,3*b[j+1],count+30,15);
 itoa(b[j],c,10);
 fillellipse(3*b[j], count, 3, 3);
 outtextxy(3*b[j]-7,count-13,c);
 count+=30;
 }
 itoa(b[j],c,10);
 outtextxy(3*b[j]-7,count-13,c);
 fillellipse(3*b[j], count, 3, 3);
// outtextxy(150,120,"C-LOOK");
}

void sstf()
{
settextstyle(1,0,3);
outtextxy(310,370,"SSTF");
settextstyle(0,0,1);
count=50;
  //b[0]=init;
  for(i=0;i<n+1;i++)
  {
	 for(j=0;j<n;j++)
	 {
	  if(b[j]>b[j+1])
	  {
	  temp=b[j];
	  b[j]=b[j+1];
	  b[j+1]=temp;
	  }
	 }
  }
  for(i=0;i<n+1;i++)
  {
  if(b[i]==init)
  {
  index=i;
  break;
  }
  }
  l=index-1;
  r=index+1;
  line(0,50,600,50);
  for(k=0;k<=600;k+=30)
  {
   line(k,48,k,52);
   g=k/3;
   itoa(g,c,10);
   outtextxy(k,37,c);
  }
  x=index;
  while(l!=-1 && r!=n+1)
   {

    if((b[r]-b[x])<(b[x]-b[l]))
     {
      bresenham(3*b[x],count,3*b[r],count+30,15);
      itoa(b[x],c,10);
      outtextxy((3*b[x])-4,count+10,c);
       fillellipse(3*b[x], count, 3, 3);
      x=r;
      r++;
      count+=30;
      if(r==n+1)
       {
       bresenham(3*b[x],count,3*b[l],count+30,15);
       itoa(b[x],c,10);
      outtextxy((3*b[x])-4,count-10,c);
       fillellipse(3*b[x], count, 3, 3);
       count+=30;
       x=l;
       for(i=l;i>=1;i--)
	{
	 bresenham(3*b[i],count,3*b[i-1],count+30,15);
	 itoa(b[i],c,10);
	 outtextxy((3*b[i])-4,count-10,c);
	  fillellipse(3*b[i], count, 3, 3);
	 count+=30;
	}

       }
     }
    else
     {

      bresenham(3*b[x],count,3*b[l],count+30,15);
      itoa(b[x],c,10);
      outtextxy((3*b[x])-4,count-10,c);
       fillellipse(3*b[x], count, 3, 3);
      x=l;
      l--;
      count+=30;
      if(l==-1)
      {
	bresenham(3*b[x],count,3*b[r],count+30,15);
	itoa(b[x],c,10);
      outtextxy((3*b[x])-4,count-10,c);
	 fillellipse(3*b[x], count, 3, 3);
	count+=30;
       for(i=r;i<n;i++)
	{
	 bresenham(3*b[i],count,3*b[i+1],count+30,15);
	 itoa(b[i],c,10);
      outtextxy((3*b[i])-4,count-10,c);
	  fillellipse(3*b[i], count, 3, 3);
	 count+=30;
	}
 itoa(b[n],c,10);
      outtextxy((3*b[n])-4,count-10,c);
	fillellipse(3*b[n], count, 3, 3);
      }
     }
   }

}
void fcfs()
{
settextstyle(1,0,3);
outtextxy(320,370,"FCFS");
settextstyle(0,0,1);
  line(0,50,600,50);
  for(k=0;k<=600;k+=30)
  {
   line(k,48,k,52);
    g=k/3;
   itoa(g,c,10);
   outtextxy(k,37,c);
  }
 bresenham(3*init,50,3*a[0],80,10);
  itoa(init,c,10);
  outtextxy((3*init)-4,55,c);
  count=count+30;
 for(j=0;j<n;j+=1)
	{
	for(i=0;i<=200;i++)
	{
	 if(a[j]==i)
	 {
	 setcolor(15);
	 itoa(i,c,10);
	 fillellipse(3*i, count, 3, 3);
	 if(a[j]>a[j+1])
	 outtextxy(3*i+15,count,c);
	 else
	 outtextxy(3*i-20,count,c);
	 if(j<n-1)
		bresenham(3*i,count,3*a[j+1],count+30,15);
	 count+=30;
	 break;
	 }
	}
	}

}

void main()
 {
 //int n;
  clrscr();
  initgraph(&gd,&gm,"C:\\turboc3\\BGI");
  printf("Enter the number of elements:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  printf("Enter element %d:",i+1);
  scanf("%d",&a[i]);
  }
  //b[0]=0;
  for(i=1;i<n+1;i++)
  {
  b[i]=a[i-1];
  }
  //b[n-1]=a[i];
  printf("Enter initial point:");
  scanf("%d",&init);
  cleardevice();
  fcfs();
  getch();
  cleardevice();
  clook();
  getch();
  cleardevice();
  sstf();
  getch();
  closegraph();
 }

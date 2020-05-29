#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void clrscr(void);
void gotoxy(int x,int y);
void delay(unsigned int);

main()
{
 int x=5,y=3;
 int n=1,i,k=0;char c='H';
 char ch;int minusx=1,minusy=1,xx,yy;
 int ulboundryx[300],ulboundryy[300],lrboundryx[300],lrboundryy[300];
 clrscr();
 for(i=0;i<300;i++)
 {
  ulboundryx[300]=0;
  ulboundryy[300]=0;
  lrboundryx[300]=0;
  lrboundryy[300]=0;
 }

	 //                                   outer  boundry start

      for(i=1;i<80;i++) //top
      {

	 gotoxy(i,1);
	 ulboundryx[k]=i;
	 ulboundryy[k]=1;k++;
	 printf(" ");
       }
       for(i=1;i<=24;i++) //left
      {
	 gotoxy(1,i);
	 lrboundryx[k]=1;
	 lrboundryy[k]=i;k++;
	 printf(" ");
       }

       for(i=1;i<=24;i++) //right
      {
	 gotoxy(79,i);
	 lrboundryx[k]=79;
	 lrboundryy[k]=i;k++;
	 printf(" ");
       }
       for(i=1;i<80;i++) //bottom
      {
	 gotoxy(i,24);
	 ulboundryx[k]=i;
	 ulboundryy[k]=24;k++;
	 printf(" ");
       }
    //                                   outer  boundry end



  gotoxy(x,y);
 printf("%c",c);

 while(n>0)
 {
  xx=x;
  yy=y;
  x=x+minusx;
  y=y+minusy;

   for(i=0;i<k;i++)
      {
		   if(x==ulboundryx[i]&&y==ulboundryy[i])
		   {
		      minusy=minusy*(-1);
		   }
      }

      for(i=0;i<k;i++)
      {
		   if(x==lrboundryx[i]&&y==lrboundryy[i])
		   {
		      minusx=minusx*(-1);
		   }
      }
      delay(100);
     gotoxy(xx,yy);
 printf(" ");

    gotoxy(x,y);
 printf("%c",c);
 }
}

void clrscr()
{
    system("cls");
}

void gotoxy(int b,int v)
{
    COORD c;
    c.X=b;
    c.Y=v;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void delay(unsigned int mseconds)
{

    clock_t goal = mseconds+clock();
    while(goal>clock());
}

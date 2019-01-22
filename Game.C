//Hello World Program
#include<stdio.h>
#include<conio.h>
#include <graphics.h>
#include <dos.h>
#include <time.h>
# include "stdlib.h"
#define buspeed 40
struct score
{
	int gscore;
	int lvl;

}score_game;
struct bullet
{
int bullet_num;
 int buradius;
  int previous;
 int speedy;
 int old_xcenter;
 int old_ycenter;
 int new_xcenter;
 int new_ycenter;
}bul_1;
struct checkin
{
	int dead;
	int chnum;
	int xofch;
	int yofch;
}ch_1;
struct wepon
{
int length;
 int width;
 int ycoordinate;
 int new_xcoordinate;
 int old_xcoordinate;
}wp_1;

 int a[8];
 int b[8];

void initialize () // Initialize the game.

{
	
	int i=0;
 char tempstring [10]; //This String holds score in char format temporarily
 ch_1.dead=9;
 ch_1.chnum=8;
  ch_1.yofch=150;
 ch_1.xofch=0;


 for (i=0;i<ch_1.chnum;i++)
 {
setcolor(BROWN);
setfillstyle(SOLID_FILL,BROWN);
line(64+ch_1.xofch,214-ch_1.yofch,55+ch_1.xofch,230-ch_1.yofch);
line(48+ch_1.xofch,244-ch_1.yofch,34+ch_1.xofch,267-ch_1.yofch);
line(36+ch_1.xofch,268-ch_1.yofch,91+ch_1.xofch,268-ch_1.yofch); //imp one
line(93+ch_1.xofch,268-ch_1.yofch,80+ch_1.xofch,244-ch_1.yofch);
line(72+ch_1.xofch,230-ch_1.yofch,64+ch_1.xofch,215-ch_1.yofch);
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
line(55+ch_1.xofch,250-ch_1.yofch,70+ch_1.xofch,250-ch_1.yofch);
line(71+ch_1.xofch,251-ch_1.yofch,64+ch_1.xofch,262-ch_1.yofch);
line(65+ch_1.xofch,264-ch_1.yofch,56+ch_1.xofch,252-ch_1.yofch);
setcolor(LIGHTRED);
setfillstyle(SOLID_FILL,LIGHTRED);
ellipse(53+ch_1.xofch,238-ch_1.yofch,0,360,4,7);
ellipse(76+ch_1.xofch,238-ch_1.yofch,0,360,5,6);
ellipse(76+ch_1.xofch,239-ch_1.yofch,0,360,2,2);
ellipse(54+ch_1.xofch,239-ch_1.yofch,0,360,2,1);
setcolor(BROWN);
setfillstyle(SOLID_FILL,BROWN);
line(56+ch_1.xofch,270-ch_1.yofch,56+ch_1.xofch,289-ch_1.yofch); // imp one
line(56+ch_1.xofch,290-ch_1.yofch,52+ch_1.xofch,292-ch_1.yofch);
line(57+ch_1.xofch,291-ch_1.yofch,57+ch_1.xofch,295-ch_1.yofch);
line(58+ch_1.xofch,292-ch_1.yofch,54+ch_1.xofch,294-ch_1.yofch);
line(72+ch_1.xofch,270-ch_1.yofch,72+ch_1.xofch,288-ch_1.yofch);
line(72+ch_1.xofch,288-ch_1.yofch,70+ch_1.xofch,291-ch_1.yofch);
line(73+ch_1.xofch,288-ch_1.yofch,76+ch_1.xofch,293-ch_1.yofch);
line(74+ch_1.xofch,289-ch_1.yofch,73+ch_1.xofch,293-ch_1.yofch);
	 
a[i]= ch_1.xofch;
b[i]= ch_1.yofch;
ch_1.xofch=ch_1.xofch+75;
	 
	 
  }
 
 //Initialise wepon
 wp_1.length = 2;
 wp_1.width = 20;
 wp_1.ycoordinate = 430;
 wp_1.new_xcoordinate = 237;
 wp_1.old_xcoordinate = 237;



 // Intialise bullet
 bul_1.buradius = 3; // bullet size  <-------
 bul_1.previous=0;
 bul_1.speedy = 0;
 bul_1.old_xcenter = 244;
 bul_1.old_ycenter = 250;
 bul_1.new_xcenter = 244;
 bul_1.new_ycenter = 250;

 // Intialise Score
 score_game.gscore = 0;
 score_game.lvl = 0;

 // Set Background to white
 setbkcolor (BLACK);




 bar (wp_1.new_xcoordinate,wp_1.ycoordinate,wp_1.new_xcoordinate+wp_1.width,wp_1.ycoordinate+wp_1.length);



 // Display Score
textcolor ();
   sprintf (tempstring,"A - %d",score_game.gscore);
   outtextxy (10,450,tempstring);


}
void movebat (char input)

{
 switch (input)
   {
     case 'A' :
                    if (wp_1.new_xcoordinate > 0) // Move only when bat is not touching the top so it doesnt jump out of screen.
                  {
                    wp_1.old_xcoordinate = wp_1.new_xcoordinate = bul_1.old_xcenter = bul_1.new_xcenter;
                    wp_1.new_xcoordinate --;
                    bul_1.new_xcenter --;
                    setfillstyle (1,0);// Remove last postion.
                    bar (wp_1.old_xcoordinate,wp_1.ycoordinate,wp_1.old_xcoordinate+wp_1.width,wp_1.ycoordinate+wp_1.length);
                    setfillstyle (1,15); // Display New postion.
                    bar (wp_1.new_xcoordinate,wp_1.ycoordinate,wp_1.new_xcoordinate+wp_1.width,wp_1.ycoordinate+wp_1.length);
                    break;
                  }

     case 'Z' :


             if (wp_1.new_xcoordinate+wp_1.length < 620) // Make sure bat doesnot go below the screen.
                  {
                    wp_1.old_xcoordinate = wp_1.new_xcoordinate=bul_1.old_xcenter=bul_1.new_xcenter;
                    wp_1.new_xcoordinate ++;
                    bul_1.new_xcenter ++;
                    setfillstyle (1,0); // Remove last postion.
                    bar (wp_1.old_xcoordinate,wp_1.ycoordinate,wp_1.old_xcoordinate+wp_1.width,wp_1.ycoordinate+wp_1.length);
                    setfillstyle (1,15); // Display New postion.
                    bar (wp_1.new_xcoordinate,wp_1.ycoordinate,wp_1.new_xcoordinate+wp_1.width,wp_1.ycoordinate+wp_1.length);
                    break;
                   }

   }

}

void moveball ()

{
	
	bul_1.previous=1;

  bul_1.old_xcenter = bul_1.new_xcenter;
  bul_1.old_ycenter = bul_1.new_ycenter;
  bul_1.speedy--;
  bul_1.new_ycenter = bul_1.new_ycenter + bul_1.speedy;
  setcolor (0);
  setfillstyle (1,0);// Remove last postion.
  fillellipse (bul_1.old_xcenter,bul_1.old_ycenter,bul_1.buradius,bul_1.buradius);
  setfillstyle (1,15); // Display New postion.
  fillellipse (bul_1.new_xcenter,bul_1.new_ycenter,bul_1.buradius,bul_1.buradius);
 if (bul_1.new_ycenter<0) {
 bul_1.previous=0;
 bul_1.speedy = 0;
 bul_1.old_ycenter = 420;
 bul_1.new_ycenter = 420;

 }

}

void play () // the main loop of the game

{
	int i=0;
	
   while (inportb (0X60) != 16) // q= esc exit -_-
    {
      delay (10); // speed control :)
      if (inportb (0X60) == 30)  movebat ('A');
      if (inportb (0X60) == 44)  movebat ('Z');
	   if (inportb (0X60) == 57||bul_1.previous) moveball ();
	   
	 for (i=0;i<8;i++)
	 {
	   	if (a[i]<bul_1.new_xcenter&&a[i]+65>bul_1.new_xcenter)
	{
		if (b[i]>=bul_1.new_ycenter)
		{
			
		setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
a[i]=a[i]+50;
bar(a[i]-30,b[i],a[i]+80,b[i]-90);
score_game.gscore++;
		}
	}
    }
	if (score_game.gscore==8)
	{
		exit(0);
		}
	}
}
void start()
{
float octave[7] = { 130.81, 146.83, 164.81, 174.61, 196, 220, 246.94 
};
setbkcolor(0);
settextstyle(7,0,0);
outtextxy(10,400," PRESS ANY KEY TO CONTINUE....");
settextstyle(1,0,0);
setcolor(4);
setusercharsize(25,15,20,4);
outtextxy(85,120,"CHICKEN SHOOTING");
while( !kbhit() )
{
sound( octave[ random(7) ]*4 );
delay(300);
}
nosound();
getch();
clearviewport();
}
int main ()

{
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
start();
initialize ();
play ();
closegraph ();
return 0;
}

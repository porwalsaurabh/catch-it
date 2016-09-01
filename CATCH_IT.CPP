#include<graphics.h>
#include<dos.h>
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>

class bucket
{
	public:
	int cnt,colr[5],c,y,x,b,prevb,left,top,right,bottom,area,larea,barea,flag,score,life,lf,cb,ob,level;
	void *p,*bp,*lp;
	char name[10];
	char scre[1],live[1],st[1];
		bucket()
		{
			int gd=DETECT,gm,i;
			initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
			colr[0]=1;
			colr[1]=2;
			colr[2]=4;
			colr[3]=6;
			colr[4]=8;
			flag=0;
			cnt=0;
			c=3;
			y=40;
			x=5;
			b=5;
			prevb=5;
			left=b-5;            // x-36;
			top=370;           // y-36;
			right=b+85;        // x+36;
			bottom=465;         // y+36;
			area=imagesize(left,top,right,bottom);
			larea=imagesize(0,top,100,bottom);
			barea=imagesize(0,0,80,80);
			lp=malloc(larea);
			p=malloc(area);
			bp=malloc(barea);
			score=0;
			life=3;
			lf=1;
			cb=3;
			ob=300;
			strcpy(name,"SAURABH");
			level=0;
		}


void draw_bucket()
{
	if(b>120 && b<440)           // b>0 && b<559
	{
		setcolor(WHITE);
		  //	setlinestyle(SOLID_LINE,10,10);
		line(b,380,b+15,460);
		line(b+15,460,b+65,460);
		line(b+65,460,b+80,380);
		ellipse(b+40,380,0,360,40,10);
		setfillstyle(SOLID_FILL,colr[c]);
		floodfill(b+40,425,WHITE);
		setfillstyle(SOLID_FILL,0);
		floodfill(b+40,380,WHITE);
	     /*	if(b==300)
		{
			getimage(left,top,right,bottom,p);
			getimage(0,top,80,bottom,bp);
		}  */
	}
	else if(b<=120)          // b<=0
	{
		b=121;           // b=1
		draw_bucket();
	}
	else if(b>=440)          // b>=559
	{
		b=439;           // b=558
		draw_bucket();
	}
	       //	else
	       //	closegraph();
}

void draw_lines()
{
	int i;
	   setcolor(8);
	  // line(0,370,639,370);
	   line(110,0,110,479);
	   line(530,0,530,479);
	   line(109,0,109,479);
	   line(531,0,531,479);
	   line(108,0,108,479);
	   line(532,0,532,479);

	      /*	for(i=120;i<=520;i=i+40) // from 0 to 639 for full screen
		{
			if(i<160 ||i>480)  // remove this condition
				line(0+i,0,0+i,479);
		}
	       //	line(639,0,639,479);
	       */
	      /*
	      for(i=0;i<479;i=i+40)
	       {
			// line(0,0+i,639,0+i);
			 line(160,0+i,480,0+i);
	       }
	     //  line(0,479,639,479);
	     */
}

void draw()
{
       //	 cleardevice();
       //	 draw_lines();
	// draw_bucket();
	ball();
	 patch();
	 score_disp();
       //	 ball();
       //	line(0,290,639,290);
	 delay(20); 	 //25
}

void randm()
{
	c=rand()%4;
}

void randm_bucket()
{
	cb=rand()%4;
}


int randx()
{
	int x=rand()%440;      // x=rand()%600
	if(x<200)              // x<40
		x=x+200;       // x=x+40
	return x;
}

void draw_ball()
{
	if(y==40 || y>420)
	{
		cleardevice();
		draw_lines();
		patch();
		y=40;
		x=randx();
		if(level==2){randm();}
		ball();
		getimage(x-40,y-40-2,x+40-2,y+40,bp);
		score_disp();
		cnt++;
	}
	else
	{

	      //	delay(5);
	      //	draw();
	}

}

void ball()
{
	if(y==40)
	{
		setcolor(WHITE);
		circle(x,y,35);
		setfillstyle(SOLID_FILL,colr[c]);
		floodfill(x,y-30,WHITE);
		y=y+2;
	}
	else
	{
		putimage(x-40,y-40,bp,0);
		y=y+2;
	}
}

void move()
{
	cleardevice();
//	draw_lines();
       //	draw_bucket();
	draw_ball();
  //	patch();
   //	score_disp();
	delay(20);
}

void patch()
{
	if(b==5)
	{
		setcolor(WHITE);
		  //	setlinestyle(SOLID_LINE,10,10);
		line(b,380,b+15,460);
		line(b+15,460,b+65,460);
		line(b+65,460,b+80,380);
		ellipse(b+40,380,0,360,40,10);
		setfillstyle(SOLID_FILL,colr[cb]);
		floodfill(b+40,425,WHITE);
		setfillstyle(SOLID_FILL,0);
		floodfill(b+40,380,WHITE);
		getimage(0,top-150,100,bottom-150,lp);
		getimage(left,top,right,bottom,p);
	       //	rectangle(0,top-5,90,bottom+5);
	       //	getimage(0,top,90,bottom,bp);
	       //	cleardevice();
	       //	draw_lines();
		putimage(0,top,lp,0); //   juzz now commented
		b=300;
	       //	putimage(left,top,p,0);
	}
    //	void *p,*b;
    //	left=prevb-5;            // x-36;
    //	top=374;           // y-36;
    //	right=prevb+80;        // x+36;
    //	bottom=461;         // y+36;
    //	int area=imagesize(left,top,right,bottom);
    //	p=malloc(area);
    //	b=malloc(area);
    //	putimage(left,top,bp,0);
       //	putimage(0,top,bp,0);
      //	putimage(0,top,lp,0);
       // line(0,top,0,bottom);
	left=b-5;
    //	getimage(left,top,right,bottom,p);
	putimage(left,top,p,0);
     //   line(b-5,0,b-5,479);
}

void score_disp()
{
	settextstyle(BOLD_FONT,0,1);
	setcolor(3);
    //	name_disp();
	settextstyle(0,0,3);
	sprintf(scre,"%d",score);
	outtextxy(550,60,scre);
	sprintf(live,"%d",life);
	outtextxy(550,100,live);
}

void name_disp()
{
//	sprintf(st,"  %s",name);
//	outtextxy(550,40,st);
	outtextxy(550,30,name);
}

void score_cal()
{
 if(level==2)
 {
  if(x-40<b+15 && x-40>b-15)
  {
	if(y>330 && y<340)
	{
		switch(c)
		{
		  case 0:  score++;
		  break;
		  case 1:  score=score+2;
		  break;
		  case 2:  score=score+3;
		  break;
		  case 3:  score=score+5;
		  break;
		}
		flag=1;
		y=40;
	}
  }
  else
  {
	if(y==420)
	{
		if(life>0)
		{
			life--;
			 delay(100);
		}
		else
		{
			cleardevice();
			lf=0;
		}
	}
  }
 }
 else
 {
  if(x-40<b+15 && x-40>b-15)
  {
	if(y>330 && y<340)
	{
		score++;
		flag=1;
		y=40;
	}
  }
  else
  {
	if(y==420)
	{
		if(life>0)
		{
			life--;
			 delay(100);
		}
		else
		{
			cleardevice();
			lf=0;
		}
	}
  }

 }

}

void game_ovr()
{
	cleardevice();
	setcolor(1);
	settextstyle(0,0,4);   //BOLD_FONT
	sprintf(st,"Hello,  %s",name);
	outtextxy(getmaxx()/2-250,getmaxy()/2-100,st);
	outtextxy(getmaxx()/2-150,getmaxy()/2,"Game Over...");
	sprintf(scre,"Your Score is %d ",score);
	outtextxy(getmaxx()/2-250,getmaxy()/2-50,scre);
	getch();
	cleardevice();
	settextstyle(0,0,2);
	delay(1000);
	setcolor(YELLOW);
	outtextxy(getmaxx()/2-250,getmaxy()/2,"ENJOYED NA....! :D");
	delay(1000);
	cleardevice();
	setcolor(CYAN);
	delay(1000);
	outtextxy(getmaxx()/2-250,getmaxy()/2,"THANKS for Playing....!!");
	delay(1000);
	cleardevice();
	setcolor(GREEN);
	delay(1000);
	outtextxy(getmaxx()/2-250,getmaxy()/2,"Do give your sugesstions...!!");
	outtextxy(getmaxx()/2-250,getmaxy()/2+50,"Press any key to Exit...!!");
	getch();
}


void input()
{
       //	int i=1;
	char a;
	do
	{
		//draw_ball();
		score_cal();
		draw_ball();
	       //	a=getch();
		if(kbhit())
		{
			patch();
			a=getch();
			if(a=='a' ||a==75)
			{
			      //	cnt++;
				if(b>120)   // b>0
				{
					b=b-4;
				}
				draw();
				prevb=b;
			}
			else if(a=='d' ||a==77)
			{
			//	cnt++;
				if(b<440)   // b<559
				{
					b=b+4;
				}
				draw();
				prevb=b;
			}
			else if(a=='q')
			{
				break;
				exit(0);
			}

		}

		else
		{
		     //	delay(10);
		     //	draw();
		    /*	if(cnt>4)
			{
				cnt=0;
				randm_bucket();
			//	prevb=b;
				ob=b;
				b=5;
				y=40;
				draw_ball();
			}
			else   */
			draw();
		}

	    /*	if(a=='a' ||a==75)
		{
			cnt++;
			if(b>0)
			{
				b=b-4;
			}
			draw();
		}
		else if(a=='d' ||a==77)
		{
			cnt++;
			if(b<559)
			{
				b=b+4;
			}
			draw();
		}
		else if(a=='q')
		{
			break;
			exit(0);
		}
		else if(cnt>200)
		{
			cnt=0;
		       //	randm();
		}
		*/
	} while(lf);
	game_ovr();
	delay(2000);

}


	void level_select()
	{
	       cleardevice();
		char a;
		setcolor(13);

		rectangle(0,0,639,479);
		setcolor(13);
			rectangle(50,50,600,440);
			setcolor(10);
			sound(1);
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
	  //  settextstyle(SMALL_FONT, HORIZ_DIR, 8);
	    outtextxy(200,10,"LEVEL SELECTION");
	    setcolor(CYAN);
	    outtextxy(100,100,"EASY");
	    outtextxy(100,150,"HARD");

	    setcolor(RED);
	     settextstyle(SMALL_FONT, HORIZ_DIR, 6);
	    outtextxy(250,110,"Press 1 for EASY LEVEL");
	    outtextxy(250,160,"Press 2 for HARD LEVEL");
	    do
	    {
		 if(kbhit())
		 {
			 a=getch();
			if(a=='1')
			{
				level=1;
				return;
			}
			else if(a=='2')
			{
				level=2;
				return;

			}
			else if(a=='q')
			{
				exit(0);
			}
		  }
	    }while(1);
	  // getch();
	}


	void intro()
	{
	    setcolor(LIGHTBLUE);
	    settextstyle(BOLD_FONT,HORIZ_DIR,5);
	    delay(1000);
	    rectangle(50,50,600,439);
	    outtextxy(120,200,"INTRODUCING");
	    delay(1000);
	    cleardevice();
	    rectangle(50,50,600,439);
	    outtextxy(150,200,"CATCH IT");
	    delay(2000);
	    cleardevice();
	}

void load()
{
	cleardevice();
	draw_lines();
	setcolor(7);
	outtextxy(getmaxx()/2-100,getmaxy()/2,"Enter Any Key To Start...");
	settextstyle(0,0,2);
	outtextxy(getmaxx()/2-60,getmaxy()/2-40,name);
}

void user()
{
	cleardevice();
	setcolor(RED);
	rectangle(2,2,635,475);
	rectangle(7,7,630,470);
	setcolor(YELLOW);
	settextstyle(3, HORIZ_DIR,8);
	outtextxy(150,50,"CATCH IT");
	setlinestyle(DASHED_LINE,1,2);
	setcolor(BLUE);
	line(135,45,500,45);
	line(135,45,135,150);
	line(135,150,500,150);
	line(500,150,500,45);
	line(130,40,505,40);
	line(130,40,130,155);
	line(130,155,505,155);
	line(505,155,505,40);
	delay(150);
	settextstyle(3,0,2);
	setcolor(12);
	getch();
	outtextxy(150,200,"ENTER USERNAME:");
       //	restorecrtmode();
    //   char str[1];
    /*  for(int i=0;i<10;i++)
	{

	  char c=getch();
	  str[0]=c;

	     int j=0;
	 outtextxy(330+j,200,str);
	 j=j+5  ;

	}*/
	 for(int i=0;i<10;i++)//enter username of 10 characters only not less not more
	{
	  char c=getch();
	  if(c==13)
	  {
	    name[i]='\0';
	    i=11;
	  }
	  else name[i]=c;

	}
	if(name[0]=='\0')
	{
	  strcpy(name,"SAURABH");
	}

	for(int m=0;m<10;m++)
	{
	  int j=0;
	  outtextxy(330+j,200,name);
	  j=j+5;
	  }
	 delay(50);
 /*	  outtextxy(150,230,"USERNAME SET AS : ") ;
	  outtextxy(350,230,name);
	  getch();

       //	set_gfx_mode

      //	delay(250);   */
		setcolor(DARKGRAY);
		outtextxy(150,400,"PRESS ENTER..") ;
		getch();
		setlinestyle(SOLID_LINE,1,1);
		settextstyle(0,0,1);

}

};

int main()
{
	bucket s1,s2;
     //	s1.draw_lines();
     //	s1.draw();
	s1.intro();
	s2.user();
	s2.level_select();
	s2.load();
	getch();
	s2.input();
}

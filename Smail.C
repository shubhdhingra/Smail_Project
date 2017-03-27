#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<graphics.h>
#define TBG textbackground(YELLOW);textcolor(BLUE)

screen1()
 {
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"..//BGI");
 setfillstyle(1,RED);
 bar(0,0,640,480);
 setfillstyle(1,WHITE);
 bar(15,15,625,465);
 setfillstyle(1,RED);
 bar(30,30,610,450);
 settextstyle(1,0,8);
 setcolor(WHITE);
 outtextxy(180,35,"SERVER");
 setfillstyle(1,LIGHTGRAY);
 bar3d(160,140,455,130,20,20);
 outtextxy(190,150,"MAIL");
    bar3d(170,255,380,245,20,20);
 outtextxy(165,270,"SYSTEM");
 bar3d(145,375,440,365,20,20);
/* sleep(4);  */
getch();
 closegraph();
 restorecrtmode();
 }

 screen2()
 {
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"..//BGI");
 setfillstyle(1,RED);
 bar(0,0,640,480);
 setfillstyle(1,WHITE);
 bar(15,15,625,465);
 setfillstyle(1,RED);
 bar(30,30,610,450);
 setfillstyle(1,LIGHTGRAY);
 bar3d(180,100,520,300,25,25); /*members bar*/
 settextstyle(1,1,10);
 setcolor(WHITE);
 outtextxy(10,55,"JIIT");
 setfillstyle(1,LIGHTGRAY);
 bar3d(180,50,420,70,20,20);   /*project members bar*/
 bar3d(50,350,570,420,25,25);   //LRC
 setcolor(BLUE);
 settextstyle(1,0,3);
 outtextxy(175,360,"SERVER MAIL SYSTEM");
 settextstyle(1,0,2);
 outtextxy(195,48,"PROJECT MEMBERS");
 outtextxy(193,130,"SHUBHAM DHINGRA  14103176");
 outtextxy(193,170,"RISHABH JAIN       14103182");
 outtextxy(193,210,"APOORVA JINDAL     14103173");
 outtextxy(193,250,"SHUBHRA SINGH     14103177");
 getch();
 closegraph();
 restorecrtmode();
 }
 




box(int i,char *p)
 {
 setfillstyle(1,WHITE);
 bar(179,108+55*i,409,138+55*i);
 setfillstyle(1,LIGHTGRAY);
 bar(180,110+55*i,410,140+55*i);
 setcolor(BLUE);
// setfillstyle(SOLID_FILL,BLUE);
 settextstyle(1,0,2);
 outtextxy(184,110+55*i,p);
/* getch();
 setfillstyle(SOLID_FILL,WHITE);
 bar(180,60,390,90);
 setfillstyle(SOLID_FILL,RED);
 bar(179,59,389,89); */


/* bar3d(180,100,420,300,-25,25);*/ /*members bar*/
/* closegraph();
 restorecrtmode(); */
 }



selectbox(int i,char *p)
 {
 setfillstyle(1,WHITE);
 bar(179,108+55*i,409,138+55*i);
 setfillstyle(1,9);            //9-LIGHTBLUE
 bar(180,110+55*i,410,140+55*i);
 setcolor(WHITE);
// setfillstyle(SOLID_FILL,BLUE);
 settextstyle(1,0,2);          //0-horizontal
 outtextxy(184,110+55*i,p);
/* getch();
 setfillstyle(SOLID_FILL,WHITE);
 bar(180,60,390,90);
 setfillstyle(SOLID_FILL,RED);
 bar(179,59,389,89); */

/* bar3d(180,100,420,300,-25,25);*/ /*members bar*/
/* closegraph();
 restorecrtmode(); */
 }

pressbutton(int i,char *p)
 {
 setfillstyle(1,WHITE);
 bar(180,110+55*i,410,140+55*i);
 setfillstyle(1,9);
 bar(179,108+55*i,409,138+55*i);
 setcolor(CYAN);
 settextstyle(1,0,2);
 outtextxy(184,110+55*i,p);
 delay(500);
 }
 title(char *title,int x)           //main menu in middle
 {
	setfillstyle(1,9);
	bar(0,0,640,50);
	setcolor(BLACK);     //boundary colour
	settextstyle(1,0,5);          //int(font,hor dir, char size)
	outtextxy(x,0,title);
 }
 status()                        //instructions to user
 {
	setfillstyle(1,9);
	bar(0,450,640,480);
	setcolor(BLACK);
	settextstyle(1,0,3);
	outtextxy(30,450,"USE UP AND DOWN ARROW KEYS TO SELECT AN OPTION");
 }
// void view_inbox()
void main_menu()
  {
	char *menu[]={"INBOX",
		"SENTBOX",
		"COMPOSE",
		"SIGN OUT"};

	char ch;
	int gd=DETECT,gm,i,choice=0;
	initgraph(&gd,&gm,"..//BGI");
	setfillstyle(1,RED);
	bar(0,0,640,480);
	title("MAIN MENU",180);
	status();
	box(0,menu[0]);               //defined below
	box(1,menu[1]);              //makes a cuboid
	box(2,menu[2]);
	box(3,menu[3]);
	selectbox(choice,menu[choice]);

	//72  up
	//80  down
	//75  left
	//77  right
	//13  enter
	//49  1
	//71  Home
	//79  End
	//73 PgUp
	//81 PgDown
	//27 Escape



	while((ch=getch())!=13)    //GETCH RETURNS THE ASCII VALUE
	{
		switch(ch)
		{
		case 80:
		case 81:
		choice++;
		if(choice==4)
		choice=0;
		selectbox(choice,menu[choice]);
		for(i=0;i<=3;i++)
		{
		if(i==choice)
		continue;
		box(i,menu[i]);
		}
		break;
		case 72:
		case 73:
		choice--;
		if(choice==-1)
		choice=3;
		selectbox(choice,menu[choice]);
		for(i=0;i<=3;i++)
		{
		if(i==choice)
		continue;
		box(i,menu[i]);
		}
		}
	}

       pressbutton(choice,menu[choice]);

       switch(choice)
	  {
	    case 0:
		  // size=sizeof(ctr);
		   closegraph();
		   restorecrtmode();
     //ctr is object of customer
		   //customer();
		   break;
	    case 1:
		closegraph();
		   restorecrtmode();
		   //movie();
		   break;
	    case 2:
	   closegraph();
		   restorecrtmode();
		   //transactions();
		   break;
	    case 3:

		   closegraph();
		   restorecrtmode();
		   exit();

	  }
  }
void admin_menu()
  {
	char *menu[]={"SIGN IN",
		"SIGN UP",
		"DELETE ACCOUNT",
		"EXIT"};

	char ch;
	int gd=DETECT,gm,i,choice=0;
	initgraph(&gd,&gm,"..//BGI");
	setfillstyle(1,RED);
	bar(0,0,640,480);
	title("MAIN MENU",180);
	status();
	box(0,menu[0]);               //defined below
	box(1,menu[1]);              //makes a cuboid
	box(2,menu[2]);
	box(3,menu[3]);
	selectbox(choice,menu[choice]);

	//72  up
	//80  down
	//75  left
	//77  right
	//13  enter
	//49  1
	//71  Home
	//79  End
	//73 PgUp
	//81 PgDown
	//27 Escape



	while((ch=getch())!=13)    //GETCH RETURNS THE ASCII VALUE
	{
		switch(ch)
		{
		case 80:
		case 81:
		choice++;
		if(choice==4)
		choice=0;
		selectbox(choice,menu[choice]);
		for(i=0;i<=3;i++)
		{
		if(i==choice)
		continue;
		box(i,menu[i]);
		}
		break;
		case 72:
		case 73:
		choice--;
		if(choice==-1)
		choice=3;
		selectbox(choice,menu[choice]);
		for(i=0;i<=3;i++)
		{
		if(i==choice)
		continue;
		box(i,menu[i]);
		}
		}
	}

       pressbutton(choice,menu[choice]);

       switch(choice)
	  {
	    case 0:
		  // size=sizeof(ctr);
		   main_menu();
		   getch();
		   closegraph();
		   restorecrtmode();
		   exit();
     //ctr is object of customer
		   //customer();
		   break;
	    case 1:
		closegraph();
		   restorecrtmode();
		   //movie();
		   break;
	    case 2:
	   closegraph();
		   restorecrtmode();
		   //transactions();
		   break;
	    case 3:

		   closegraph();
		   restorecrtmode();
		   exit();

	  }
  }

void main()
{
	clrscr();
	screen1();
	getch();
	screen2();
	getch();
	admin_menu();
	getch();
}

#include"common.h"
#include"welcome.h"
int welcome(char *s1,char*s6,char*s18,char*s25,char *s41)//画出开机动画，选择 登录选项 
{
	clrmous(MouseX,MouseY); 
	delay(200);
	welcome_screen();
	save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	while(1)
	{	
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(79,319,239,399)==1)
		{
			return 0;//用户登录界面 
		}
		else if(mouse_press(402,322,562,362)==1)
		{
			return 23;//管理员登录界面 
		}
		else if(mouse_press(540,10,630,40)==1)
		{
			return 38;//退出程序 
		}
		
	}
	
	
	
}
void welcome_screen()//开机动画 
{
	 
	 int v1[10]={70,0,320,165,565,0};
	 int v2[10]={0,0,320,230,639,0};
	 int v3[10]={0,80,320,315,639,80};
	 int v4[10]={100,479,320,318,540,479};
	 int v5[10]={0,479,320,260,639,479};
	 int v6[10]={0,400,320,175,639,400};
	 setbkcolor(BLACK);
	 setfillstyle(1,1);
	 bar(0,0,640,480);
	 setcolor(WHITE);
	 setlinestyle(SOLID_LINE,1,3);
	 drawpoly(3,v1);
	 drawpoly(3,v2);
	 drawpoly(3,v3);
	 drawpoly(3,v4);
	 drawpoly(3,v5);
	 drawpoly(3,v6); 
	 setcolor(WHITE);
	 floodfill(320,300,WHITE);
	 floodfill(320,200,WHITE);
	 /*floodfill(20,140,YELLOW);
	 floodfill(40,10,YELLOW);*/
	 setfillstyle(1,15);
	 bar(159,100,515,145);
	 puthz(159+2,100+2,"图书馆信息资源管理系统",32,32,BLUE) ;
	 setcolor(BLACK);
	 rectangle(79,319,239,359);
	 setfillstyle(1,7);
	 bar(82,322,242,362);
	 puthz(79+20,319+2,"用户登录",32,32,BLACK);
	 setcolor(BLACK);
	 rectangle(399,319,559,359);
	 setfillstyle(1,7);
	 bar(402,322,562,362);
	 puthz(399+2,319+2,"管理员登录",32,32,BLACK);
	 setfillstyle(1,LIGHTGRAY);
	bar(542,12,632,42);
	setfillstyle(1,WHITE); 
	bar(540,10,630,40);
	puthz(560,17,"退出",24,24,BLACK); 
	
}

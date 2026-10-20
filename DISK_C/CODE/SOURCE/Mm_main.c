#include"common.h"
#include"Mm_main.h" 
//主界面：六个跳转
int manage_mainpage()
{
	int state=0,pre_state=0;
	clrmous(MouseX,MouseY); 
	delay(100);
	Draw_ManageMainpage();
	save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(65,310+40,155,340+40)==2)//退出登录、未点击 
		{
			pre_state=state;
			state=1;
			if(pre_state!=1)//防止重复标亮
			{
				clrmous(MouseX,MouseY);
				delay(5);
				setfillstyle(1,BLACK);
				bar(67,310+42,157,340+42);
				puthz(80,360,"退出登录",16,16,WHITE);
			}
		}
		else if(mouse_press(65,310+40,155,340+40)==1)//退出登录、点击
		{
			return 23;
		}
		else if(mouse_press(235,40,405,225)==2)//用户信息管理、未点击 
		{
			pre_state=state;
			state=2;
			if(pre_state!=2)//防止重复标亮
			{
				clrmous(MouseX,MouseY);
				delay(5);
				setfillstyle(1,BLACK);
				bar(235,40,405,225);
				puthz(245,131,"用户信息管理",24,24,WHITE);
			}
		}
		else if(mouse_press(235,40,405,225)==1)//用户信息管理、点击 
		{
			return 29; 
		}
		else if(mouse_press(435,40,605,225)==2)//书籍信息管理、未点击 
		{
			pre_state=state;
			state=3;
			if(pre_state!=3)//防止重复标亮
			{
				clrmous(MouseX,MouseY);
				delay(5);
				setfillstyle(1,BLACK);
				bar(435,40,605,225);
				puthz(445,131,"书籍信息管理",24,24,WHITE);
			}
		}
		else if(mouse_press(435,40,605,225)==1)//书籍信息管理、点击 
		{
			return 26; 
		}
		else if(mouse_press(235,255,405,440)==2)//借阅信息管理、未点击 
		{
			pre_state=state;
			state=4;
			if(pre_state!=4)//防止重复标亮
			{
				clrmous(MouseX,MouseY);
				delay(5);
				setfillstyle(1,BLACK);
				bar(235,255,405,440);
				puthz(247,346,"借阅信息管理",24,24,WHITE);
			}
		}
		else if(mouse_press(235,255,405,440)==1)//借阅信息管理、点击 
		{
			return 32; 
		}
		else if(mouse_press(435,255,605,440)==2)//图书馆座位管理、未点击 
		{
			pre_state=state;
			state=5;
			if(pre_state!=5)//防止重复标亮
			{
				clrmous(MouseX,MouseY);
				delay(5);
				setfillstyle(1,BLACK);
				bar(435,255,605,440);
				puthz(440,346,"图书馆座位管理",24,24,WHITE);
			}
		}
		else if(mouse_press(435,255,605,440)==1)//图书馆座位管理、点击 
		{
			return 33; 
		}
		else //无操作 
		{
			pre_state=state;
			state=0;
			MouseS=0; 
		}	
		
		//如果状态发生改变，且之前不是无操作状态，则可能需清除标亮
		if(pre_state!=state && pre_state!=0)
		{
			clrmous(MouseX,MouseY);
			delay(5);
			
			switch(pre_state)
			{
				case 1:
						setfillstyle(1,LIGHTGRAY);
						bar(67,310+42,157,340+42); 
						setcolor(BLACK);
						rectangle(65,310+40,155,340+40);
						puthz(80,360,"退出登录",16,16,BLACK);	
						break;
				case 2:
						setfillstyle(1,WHITE);
						bar(235,40,405,225);
						puthz(245,131,"用户信息管理",24,24,BLACK);
						break;
				case 3:
						setfillstyle(1,WHITE);
						bar(435,40,605,225);
						puthz(445,131,"书籍信息管理",24,24,BLACK);
						break;
				case 4:
						setfillstyle(1,WHITE);
						bar(235,255,405,440);
						puthz(247,346,"借阅信息管理",24,24,BLACK);
						break;
				case 5:
						setfillstyle(1,WHITE);
						bar(435,255,605,440);
						puthz(440,346,"图书馆座位管理",24,24,BLACK);
						break;
			}
		}		
	} 
}


/*****管理员端主界面画图****/ 
void Draw_ManageMainpage()
{
	int Tie[]={107,174,109,178,106,187,110,190,114,187,111,178,113,174,110,170,107,174}; 
	cleardevice();
	setfillstyle(1,BLUE);
	bar(0,0,640,480);
	setfillstyle(1,WHITE);
	bar(20,20,200,460);
	setfillstyle(1,LIGHTGRAY);
	bar(67,310+42,157,340+42);//退出登录 
	setcolor(BLACK);
	rectangle(65,310+40,155,340+40);
	puthz(65,215,"你好，管理员！",16,16,BLACK);
	puthz(80,360,"退出登录",16,16,BLACK);
	setfillstyle(1,BLACK);	//管理员头像大圆 
	fillellipse(110,170,30,30); 
	setfillstyle(1,WHITE);
	fillellipse(110,155,10,10);//人头
	setcolor(WHITE); 
	circle(110,155,10);
	rectangle(90,170,130,190);//身子 
	line(98,178,98,190);
	line(122,178,122,190);
	moveto(104,170);
	lineto(107,174);
	lineto(110,170);
	lineto(113,174);
	lineto(116,170);
	fillpoly(9,Tie);
	setfillstyle(1,LIGHTGRAY);
	bar(237,42,407,227);
	bar(437,42,607,227);
	bar(237,257,407,442);
	bar(437,257,607,442);
	setfillstyle(1,WHITE);
	bar(235,40,405,225);
	bar(435,40,605,225);
	bar(235,255,405,440);
	bar(435,255,605,440);
	puthz(245,131,"用户信息管理",24,24,BLACK);
	puthz(445,131,"书籍信息管理",24,24,BLACK);
	puthz(247,346,"借阅信息管理",24,24,BLACK);
	puthz(440,346,"图书馆座位管理",24,24,BLACK);
} 

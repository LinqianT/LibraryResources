/***************************************************/
/*页面：rgst_user;
  作者：dongyilei;
  功能：实现用户注册
  函数：register_user;
  		register_user_screen;*/ 
#include"common.h"
#include"Logtools.h"
#include"rgst_u.h"
int register_user(USER1 *p1,Link head)//实现用户的注册 
{
	INPUT stuid ={240,100,540,150,"",3,0,0};
	INPUT key={240,180,540,230,"",12,0,0};
	INPUT keyagain={240,260,540,310,"",12,0,0};
	int i;
	int j;
	int k;
	int s;
	int a;

	clrmous(MouseX,MouseY);
	delay(200);
	regist_user_screen();
	 while(1)
	 {
	 	input_s(240+4,100+4,&stuid,7,0);
		input_s(240+4,180+4,&key,7,1);
		input_s(240+4,260+4,&keyagain,7,1);
	 	newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(190,340,410,400)==1)
		{
			if(stuid.string[0]=='\0' && key.string[0]!='\0')
			{
				setfillstyle(1,1);
				bar(30,340,240,370);
				puthz(50,340,"未输入学号",24,24,WHITE);
			}
			else if(key.string[0]=='\0' && stuid.string[0]!='\0')
			{
				setfillstyle(1,1);
				bar(30,340,240,370);
				puthz(50,340,"未输入密码",24,24,WHITE);
			}
			else if(strcmp(key.string,keyagain.string)!=0)
			{
				setfillstyle(1,1);
				bar(30,340,240,370);
				puthz(30,340,"两次密码不一致",24,24,WHITE);				
			}
			else if(stuid.string[0]=='\0' && key.string[0]=='\0')
			{
				setfillstyle(1,1);
				bar(30,340,240,370);
				puthz(50,340,"请输入学号和密码",24,24,WHITE);
			}
			else if(strcmp(key.string,keyagain.string)==0 && stuid.string[0]!='\0' && key.string[0]!='\0')
			{
				if(judge_samestuid(stuid.string,head)==0)
				{
					setfillstyle(1,1);
					bar(30,340,240,370);
					puthz(50,340,"学号已存在！",24,24,WHITE);
				}
				else
				{
					strcpy(p1->name,"");
					strcpy(p1->gender,"");
					strcpy(p1->my_class,"");
					insert_user(p1->name,p1->gender,stuid.string,key.string,p1->my_class,head);//插入节点储存用户信息 
					wr_user_info(head);
					clrmous(MouseX,MouseY);
					setfillstyle(1,1);
					bar(30,340,240,370);
					delay(100); 
					drawpage_register();
					save_bk_mou(MouseX,MouseY);		
					delay(1000);
					clrmous(MouseX,MouseY);
					return 0;//返回登录界面 
				} 
			}
		}
		else if(mouse_press(540,10,630,40)==1)
		{
			
			save_bk_mou(MouseX,MouseY);
			clrmous(MouseX,MouseY);
			return 0;
		}
	}
}
void regist_user_screen()//画出用户注册界面的图 
{
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setcolor(WHITE);
	rectangle(240,10,440,80);
	puthz(240+2,10+2,"用户注册",48,48,WHITE);
	rectangle(40,110,120,150);
	puthz(40+2,110+2,"学号",32,32,WHITE);
	rectangle(40,180,120,230);
	puthz(40+2,180+2,"密码",32,32,WHITE);
	rectangle(40,260,180,310);
	puthz(40+2,260+2,"确认密码",32,32,WHITE);
	setcolor(BLACK);
	rectangle(240,340,350,400);
	setfillstyle(1,7);
	bar(245,345,355,405);
	puthz(240+2,340+2,"注册",48,48,BLACK);
	setfillstyle(1,15);
	bar(240,100,540,150);
	bar(240,180,540,230);
	bar(240,260,540,310);
	setfillstyle(1,LIGHTGRAY);
	bar(542,12,632,42);
	setfillstyle(1,WHITE); 
	bar(540,10,630,40);
	puthz(560,17,"返回",24,24,BLACK); 
}
void drawpage_register()//显示注册成功的界面 
{
	int v1[]={170,85,175,105,205,105,185,120,190,140,170,130,150,140,155,120,140,105,160,105,170,85};
	int v2[]={505,275,510,260,520,275,545,275,525,300,535,320,515,305,495,320,500,300,480,275,505,275};
	setfillstyle(1,15);
	bar(130,80,600,400);
	setcolor(BLUE);
	drawpoly(11,v1);
	drawpoly(11,v2);
	puthz(240+10,175+10,"注册成功",48,48,BLUE);
}

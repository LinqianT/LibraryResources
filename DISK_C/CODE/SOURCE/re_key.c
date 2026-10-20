/*******************************************************/
/*页面：reset_key;
  作者：dongyilei;
  功能：实现密码的重置；
  函数：(1)reset_key;
  		(2)reset_key_screen;
		(3)input_key_again;
		(4)input_id;
		(5)drawpage_reset_key;
  页面跳转：main;*/
#include"common.h"
#include"Logtools.h"
#include"re_key.h"
int reset_key(USER1 *p1,Link head)//密码重置 
{
	INPUT stuid={215,105,550,150,"",20,0,0};
	INPUT id={215,185,550,230,"",18,0,0};
	INPUT key={215,260,550,305,"",12,0,0};
	INPUT keyagain={215,340,550,385,"",12,0,0};
	int i=0;
	Link curr;
	curr=head->next; 
	reset_key_screen();
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);
	
	while(1)
	{
		input_s(215+4,105+4,&stuid,7,0);
		input_s(215+4,185+4,&id,7,0);
		input_s(215+4,260+4,&key,7,1);
		input_s(215+4,340+4,&keyagain,7,1);
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(500,400,625,470)==1)
		{
			if(strcmp(key.string,keyagain.string)==0 && strlen(id.string)==18)
			{
				while(curr!=NULL)//遍历链表找到当前用户的节点 
				{
					if(strcmp(stuid.string,curr->data.stuid)==0)
					{
						break;
					}
					else 
					{
						curr=curr->next;
					}
				}
				strcpy(p1->key,key.string);
				strcpy(curr->data.password,key.string);
				wr_user_info(head);
				if(strcmp(curr->data.password,key.string)==0)
				{
					i=drawpage_resetkey();
					if(i=1)
					{
						cleardevice();
						clrmous(MouseX,MouseY);
						save_bk_mou(MouseX,MouseY);
						return 0;
					}
				}
				else 
				{
					printf("error in changing your key!please try again!");
				}
				
			}
			else if(strcmp(key.string,keyagain.string)!=0&&strlen(id.string)==18)
			{
				setfillstyle(1,1);
				bar(215,395,480,430);
				puthz(215,395,"两次密码输入不一致",24,24,WHITE);
			}
			else if(strcmp(key.string,keyagain.string)==0&&strlen(id.string)!=18)
			{
				setfillstyle(1,1);
				bar(215,395,500,430);
				puthz(215,395,"身份证号格式有误",24,24,WHITE);
			}
			else if(strcmp(key.string,keyagain.string)!=0&&strlen(id.string)!=18)
			{		
				setfillstyle(1,1);
				bar(215,395,480,430);
				puthz(215,395,"检查密码输入和身份证号",24,24,WHITE);
			}
		}
		else if(mouse_press(540,10,630,40)==1)
		{
			clrmous(MouseX,MouseY);
			return 0;
			save_bk_mou(MouseX,MouseY);
		}

	}
}
void reset_key_screen()//画出重置密码的界面 
{
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setcolor(WHITE);
	rectangle(40,105,180,165);
	puthz(40+2,105+4,"学号",32,32,WHITE);
	rectangle(40,185,180,240);
	puthz(40+2,185+4,"身份证号",32,32,WHITE);
	rectangle(40,260,180,305);
	puthz(40+5,260+3,"新密码",32,32,WHITE);
	rectangle(40,340,180,390);
	puthz(40+2,340+4,"确认密码",32,32,WHITE);
	setcolor(BLACK);
	rectangle(500,400,625,470);
	setfillstyle(1,7);
	bar(505,405,630,475);
	puthz(500+15,400+15,"确定",48,48,BLACK);
	setfillstyle(1,15);
	bar(215,105,550,150);
	bar(215,185,550,230);
	bar(215,260,550,305);
	bar(215,340,550,385);
	setfillstyle(1,WHITE); 
	bar(540,10,630,40);
	puthz(560,17,"返回",24,24,BLACK); 
}

int drawpage_resetkey(void)//重置密码成功 
{
	int v1[]={130,100,140,75,145,100,170,110,145,115,140,140,130,115,105,110,130,100};
	int v2[]={530,250,540,280,560,290,540,295,530,315,525,295,500,290,525,280,530,250};
	setcolor(WHITE);
	bar(100,70,570,320);
	setcolor(BLUE);
	drawpoly(9,v1);
	drawpoly(9,v2);
	setcolor(BLACK);
	rectangle(270,250,360,290);
	setfillstyle(1,7);
	bar(272,252,362,292);
	puthz(190+10,170+10,"密码修改成功",48,48,BLUE);
	puthz(270+5,250+5,"确定",32,32,BLACK);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(270,250,360,290)==1)
		{
			return 1;
		} 
	}
	
}

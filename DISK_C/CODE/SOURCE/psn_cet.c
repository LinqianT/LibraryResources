/*************************************/
/*页面：psn_cet;
  作者：dongyilei;
  功能：进入个人中心界面，可以查看个人信息，借阅情况，收藏的文献以及自己座位的预约情况
  头文件："psn_cet.h"
  页面跳转：(1)after_login;
  			(2)my_borrrow;
  			(3)my_collection;
  			(4)record;
  			(5)personal_information;*/
  			
#include"common.h"
#include"Logtools.h"
#include"psn_cet.h"
int personal_center(USER1 *p1,Link head)//个人中心 
{
	int a=5;
	psn_cet_screen(p1,head);
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(235,85,335,185)==1)//修改个人信息 
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 10;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(390,85,490,185)==1)//查看我的借阅 
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 6;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(235,240,335,340)==1)//查看我的收藏 
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 7;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(520,150,600,200)==1)//返回 
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 4;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(40,20,180,60)==1)//退出登录 
		{
			strcpy(p1->name,'\0');
			strcpy(p1->key,'\0');
			strcpy(p1->key_again,'\0');
			strcpy(p1->study_id,'\0');
			strcpy(p1->my_class,'\0');
			strcpy(p1->study_id,'\0');
			strcpy(p1->gender,'\0');
			strcpy(p1->age,'\0');
			strcpy(p1->string,'\0');
			strcpy(p1->balance,'\0');
			itoa(a,p1->arrears,10);
			strcpy(p1->payment,'\0');
			strcpy(p1->borrow_book[1],'\0');
			strcpy(p1->collect_book[1],'\0');
			strcpy(p1->seat,'\0');
			cleardevice();
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			return 0;
		}
		else if(mouse_press(390,250,490,330)==1)//查看我的预约 
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			return 36;
		}
		else if(mouse_press(520,50,615,80)==1)//退出程序 
		{
			return 38;
		}
		
	}
	
}
void psn_cet_screen(USER1 *p1,Link head)//画出个人中心的界面 
{
	Link p;
	int v1[]={550,300,590,330,590,265,610,265,610,345,635,365,455,365,550,300};
	int v2[]={605,368,605,475,570,475,570,395,525,395,525,475,485,475,485,368};
	int v3[]={87,125,70,137,75,143,87,135,77,160,85,161,90,146,99,161,108,161,97,139,110,146,114,140,98,127};
	p=head->next;
	while(p!=NULL)
	{
		if(strcmp(p1->study_id,p->data.stuid)==0)
		{
			break;
		}
		else 
		{
			p=p->next;
		}
	}
	setbkcolor(BLACK);
	setfillstyle(1,1);
	settextstyle(1,0,2);
	bar(0,0,640,480);
	setcolor(WHITE);
	rectangle(190,10,490,75);
	line(215,95,215,479);
	line(570,475,525,475);
	circle(285,135,50);
	circle(440,135,50);
	circle(285,290,50);
	circle(440,290,50);
	drawpoly(8,v1);
	drawpoly(8,v2);
	circle(555,415,10);
	ellipse(95,135,0,360,80,50);
	circle(94,114,11);
	drawpoly(13,v3);
	puthz(30+5,185+5,"姓名",32,32,WHITE);
	if(strcmp(p->data.name,"")!=0)
	{
		puthz(120,185+5,p->data.name,24,24,WHITE);
	}
	puthz(30+5,230+5,"班级",32,32,WHITE);
	if(strcmp(p->data.class,"")!=0)
	{
		outtextxy(120,230+5,p->data.class);
	}	
	puthz(30+5,275+5,"学号",32,32,WHITE);
	if(strcmp(p->data.stuid,"")!=0)
	{
		outtextxy(120,275+5,p->data.stuid);
	}
	puthz(30+5,320,"性别",32,32,WHITE);
	if(strcmp(p->data.gender,"")!=0)
	{
		outtextxy(120,320,p->data.gender);
	}
	puthz(30+5,360+5,"年龄",32,32,WHITE);
	if(strcmp(p->data.age,"")!=0)
	{
		outtextxy(120,360+5,p->data.age);
	}
	puthz(30+5,405+5,"个人签名",32,32,WHITE);
	if(strcmp(p->data.string,"")!=0)
	{
		outtextxy(180,415+5,p->data.string);
	}
	puthz(235+5,120+5,"个人信息",24,24,WHITE);
	puthz(390+5,120+5,"我的借阅",24,24,WHITE);
	puthz(235+5,275+5,"我的收藏",24,24,WHITE);
	puthz(390+5,275+5,"我的预约",24,24,WHITE);
	puthz(190+60,0+20,"个人中心",48,48,WHITE);
	delay(200);
	setfillstyle(1,7);
	setcolor(BLACK);
	rectangle(520,150,600,200);
	rectangle(520,50,615,80);
	rectangle(40,20,150,55);
	bar(520+1,150+1,600+1,200+1); 
	bar(520+2,50+2,615+2,80+2);
	bar(40+2,20+2,150+2,55+2);
	puthz(520+6,150+6,"返回",32,32,BLACK); 
	puthz(40+3,20+6,"退出登录",24,24,BLACK);
	puthz(520+5,50+6,"退出程序",24,24,BLACK);
	
	
	
	
}	


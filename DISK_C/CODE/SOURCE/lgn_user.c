/******************************************************/
/*页面：lgn_user;
  作者：dongyilei;
  功能：实现用户的登录，读入用户输入的账户名以及密码等信息，与注册时的信息进行比对，符合即可登录
  头文件："lgn_user.h"
  页面跳转：(1)regiseter_user;
  			(2)reset_key;
			(3)after_login;*/

#include"common.h"
#include"Logtools.h"
#include"lgn_user.h"

int login_user(USER1*p1,USER1 *p2,Link head)
{	
	INPUT stuid ={230,100,550,150,"",3,0,0};
	INPUT key={230,190,550,240,"",12,0,0};
	int i=0;
	Link curr;
	curr=head->next;
	clrmous(MouseX,MouseY); 
	delay(100);
	login_user_screen();
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);
	while(1)
	{
		input_s(230+4,100+4,&stuid,7,0);
		input_s(230+4,190+4,&key,7,1);
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(240,280,390,350)==1)
		{
			if(stuid.string[0]=='\0'&&key.string[0]!='\0')
			{
				setfillstyle(1,1);
				bar(200,50,350,75);
				puthz(200,50,"未输入学号",24,24,WHITE);
			}
			else if(stuid.string[0]!='\0'&&key.string[0]=='\0')
			{
				setfillstyle(1,1);
				bar(200,50,350,75);
				puthz(200,50,"未输入密码",24,24,WHITE);
			}
			else if(stuid.string[0]=='\0'&&key.string[0]=='\0')
			{
				setfillstyle(1,1);
				bar(200,50,400,75);
				puthz(200,50,"请输入账号名和密码",24,24,WHITE);
			}
			else if(stuid.string[0]!='\0'&&key.string[0]!='\0')
			{
				if(judge_samestuid(stuid.string,head)==0)
				{
					while(curr!=NULL)							
					{
						if(strcmp(stuid.string,curr->data.stuid)==0)
						{
							if(strcmp(key.string,curr->data.password)==0)
							{
								setfillstyle(1,1);
								bar(200,50,350,75);
								puthz(200,50,"登陆成功",24,24,WHITE);
								strcpy(p1->study_id,curr->data.stuid);
								strcpy(p1->key,curr->data.password);
								delay(500);
								cleardevice();
								clrmous(MouseX,MouseY);
								save_bk_mou(MouseX,MouseY);
								return 4;
							}
							else 
							{
								setfillstyle(1,1);
								bar(200,50,350,75);
								puthz(200,50,"密码错误",24,24,WHITE);
								break;
							}
						}
						else 
						{
							curr=curr->next;
						}
					}
				}
				else 
				{
					puthz(200,50,"账号不存在，请先注册",24,24,WHITE);
				}
			}
		}
		else if(mouse_press(430,280,620,350)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			return 3;
			
		}
		else if(mouse_press(550,20,620,80)==1)
		 {
		 	clrmous(MouseX,MouseY);
		 	cleardevice();
		 	save_bk_mou(MouseX,MouseY);
		 	return 37;
		 }
		else if(mouse_press(50,280,200,350)==1)
		{	
			clrmous(MouseX,MouseY);
			cleardevice();
			save_bk_mou(MouseX,MouseY);
			return 1;
		}
	}
}
void login_user_screen()
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setcolor(WHITE);
	rectangle(40,100,200,150);
	puthz(80+2,100+5,"学号",32,32,WHITE);
	rectangle(40,190,200,230);
	puthz(80+2,190+2,"密码",32,32,WHITE);
	setcolor(BLACK);
	rectangle(50,280,200,350);
	setfillstyle(1,7);
	bar(55,285,205,355);
	puthz(80+2,280+10,"注册",48,48,BLACK);
	setcolor(BLACK);
	rectangle(240,280,390,350);
	setfillstyle(1,7);
	bar(245,285,395,355);
	puthz(240+30,280+10,"登录",48,48,BLACK);
	setcolor(BLACK);
	rectangle(550,20,620,80);
	rectangle(430,280,625,350);
	setfillstyle(1,7);
	bar(435,285,630,355);
	bar(550+2,20+2,620+2,80+2);
	puthz(430+2,280+10,"忘记密码",48,48,BLACK);
	puthz(550+5,20+10,"返回",32,32,BLACK);
	setfillstyle(1,15);
	bar(230,100,550,150);
	bar(230,190,550,240);
	
}



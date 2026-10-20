#include"common.h"
#include"LogTools.h"
#include"Mu_add.h"


/*用户信息添加界面 
	功能：输入用户信息 
*/ 

int usermng_add(Link head)
{	
	int len=0;
	char name[20]={'\0'};
	INPUT stuid ={90,68,450,97,"",3,0,0};
  	//INPUT name ={90,118,450,147,"",20,0,0};
	INPUT gender ={90,168,450,197,"",6,0,0};
	INPUT class ={90,218,450,247,"",10,0,0};
	INPUT password ={90,268,450,297,"",12,0,0};

	clrmous(MouseX,MouseY); 
	delay(100);
	Draw_usermngadd();
	save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		input_s(90+4,68+4,&stuid,7,0);
		//input_s(90+4,118+4,&name,7,0);
		input_s(90+4,168+4,&gender,7,0);
		input_s(90+4,218+4,&class,7,0);
		input_s(90+4,268+4,&password,7,0);
		
		if(mouse_press(540,10,630,40)==2||mouse_press(440,10,530,40)==2)//返回、未点击 
		{
			MouseS=1;
			continue;
		}
		else if(mouse_press(540,10,630,40)==1)//返回、点击
		{
			return 29;
		}
		else if(mouse_press(90,118,450,147)==1)
		{
			len=hz_input(90,118,450,147+10,name,len,WHITE);
		}
		else if(mouse_press(440,10,530,40)==1)//确认、点击 
		{
			//清除提示信息
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			bar(450,68,620,450);
			
			//判断是否输入完全
			if(stuid.string[0]=='\0')
			{
				puthz(450+4,68+3,"请输入学号",16,16,RED);
			}
			if(name[0]=='\0')
			{
				puthz(450+4,118+3,"请输入姓名",16,16,RED);
			}
			if(gender.string[0]=='\0')
			{
				puthz(450+4,168+3,"请输入性别",16,16,RED);
			}
			if(class.string[0]=='\0')
			{
				puthz(450+4,218+3,"请输入班级",16,16,RED);
			}
			if(password.string[0]=='\0')
			{
				puthz(450+4,268+3,"请输入密码",16,16,RED);
			}
			//判断性别输入是否合规m/f改→○M/○F 
			//判断密码是否符合要求 
			if(password.string[0]!='\0' && !judge_password(password.string))
			{
				puthz(450+4,268+3,"密码长度至少为六位",16,16,RED);
			}
			else if(stuid.string[0]!='\0')//已输入 
			{
				if(judge_samestuid(stuid.string,head)==0)
				{
					puthz(450+4,68+3,"学号已存在",16,16,RED);
				}
				else//写入用户信息 
				{
					insert_user(name,gender.string,stuid.string,password.string,class.string,head);
					wr_user_info(head);
					sucdraw(0);
					delay(1000);
					return 29;
				}
			} 
			continue; 
		}
		else //无操作 
		{
			MouseS=0;
			continue;
		}
	} 
}
void Draw_usermngadd()
{
	cleardevice();
	setfillstyle(1,BLUE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(10,50,630,470);
	
	puthz(20,17,"录入新用户",24,24,WHITE);
	puthz(20,70,"学号",24,24,BLACK);
	puthz(20,120,"姓名",24,24,BLACK); 
	puthz(20,170,"性别",24,24,BLACK); 
	puthz(20,220,"班级",24,24,BLACK);
	puthz(20,270,"密码",24,24,BLACK);
	setfillstyle(1,WHITE);
	bar(90,68,450,97);
	bar(90,118,450,147);
	bar(90,168,450,197);
	bar(90,218,450,247);
	bar(90,268,450,297);

	setfillstyle(1,LIGHTGRAY);
	bar(442,12,532,42);
	setfillstyle(1,WHITE); 
	bar(440,10,530,40);
	puthz(460,17,"确认",24,24,BLACK); 
	//返回查询界面AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA	
	setfillstyle(1,LIGHTGRAY);
	bar(542,12,632,42);
	setfillstyle(1,WHITE); 
	bar(540,10,630,40);
	puthz(560,17,"返回",24,24,BLACK); 
}

#include"common.h"
#include"LogTools.h"
#include"M_login.h"
int mng_login()
{
	INPUT password = {208,224,432,256,"",8,0,0};
	
	clrmous(MouseX,MouseY); 
	delay(200);
	Draw_mnglogin();
	save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		input_s(208+4,224+4,&password,7,1);
		
		if(mouse_press(540,10,630,40)==2||mouse_press(288-8,320-8,352+8,352+8)==2)//返回/登录、未点击 
		{
			MouseS=1;
			continue;
		}
		else if(mouse_press(540,10,630,40)==1)//返回、点击
		{
			return 37;
		}
		else if(mouse_press(288-8,320-8,352+8,352+8)==1)
		{
		
			//清除提示信息
			setfillstyle(SOLID_FILL, DARKGRAY);
			bar(416-16*5,256+4,416,256+4+16);
			//bar(160+320-16*5,192+32+4,160+320,192+32+4+16);
		
			//判断是否输入密码
			if(password.string[0]=='\0')
			{
				puthz(416-16*5,256+4,"请输入密码",16,16,WHITE);
			}
			
			//判断密码是否正确
			else if(strcmp(password.string,"123456")!=0)
			{
				puthz(416-16*4,256+4,"密码错误",16,16,WHITE);
			}
			
			//跳转页面
			else
			{
				delay(100);
				return 24;
			}
		}
		else
		{
			MouseS=0;
			continue;
		}			
	} 
} 

void Draw_mnglogin()
{
	cleardevice();
	setfillstyle(1,BLUE);
	bar(0,0,640,480);
	//背景框
	setcolor(LIGHTGRAY);
	setlinestyle(0,0,1);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(192,128,448,288);
	setfillstyle(SOLID_FILL, WHITE);
	bar(208,224,432,256);
	puthz(240+4,160+4,"管理员密码",24,32,WHITE);
	
	//登录按钮
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(288-8,320-8,352+8,352+8);
	puthz(288+4,320+4,"登录",24,32,WHITE);
	
	setfillstyle(1,LIGHTGRAY);
	bar(542,12,632,42);
	setfillstyle(1,WHITE); 
	bar(540,10,630,40);
	puthz(560,17,"返回",24,24,BLACK);
}

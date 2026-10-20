#include"common.h"
#include"Mng_seat.h"
#include"resv.h"
int mng_seat(USER*p1,Link head)
{
	clrmous(MouseX,MouseY); 
	delay(100);
	reservation_screen(head);
	save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(460,125,615,190)==1)// 二楼 
		{
			return 34;
		}
		else if(mouse_press(460,200,630,270)==1)// 三楼 
		{
			return 35;
		}
		else if(mouse_press(460,275,630,345)==1)// 四楼 
		{
			return 16;
		}
		else if(mouse_press(500,400,630,470)==1)//返回点击 
		{
			return 24;
		}
		else if(mouse_press(460,125,615,190)==2||mouse_press(460,200,630,270)==2||mouse_press(460,275,630,345)==2||mouse_press(500,400,630,470)==2)//未点击 
		{
			MouseS=1;
			continue;
		}
		else//无操作 
		{
			MouseS=0;
			continue;
		}
	}
	
}

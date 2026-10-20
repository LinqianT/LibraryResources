/************************************************/
/*页面: after_longin();
  作者：dongyilei 
  功能：绘出登录后的首界面，支持选择预约选座，修改个人信息，进入个人收藏界面和个人借阅界面的选择和进入
  头文件："aft_login.h"
  函数：(1)after_login();
  		(2)after_login_screen();
  页面跳转：5：personal_center;
  			9:reservation;*/	   
  			
#include"common.h"
#include"data.h"		
#include"aft_log.h"

int after_login(Link head)
{
	Link p;
	p=head->next;
	after_login_screen();
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(150,75,320,200)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 5;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(320,75,490,200)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 9;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(150,200,320,325)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 17;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(320,200,490,325)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 28;
			
		}
		
	}
 } 
void after_login_screen()
{
	setlinestyle(SOLID_LINE,1,3);
	setcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setcolor(WHITE);
	rectangle(150,75,490,325);
	line(320,75,320,325);
	line(150,200,490,200);
	line(0,350,639,350);
	puthz(150+10,75+50,"个人中心",32,32,WHITE);
	puthz(320+10,75+50,"预约选座",32,32,WHITE);
	puthz(150+10,200+50,"热门书籍",32,32,WHITE);
	puthz(320+10,200+50,"文献检索",32,32,WHITE);
	puthz(50+20,350+20,"书籍是人类进步的阶梯",48,48,WHITE);
	puthz(80+5,30+5,"欢迎访问图书馆信息资源管理系统",32,32,WHITE);
}

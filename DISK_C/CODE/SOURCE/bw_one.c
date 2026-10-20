/*****************************************/
/*页面：borrow_one;
  作者：dongyilei
  功能：绘出已借阅图书的界面 ，同时支持选择续借图书和归还图书，借阅缴费的跳转和选择
  头文件："borrow_one.h"
  函数：(1)borrow_one;
  		(2)borrow_one_screen;
  页面跳转：
  */ 

#include"common.h"
#include"bw_one.h"
int borrow_one()
{
	borrow_one_screen();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
	}
}
void borrow_one_screen()
{
	int v1[]={255,335,345,335,345,315,435,350,345,390,345,370,255,370,255,335};
	int v2[]={255,415,345,415,345,395,440,430,345,470,345,450,255,450,255,415};
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setfillstyle(1,15);
	bar(0,0,200,300);
	setcolor(WHITE);
	rectangle(30,350,215,465);
	drawpoly(8,v1);
	drawpoly(8,v2);
	puthz(30+10,350+10,"归还截止日期",24,24,WHITE);
	puthz(255+10,335+10,"归还图书",24,24,WHITE);
	puthz(255+10,415+10,"我要续借",24,24,WHITE);
	rectangle(30,350,215,465);
	
}

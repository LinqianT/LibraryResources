/***************************************************/
/*页面：my_borrow;
  作者：dongyilei;
  功能：实现用户借阅图书的查看
  头文件："my_borrow.h"
  页面跳转：(1)borrow_one;
  			(2)borrow_payment;*/ 
#include"common.h"
#include"data.h"
#include"my_bw.h"
#include"LogTools.h"

int my_borrow(USER1*p1,Link head)
{
	int result=0; 
	Link p;
	p=head->next;
	while(p!=NULL)
	{
		if(strcmp(p->data.stuid,p1->study_id)==0)
		{
			break;//找到当前节点 
		}
		else 
		{
			p=p->next;
		}
	}
	my_borrow_screen(p1,head);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(35,330,175,370)==1)//第一本书 
		{
			result=choose_fun();
			if(result==0)//取消 
			{	clrmous(MouseX,MouseY);
				save_bk_mou(MouseX,MouseY);
				my_borrow_screen(p1,head);
				save_bk_mou(MouseX,MouseY);
				drawmous(MouseX,MouseY);
				continue;
			}
			else if(result==1)//收藏 
			{
				strcpy(p->data.collect_book1,p->data.borrow_book1);
				wr_user_info(head);
				clrmous(MouseX,MouseY);
				save_bk_mou(MouseX,MouseY);
				my_borrow_screen(p1,head);
				save_bk_mou(MouseX,MouseY);
				drawmous(MouseX,MouseY);
			}
			else if(result==2)//归还 
			{
				//在外面遍历链表，以免嵌套结构太混乱复杂 
				//记录用户的借阅书籍情况变为归还 
				//链表信息中借书的书名不赋空，但是借阅状态要显示已归还 
				strcpy(p->data.borrow_book1,"");
				p->data.borrow_state=0;
				strcpy(p->data.borrow_time1,"");
				wr_user_info(head);
				clrmous(MouseX,MouseY);
				save_bk_mou(MouseX,MouseY);
				my_borrow_screen_new(p,head);
				save_bk_mou(MouseX,MouseY);
				drawmous(MouseX,MouseY); 
			}
		}
		else if(mouse_press(220,330,360,370)==1)//第二本书 
		{
			result=choose_fun();
			if(result==0)//取消 
			{	clrmous(MouseX,MouseY);
				save_bk_mou(MouseX,MouseY);
				my_borrow_screen(p1,head);
				save_bk_mou(MouseX,MouseY);
				drawmous(MouseX,MouseY);
				continue;
			}
			else if(result==1)//收藏 
			{
				strcpy(p->data.collect_book2,p->data.borrow_book2);
				clrmous(MouseX,MouseY);
				save_bk_mou(MouseX,MouseY);
				my_borrow_screen(p1,head);
				save_bk_mou(MouseX,MouseY);
				drawmous(MouseX,MouseY);
			}
			else if(result==2)//归还 
			{
				//在外面遍历链表，以免嵌套结构太混乱复杂 
				//记录用户的借阅书籍情况变为归还 
				//链表信息中借书的书名不赋空，但是借阅状态要显示已归还 
				strcpy(p->data.borrow_book2,"");
				p->data.borrow_state=0;
				strcpy(p->data.borrow_time2,"");
				wr_user_info(head);
				clrmous(MouseX,MouseY);
				save_bk_mou(MouseX,MouseY);
				my_borrow_screen_new(p,head);
				save_bk_mou(MouseX,MouseY);
				drawmous(MouseX,MouseY); 
			}
		}
		else if(mouse_press(405,330,620,370)==1)//第三本书 
		{
			result=choose_fun();
			if(result==0)//取消 
			{	clrmous(MouseX,MouseY);
				save_bk_mou(MouseX,MouseY);
				my_borrow_screen(p1,head);
				save_bk_mou(MouseX,MouseY);
				drawmous(MouseX,MouseY);
				continue;
			}
			else if(result==1)//收藏 
			{
				strcpy(p->data.collect_book3,p->data.borrow_book3);
				clrmous(MouseX,MouseY);
				save_bk_mou(MouseX,MouseY);
				my_borrow_screen(p1,head);
				save_bk_mou(MouseX,MouseY);
				drawmous(MouseX,MouseY);
			}
			else if(result==2)//归还 
			{
				//在外面遍历链表，以免嵌套结构太混乱复杂 
				//记录用户的借阅书籍情况变为归还 
				//链表信息中借书的书名不赋空，但是借阅状态要显示已归还 
				strcpy(p->data.borrow_book3,"");
				p->data.borrow_state=0;
				strcpy(p->data.borrow_time3,"");
				wr_user_info(head);
				clrmous(MouseX,MouseY);
				save_bk_mou(MouseX,MouseY);
				my_borrow_screen_new(p,head);
				save_bk_mou(MouseX,MouseY);
				drawmous(MouseX,MouseY); 
			}
		}
		
		else if(mouse_press(315,400,515,455)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 12;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(50,400,150,450)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			return 5;
		}
		
	}
}
void my_borrow_screen(USER1 *p1,Link head)
{
	Link p;
	int v1[]={315,400,415,400,415,375,510,425,415,475,415,455,315,455,315,400};
	p=head->next;
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setcolor(WHITE);
	drawpoly(8,v1);
	rectangle(220,5,435,75);
	puthz(220+10,5+10,"我的借阅",48,48,WHITE);
	puthz(315+5,400+10,"借阅缴费",32,32,WHITE);
	setfillstyle(1,15);
	bar(35,115,155,310);
	bar(215,115,335,310);
	bar(400,110,520,305);
	setcolor(BLUE);
	settextstyle(1,0,5);
	outtextxy(45,130,"BOOK");
	outtextxy(225,130,"BOOK");
	outtextxy(410,135,"BOOK");
	setfillstyle(1,CYAN);
	bar(35,330,175,370);
	bar(220,330,360,370);
	bar(405,330,620,370);
	setcolor(WHITE);
	rectangle(35+2,330+2,175+2,370+2);
	rectangle(220+2,330+2,360+2,370+2);
	rectangle(405+2,330+2,620+2,370+2);
	settextstyle(1,1,1);
	setcolor(BLACK);
	while(p!=NULL)
	{
		if(strcmp(p->data.stuid,p1->study_id)==0)
		{
			break;
		}
		else 
		{
			p=p->next;
		}
	}
	puthz(35+5,330+10,p->data.borrow_book1,16,16,BLACK);
	puthz(220+5,330+10,p->data.borrow_book2,16,16,BLACK);
	puthz(405+5,330+10,p->data.borrow_book3,16,16,BLACK);
	setcolor(BLACK);
	rectangle(50,400,150,450);
	setfillstyle(1,7);
	bar(50+2,400+2,150+2,450+2);
	puthz(50+5,400+5,"返回",32,32,BLACK);
	
}
int choose_fun()
{
	
	setfillstyle(1,8);
	bar(150,100,500,300);
	setfillstyle(1,7);
	bar(200+2,150+2,320+2,200+2);
	bar(350+2,150+2,465+2,200+2); 
	bar(300+2,220+2,355+2,260+2);
	setcolor(BLACK);
	rectangle(200,150,320,200);
	rectangle(350,150,465,200);
	rectangle(300,220,355,260);
	puthz(200+10,150+10,"确认收藏",24,24,BLACK);
	puthz(350+10,150+10,"取消借阅",24,24,BLACK);
	puthz(300+3,220+4,"返回",24,24,BLACK);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(200,150,320,200)==1)//收藏图书 
		{
			
			return 1;
		}
		else if(mouse_press(350,150,465,200)==1)//归还图书  
		{
			return 2;
		}
		else if(mouse_press(300,220,355,260)==1)//取消 
		{
			return 0;
		}
	}
}
void my_borrow_screen_new(Link p,Link head)
{
	int a,b,c;
	int v1[]={315,400,415,400,415,375,510,425,415,475,415,455,315,455,315,400};
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setcolor(WHITE);
	drawpoly(8,v1);
	rectangle(220,5,435,75);
	puthz(220+10,5+10,"我的借阅",48,48,WHITE);
	puthz(315+5,400+10,"借阅缴费",32,32,WHITE);
	setfillstyle(1,15);
	bar(35,115,155,310);
	bar(215,115,335,310);
	bar(400,110,520,305);
	setcolor(BLUE);
	settextstyle(1,0,5);
	outtextxy(45,130,"BOOK");
	outtextxy(225,130,"BOOK");
	outtextxy(410,135,"BOOK");
	setfillstyle(1,CYAN);
	bar(35,330,175,370);
	bar(220,330,360,370);
	bar(405,330,620,370);
	setcolor(WHITE);
	rectangle(35+2,330+2,175+2,370+2);
	rectangle(220+2,330+2,360+2,370+2);
	rectangle(405+2,330+2,620+2,370+2);
	settextstyle(1,1,1);
	setcolor(BLACK);
	if(strcmp(p->data.borrow_book1,"")==0)
	{
		a=0;
	}
	else 
	{
		a=1;
	}
	if(strcmp(p->data.borrow_book2,"")==0)
	{
		b=0;
	}
	else 
	{
		b=1;
	}
	if(strcmp(p->data.borrow_book3,"")==0)
	{
		c=0;
	}
	else 
	{
		c=1;
	}
	if(a==0&&b==1&&c==0)
	{
		strcpy(p->data.borrow_book1,p->data.borrow_book2);
		strcpy(p->data.borrow_book2,"");
		wr_user_info(head);
	}
	else if(a==0&&b==1&&c==1)
	{
		strcpy(p->data.borrow_book1,p->data.borrow_book2);
		strcpy(p->data.borrow_book2,p->data.borrow_book3);
		strcpy(p->data.borrow_book3,"");
		wr_user_info(head);
	}
	else if(a==1&&b==0&&c==1)
	{
		strcpy(p->data.borrow_book2,p->data.borrow_book3);
		strcpy(p->data.borrow_book3,"");
		wr_user_info(head);
	}
	puthz(35+5,330+10,p->data.borrow_book1,16,16,BLACK);
	puthz(220+5,330+10,p->data.borrow_book2,16,16,BLACK);
	puthz(405+5,330+10,p->data.borrow_book3,16,16,BLACK);
	setcolor(BLACK);
	rectangle(50,400,150,450);
	setfillstyle(1,7);
	bar(50+2,400+2,150+2,450+2);
	puthz(50+5,400+5,"返回",32,32,BLACK);
}

/************************************************/
/*页面：座位预约
  作者：dongyilei;
  功能：绘出座位预约的界面1，可以跳转到二楼三楼四楼的座位预约
  函数：reservation;
  		reservation_screen;
  页面跳转：after_login;
  			second_floor_reservation;
*/
#include"common.h"
#include"resv.h"
#include"LogTools.h"
/**********************************************************
函数：reservation
功能：实现已经预约座位和未预约作为的查看和选择座位
************************************************************/ 
int reservation(USER1 *p1,Link head)
{
	Link curr;
	curr=head->next;
	reservation_screen(head);
	while(curr!=NULL)//遍历链表找到存储当前用户信息的节点 
	{
		if(strcmp(curr->data.stuid,p1->study_id)==0)
		{
			break;
		}
		else 
		{
			curr=curr->next;
		}
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(460,125,615,190)==1)//点击二楼 
		{
			wr_user_info(head);
			cleardevice();
			clrmous(MouseX,MouseY);
			return 15;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
			
		}
		else if(mouse_press(460,200,630,270)==1)//点击三楼 
		{
			wr_user_info(head);
			cleardevice();
			clrmous(MouseX,MouseY);
			return 8;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(460,275,630,345)==1)//点击四楼 
		{
			wr_user_info(head);
			cleardevice();
			clrmous(MouseX,MouseY);
			return 13;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		} 
		else if(mouse_press(500,400,630,470)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 4;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
	}
	
}
/****************************************************************
函数：reservation_scrreen();
功能：画出图书馆的三层楼的平面图，显示剩余座位
*****************************************************************/ 
void reservation_screen(Link head)
{
	int i=48;
	int j=48;
	int k=48;
	char string1[10];
	char string2[10];
	char string3[10];
	Link p;
	int v1[]={230,395,175,395,175,195,200,195,220,160,365,160,395,195,415,195,415,395,370,395};
	int v2[]={200,480,245,375,245,275,225,275,225,255,370,255,370,275,355,275,355,375,405,480};
	p=head->next;
	while(p!=NULL)//计算剩余座位 
	{
		if(p->data.resv_floor==2)
		{
			if(p->data.seat_state==1)
			{
				i--;
				p=p->next;
				continue;
			} 
			else 
			{
				p=p->next;
			}
		}
		else if(p->data.resv_floor==3)
		{
			if(p->data.seat_state==1)
			{
				j--;
				p=p->next;
				continue;
			}
			else 
			{
				p=p->next;
			}
		}
		else if(p->data.resv_floor==4)
		{
			if(p->data.seat_state==1)
			{
				k--;
				p=p->next;
				continue;
			}
			else 
			{
				p=p->next;
			}
		}
		else if(p->data.resv_floor==0)
		{
			p=p->next;
			continue;
		}
		else 
		{
			break;
		}
	}
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setcolor(WHITE);
	rectangle(35,140,120,420);
	rectangle(460,125,630,195);
	rectangle(460,200,630,270);
	rectangle(460,275,630,345);
	drawpoly(10,v1);
	drawpoly(10,v2);
	rectangle(215,205,390,225);
	line(200,195,395,195);
	line(295,205,295,225);
	line(245,275,355,275);
	line(245,375,355,375);
	line(245,375,200,480);
	line(355,375,405,480);
	line(255,375,355,375);
	line(210,480,400,480);
	line(295,275,295,375);
	circle(285,325,5);
	circle(305,325,5); 
	puthz(205+5,50+5,"在线选座",48,48,WHITE);
	puthz(35+5,140+5,"东",48,48,WHITE);
	puthz(35+5,215+5,"图",48,48,WHITE);
	puthz(35+5,285+5,"书",48,48,WHITE);
	puthz(35+5,355+5,"馆",48,48,WHITE);
	puthz(460+5,125+2,"二楼",32,32,WHITE);
	puthz(460+5,159+2,"剩余座位",32,32,WHITE);
	settextstyle(1,0,2);
	itoa(i,string1,10);
	outtextxy(600,165,string1);
	puthz(460+5,200+1,"三楼",32,32,WHITE);
	puthz(460+5,238+1,"剩余座位",32,32,WHITE);
	itoa(j,string2,10);
	outtextxy(600,245,string2);
	puthz(460+5,275+1,"四楼",32,32,WHITE);
	puthz(460+5,310+1,"剩余座位",32,32,WHITE);
	itoa(k,string3,10);
	outtextxy(600,315,string3);
	setfillstyle(1,7);
	setcolor(BLACK);
	bar(500+1,400+1,630+1,470+1);
	rectangle(500,400,630,470);
	puthz(500+20,400+20,"返回",48,48,BLACK);
	
}

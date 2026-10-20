/**********************************************************
函数：psn_resv
功能：实现看看自己的选座情况，记录选择座位的座位号和楼层，并且可以进行签离
************************************************************/ 
#include"common.h"
#include"LogTools.h"
#include"psn_resv.h"
int psn_resv(USER1 *p1,Link head)
{
	Link p;
	p=head->next;
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
	psn_resv_screen(p1,head,p);
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(560,420,620,470)==1)//点击离开 
		{
			p1->seat_state=0;
			p->data.seat_state=0;
			p->data.resv_floor=0;
			strcpy(p->data.seat,"");
			wr_user_info(head);
			delay(200);
			cleardevice();
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			psn_resv_screen(p1,head,p);
			save_bk_mou(MouseX,MouseY); 
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(400,420,480,470)==1)//点击返回 
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			return 5;
			
		}
		
	}
	
	
}
void psn_resv_screen(USER1*p1,Link head,Link p)//画出个人预约界面的图 
{
	char string[10];
	int i;
	int j;
	int k;
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setcolor(GREEN);
	rectangle(40,100,600,400);
	setfillstyle(1,7);
	bar(40+2,100+2,600+2,400+2);
	bar(400,420,480,470);
	bar(560,420,630,470);
	setfillstyle(1,15);
	bar(40+10,100+10,600-10,400-10);
	puthz(150,30,"我的预约",48,48,WHITE);
	setcolor(BLACK);
	rectangle(400+2,420+2,480+2,470+2);
	rectangle(560+2,420+2,630+2,470+2);
	for(i=1;i<6;i++)
	{
		line(50,110+50*i,590,110+50*i);
	}
	puthz(400+5,420+5,"返回",32,32,BLACK);
	puthz(560+5,420+10,"签离",32,32,BLACK);
	setfillstyle(1,2);
	for(j=0;j<3;j++)
	{
		bar(60+200*i+2,120+2,160+200*i+2,150+2);
	}
	for(k=0;k<3;k++)
	{
		rectangle(60+200*i,120,160+200*i,150);
	}
	puthz(60+20,120+3,"学号",24,24,BLACK);
	puthz(60+15+200,120+3,"预约座位",24,24,BLACK);
	puthz(60+200*2+20,120+3,"状态",24,24,BLACK);
	setlinestyle(1,0,5);
	outtextxy(60+20,170,p1->study_id);
	if(p->data.seat_state==1)//判断座位的使用情况 
	{
		puthz(60+200*2+20,170,"使用中",24,24,BLACK);
		outtextxy(60+40+200,170,p->data.seat);
		itoa(p->data.resv_floor,string,10);
		settextstyle(1,0,2);
		outtextxy(60+40+160,170,string);
		puthz(60+40+175,175,"楼",16,16,BLACK);
	}
	else if(p->data.seat_state==0)
	{
		strcpy(p1->seat,'\0');
		puthz(60+200*2+20,170,"离开",24,24,BLACK);
		
	}
	else if(p->data.seat_state==2)
	{
		puthz(60+200*2+20,170,"未选座",24,24,BLACK);
	 } 

		
	
}

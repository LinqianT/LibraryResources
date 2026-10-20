/**********************************************/
/*页面：borrow_pay;
  作者：dongyilei;
  功能：实现借阅缴费的功能，将用户缴费的信息录入文件并计算出用户的余额以及欠费情况 
  头文件："borrow_pay.h"
  页面跳转：
  */ 
#include"common.h"
#include"data.h"
#include"bw_pay.h"
#include"LogTools.h"
int borrow_payment(USER1 *p1,Link head)
{
	Link p;
	int payment;
	int arrears;
	int balance;
	borrow_payment_screen();
	p=head->next;
	while(p!=NULL)
	{
		if(strcmp(p->data.stuid,p1->study_id)==0)//找到了该用户的节点进行修改信息 
		{
			break;
		}
		else 
		{
			p=p->next;
		}
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		settextstyle(2,0,8);
		outtextxy(265+5,155+2,p->data.balance);
		balance=atoi(p->data.balance);//余额 
		outtextxy(265+5,245+2,p->data.arrears);
		arrears=atoi(p->data.arrears);//欠费 
		if(mouse_press(265,335,520,370)==1)
		{
			input_inform(p1->payment,265,335,15,WHITE,220);
			setfillstyle(1,15);
			bar(265,155,520,200);
			bar(265,245,520,285);
			payment=atoi(p1->payment);
			if(arrears==0)
			{
				balance=payment+balance;
			 } 
			 else 
			 {
			 	balance=payment-arrears;
			 	if(balance<0)
			 	{
			 		arrears=arrears-payment;
			 		balance=0;
				}
				else 
				{
					
					balance=payment-arrears;
					arrears=0;
				}
			 }
			itoa(arrears,p1->arrears,10);
			itoa(balance,p1->balance,10);
			strcpy(p->data.balance,p1->balance);
			strcpy(p->data.arrears,p1->arrears);
			wr_user_info(head);
		}
		else if(mouse_press(540,385,630,450)==1)
		{
			cleardevice();
			save_bk_mou(MouseX,MouseY);
			clrmous(MouseX,MouseY);
			delay(100);
			return 6;
		}
		else if(mouse_press(540,40,630,95)==1)
		{
			cleardevice();
			save_bk_mou(MouseX,MouseY);
			clrmous(MouseX,MouseY);
			delay(100);
			return 6;
		}
	}
	
}
void borrow_payment_screen()
{
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setcolor(WHITE);
	rectangle(205,10,535,95);
	setfillstyle(1,15);
	bar(265,155,520,200);
	bar(265,245,520,285);
	bar(265,335,520,370);
	setcolor(BLACK);
	rectangle(540,385,630,450);
	rectangle(540,40,630,95);
	setfillstyle(1,7);
	bar(542,387,632,452);
	bar(542,42,632,97);
	puthz(205+40,10+20,"借阅缴费",48,48,WHITE);
	puthz(70+2,155+2,"我的余额",32,32,WHITE);
	puthz(115+2,245+2,"欠费",32,32,WHITE);
	puthz(115+2,335+2,"缴费",32,32,WHITE);
	puthz(540+10,385+10,"确定",32,32,WHITE);
	puthz(540+10,40+5,"返回",32,32,WHITE);
}

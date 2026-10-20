/********************************************************
函数：my_collection();
功能：查看用户自己收藏的书籍并且可以借阅，取消收藏
********************************************************/ 
#include"common.h"
#include"my_col.h"
#include"LogTools.h"
#include"res_plat.h"
int my_collection(USER1*p1,Link head,BLink bhead)
{
	int i,j,k,s;
	Link p;
	BLink curr;
	int result=0;
	p=head->next;
	curr=bhead->next;
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
	collection_screen(p);
	delay(200);
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(580,400,635,440)==1)
		{
			cleardevice();
			save_bk_mou(MouseX,MouseY);
			clrmous(MouseX,MouseY);
			return 5;
		}
		else if(mouse_press(45,270,180,300)==1)//借阅收藏的第一本书 
		{
			result=add_page();
			i=judge_borrow_room(p);
			j=judge_borrow_book(curr,bhead);
			if(result==0)
			{
				save_bk_mou(MouseX,MouseY);
				clrmous(MouseX,MouseY);
				collection_screen(p);
			}
			else if(result==1)
			{
				i=judge_borrow_room(p);
				if(i==0)
				{
					puthz(50,400,"借阅数目已达上限！",24,24,WHITE);
				}
				else if(i==1)
				{
					strcpy(p->data.borrow_book1,p->data.collect_book1);//用户没有借书，这是他借的第一本书 
					get_time(p->data.borrow_time1);
					p->data.borrow_state=1;
					wr_user_info(head);
					save_bk_mou(MouseX,MouseY);
					clrmous(MouseX,MouseY);
					drawpage_scborrow();
					delay(500);	
				}
				else if(i==2)
				{
					strcpy(p->data.borrow_book2,p->data.collect_book1);//用户借阅的第二本书 
					get_time(p->data.borrow_time2);
					p->data.borrow_state=1;
					wr_user_info(head);
					save_bk_mou(MouseX,MouseY);
					clrmous(MouseX,MouseY);
					drawpage_scborrow();
					delay(500);		
				}
				else if(i==3)
				{
					strcpy(p->data.borrow_book3,p->data.collect_book1);//用户借阅的第三本书 
					get_time(p->data.borrow_time3);
					p->data.borrow_state=1;
					wr_user_info(head);
					clrmous(MouseX,MouseY);
					save_bk_mou(MouseX,MouseY);
					drawpage_scborrow();
					delay(500);		
				}
				if((j==1)&&(i!=0))//点击借阅，该本书的借阅次数加一 
				{
					curr->data.borrow_times++;
					wr_book_info(bhead);
				}
				save_bk_mou(MouseX,MouseY);
				clrmous(MouseX,MouseY);
				collection_screen(p);
			}
			else if(result==2)//取消收藏 
			{
			
				strcpy(p->data.collect_book1,"");
				wr_user_info(head);
				save_bk_mou(MouseX,MouseY);
				clrmous(MouseX,MouseY);
				collection_screen_new(p,head);
			}
			
		}
		else if(mouse_press(45+210,270,45+210+140,300)==1)//借阅收藏的第二本书 
		{
			delay(200);
			save_bk_mou(MouseX,MouseY);
			clrmous(MouseX,MouseY);
			result=add_page();
			i=judge_borrow_room(p);
			j=judge_borrow_book(curr,bhead);
			if(result==0)
			{
				save_bk_mou(MouseX,MouseY);
				clrmous(MouseX,MouseY);
				collection_screen(p);
			}
			else if(result==1)
			{
				if(i==0)
				{
					puthz(50,400,"借阅数目已达上限！",24,24,WHITE);
				}
				else if(i==1)
				{
					strcpy(p->data.borrow_book1,p->data.collect_book2);
					get_time(p->data.borrow_time1);
					p->data.borrow_state=1;
					wr_user_info(head);
					save_bk_mou(MouseX,MouseY);
					clrmous(MouseX,MouseY);
					drawpage_scborrow();
					delay(500);		
				}
				else if(i==2)
				{
					strcpy(p->data.borrow_book2,p->data.collect_book2);
					get_time(p->data.borrow_time2);
					p->data.borrow_state=1;
					wr_user_info(head);
					save_bk_mou(MouseX,MouseY);
					clrmous(MouseX,MouseY);
					drawpage_scborrow();
					delay(500);	
				}
				else if(i==3)
				{
					strcpy(p->data.borrow_book3,p->data.collect_book2);
					get_time(p->data.borrow_time3);
					p->data.borrow_state=1;
					wr_user_info(head);
					save_bk_mou(MouseX,MouseY);
					clrmous(MouseX,MouseY);
					drawpage_scborrow();
					delay(500);	
				}
				if((j==2)&&(i!=0))
				{
					curr->data.borrow_times++;
					wr_book_info(bhead);
				}
				save_bk_mou(MouseX,MouseY);
				clrmous(MouseX,MouseY);
				collection_screen(p);
			}
			else if(result==2)//取消收藏 
			{
			
				strcpy(p->data.collect_book2,"");
				wr_user_info(head);
				clrmous(MouseX,MouseY);
				save_bk_mou(MouseX,MouseY);
				collection_screen_new(p,head);
			}
		}
		else if(mouse_press(45+210*2,270,45+210*2+140,300)==1)//借阅收藏的第三本书 
		{
			result=add_page();
			i=judge_borrow_room(p);
			j=judge_borrow_book(curr,bhead);
			if(result==0)
			{
				save_bk_mou(MouseX,MouseY);
				clrmous(MouseX,MouseY);
				collection_screen_new(p,head);
			}
			else if(result==1)
			{
				if(i==0)
				{
					puthz(50,400,"借阅数目已达上限！",24,24,WHITE);
				}
				else if(i==1)
				{
					strcpy(p->data.borrow_book1,p->data.collect_book3);
					get_time(p->data.borrow_time1);
					p->data.borrow_state=1;
					wr_user_info(head);
					save_bk_mou(MouseX,MouseY);
					clrmous(MouseX,MouseY);
					drawpage_scborrow();
					delay(500);
		
				}
				else if(i==2)
				{
					strcpy(p->data.borrow_book2,p->data.collect_book3);
					get_time(p->data.borrow_time2);
					p->data.borrow_state=1;
					wr_user_info(head);	
					save_bk_mou(MouseX,MouseY);
					clrmous(MouseX,MouseY);
					drawpage_scborrow();
					delay(500);
		
				}
				else if(i==3)
				{
					strcpy(p->data.borrow_book3,p->data.collect_book3);
					get_time(p->data.borrow_time3);
					p->data.borrow_state=1;
					wr_user_info(head);
					save_bk_mou(MouseX,MouseY);
					clrmous(MouseX,MouseY);
					drawpage_scborrow();
					delay(500);
	
				}
				if((j==3)&&(i!=0))
				{
					curr->data.borrow_times++;
					wr_book_info(bhead);
				}
				save_bk_mou(MouseX,MouseY);
				clrmous(MouseX,MouseY);
				collection_screen(p);
			}
			else if(result==2)//取消收藏 
			{
			
				strcpy(p->data.collect_book3,"");
				wr_user_info(head);
				save_bk_mou(MouseX,MouseY);
				clrmous(MouseX,MouseY);
			    collection_screen_new(p,head);
			}
		}
	}
}
void collection_screen(Link p)//画出收藏的界面 
{
	int i;
	int v1[]={50,150,25,150,25,250,125,250,205,250,205,150,180,150};
	int v2[]={125,150,50,100,50,225,125,250,180,225,180,100,125,150};
	int v3[]={50+205,150,25+205,150,25+205,250,125+205,250,205+205,250,205+205,150,180+205,150};
	int v4[]={50+205*2,150,25+205*2,150,25+205*2,250,125+205*2,250,205+205*2,250,205+205*2,150,180+205*2,150};
	int v5[]={125+205,150,50+205,100,50+205,225,125+205,250,180+205,225,180+205,100,125+205,150};
	int v6[]={125+205*2,150,50+205*2,100,50+205*2,225,125+205*2,250,180+205*2,225,180+205*2,100,125+205*2,150};
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setfillstyle(1,15);
	bar(20,80,630,370);
	for(i=0;i<3;i++)
	{
		setcolor(BLACK);
		line(125+205*i,150,125+205*i,250);
	}
	drawpoly(7,v1);
	drawpoly(7,v2);
	drawpoly(7,v3);
	drawpoly(7,v4);
	drawpoly(7,v5);
	drawpoly(7,v6);
	settextstyle(1,0,2);
	puthz(45,270,p->data.collect_book1,16,16,BLACK);
	puthz(50+210,270,p->data.collect_book2,16,16,BLACK);
	puthz(50+205*2+5,270,p->data.collect_book3,16,16,BLACK);
	setcolor(BLACK);
	rectangle(580,400,635,440);
	setfillstyle(1,7);
	bar(580+2,400+2,635+2,440+2);
	puthz(580+3,400+10,"返回",24,24,BLACK);
}
int add_page()//弹出功能选项界面 
{
	setfillstyle(1,8);
	bar(150,100,500,300);
	setfillstyle(1,7);
	bar(200+2,150+2,300+2,200+2);
	bar(350+2,150+2,450+2,200+2); 
	bar(300+2,220+2,350+2,260+2);
	setcolor(BLACK);
	rectangle(200,150,300,200);
	rectangle(350,150,450,200);
	rectangle(300,220,350,260);
	puthz(200+10,150+10,"确认借阅",24,24,BLACK);
	puthz(350+10,150+10,"取消收藏",24,24,BLACK);
	puthz(300+3,220+4,"返回",24,24,BLACK);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(200,150,300,200)==1)
		{
			
			return 1;
		}
		else if(mouse_press(350,150,450,200)==1)
		{
			return 2;
		}
		else if(mouse_press(300,220,350,260)==1)
		{
			return 0;
		}
	}
	
}
void collection_screen_new(Link p,Link head)//完成选择后重新画图 
{
	Link curr;
	int i;
	int a;
	int b;
	int c;
	int v1[]={50,150,25,150,25,250,125,250,205,250,205,150,180,150};
	int v2[]={125,150,50,100,50,225,125,250,180,225,180,100,125,150};
	int v3[]={50+205,150,25+205,150,25+205,250,125+205,250,205+205,250,205+205,150,180+205,150};
	int v4[]={50+205*2,150,25+205*2,150,25+205*2,250,125+205*2,250,205+205*2,250,205+205*2,150,180+205*2,150};
	int v5[]={125+205,150,50+205,100,50+205,225,125+205,250,180+205,225,180+205,100,125+205,150};
	int v6[]={125+205*2,150,50+205*2,100,50+205*2,225,125+205*2,250,180+205*2,225,180+205*2,100,125+205*2,150};
	delay(500);
	curr=head->next;
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setfillstyle(1,15);
	bar(20,80,630,370);
	for(i=0;i<3;i++)
	{
		setcolor(BLACK);
		line(125+205*i,150,125+205*i,250);
	}
	drawpoly(7,v1);
	drawpoly(7,v2);
	drawpoly(7,v3);
	drawpoly(7,v4);
	drawpoly(7,v5);
	drawpoly(7,v6);
	settextstyle(1,0,2);
	setcolor(BLACK);
	rectangle(580,400,635,440);
	setfillstyle(1,7);
	bar(580+2,400+2,635+2,440+2);
	puthz(580+3,400+10,"返回",24,24,BLACK);
	//进行排序操作，如果已经存在取消收藏的书籍的话，把顺序变一下
	if(strcmp(p->data.collect_book1,"")==0)
	{
		a=0;
	}
	else 
	{
		a=1;
	}
	if(strcmp(p->data.collect_book2,"")==0)
	{
		b=0;
	}
	else 
	{
		b=1;
	}
	if(strcmp(p->data.collect_book3,"")==0)
	{
		c=0;
	}
	else 
	{
		c=1;
	}
	if(a==0&&b==1&&c==0)
	{
		strcpy(p->data.collect_book1,p->data.collect_book2);
		strcpy(p->data.collect_book2,"");
		wr_user_info(head);
	}
	else if(a==0&&b==1&&c==1)
	{
		strcpy(p->data.collect_book1,p->data.collect_book2);
		strcpy(p->data.collect_book2,p->data.collect_book3);
		strcpy(p->data.collect_book3,"");
		wr_user_info(head);
	}
	else if(a==1&&b==0&&c==1)
	{
		strcpy(p->data.collect_book2,p->data.collect_book3);
		strcpy(p->data.collect_book3,"");
		wr_user_info(head);
	}
		puthz(45,270,p->data.collect_book1,16,16,BLACK);
		puthz(45+210,270,p->data.collect_book2,16,16,BLACK);
		puthz(45+210*2,270,p->data.collect_book3,16,16,BLACK);
}
int judge_borrow_room(Link p)
{
	if(strcmp(p->data.borrow_book1,"")!=0)
	{
		if(strcmp(p->data.borrow_book2,"")!=0)
		{
			if(strcmp(p->data.borrow_book3,"")!=0)
			{
				return 0;
			}
			else 
			{
				return 3;
			}
		}
		else
		{
			return 2;
		}
	}
	else 
	{
		return 1;
	}			
}
int judge_borrow_book(BLink curr,Link p)//判断是否借书 
{

	while(curr!=NULL)
	{
		if(strcmp(curr->data.title,p->data.collect_book1)==0)
		{
			return 1;
		}
		else if(strcmp(curr->data.title,p->data.collect_book2)==0)
		{
			return 2;
		}
		else if(strcmp(curr->data.title,p->data.collect_book3)==0)
		{
			return 3;
		}
		else 
		{
			curr=curr->next;
		}
	}
	
}

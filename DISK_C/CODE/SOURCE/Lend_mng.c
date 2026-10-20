#include"common.h"
#include"Lend_mng.h"
int lending_mng(Link head,BLink bhead)
{
//	Excel_data excel;
	clrmous(MouseX,MouseY); 
	delay(100);
	Draw_lendmain();
	save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标

	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(540,10,630,40)==2||mouse_press(10,10,110,40)==2||mouse_press(120,10,220,40)==2||mouse_press(230,10,330,40)==2)//返回、未点击 
		{
			MouseS=1;
			continue;
		}
		else if(mouse_press(540,10,630,40)==1)//返回、点击
		{
			return 24;
		}
		else if(mouse_press(240,420,300,445)==2||mouse_press(310,420,370,445)==2)//上一页下一页、未点击 
		{
			MouseS=1;
			continue;
		}
		else if(mouse_press(10,10,110,40)==1)
		{
			clrmous(MouseX,MouseY); 
			delay(100);
			Draw_lendlist(head,bhead);
			save_bk_mou(MouseX,MouseY);//存取鼠标背景
			drawmous(MouseX,MouseY);//画鼠标
		}
		else if(mouse_press(120,10,220,40)==1)
		{
			clrmous(MouseX,MouseY); 
			delay(100);
			out_ranklist(head,bhead);
			save_bk_mou(MouseX,MouseY);//存取鼠标背景
			drawmous(MouseX,MouseY);//画鼠标
		}
		else if(mouse_press(230,10,330,40)==1)
		{
			clrmous(MouseX,MouseY); 
			delay(100);
			Draw_liushui(head);
			save_bk_mou(MouseX,MouseY);//存取鼠标背景
			drawmous(MouseX,MouseY);//画鼠标
		}
		
		else //无操作 
		{
			MouseS=0;
			continue;
		}
	} 
}

/**************************************************
函数：Draw_lendlist
作用：借阅界面画图
输入：
输出：
**************************************************/
void Draw_lendmain() 
{
	cleardevice();
	setfillstyle(1,BLUE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(542,12,632,42);
	bar(542,12,632,42);
	bar(12,12,112,42);
	bar(122,12,222,42);
	bar(232,12,332,42);
	setfillstyle(1,WHITE); 
	bar(540,10,630,40);
	bar(10,10,110,40);
	bar(120,10,220,40);
	bar(230,10,330,40);
	puthz(560,17,"返回",24,24,BLACK); 
	puthz(12,17,"借阅清单",24,24,BLACK); 
	puthz(122,17,"借阅榜单",24,24,BLACK); 
	puthz(232,17,"借阅流水",24,24,BLACK); 
}

/**************************************************
函数：
作用：显示借阅清单 
输入：
输出：
**************************************************/
void Draw_lendlist(Link head,BLink bhead)
{
	int page=1,count=0;
	int line_y,i=0,j=0; 
	Link curr;
	Link temp[26];
	curr=head->next;
	while(curr!=NULL)
	{
		if(strcmp(curr->data.borrow_book1,"")!=0)
		{
			temp[j]=curr;
			j++;
			count=j;
		}
		if(strcmp(curr->data.borrow_book2,"")!=0)
		{
			temp[j]=curr;
			j++;
			count=j;
		}
		if(strcmp(curr->data.borrow_book3,"")!=0)
		{
			temp[j]=curr;
			j++;
			count=j;
		}
		curr=curr->next;
	}
	setfillstyle(1,BLACK);
	bar(10,10,110,40);
	puthz(12,17,"借阅清单",24,24,WHITE);
	setfillstyle(1,WHITE);
	bar(120,10,220,40);
	puthz(122,17,"借阅榜单",24,24,BLACK);
	setfillstyle(1,WHITE);
	bar(230,10,330,40);
	puthz(232,17,"借阅流水",24,24,BLACK);
	
	setfillstyle(1,WHITE);
	bar(10,50,630,470);
	puthz(15,56,"学号",16,16,LIGHTGRAY);
	puthz(120,56,"姓名",16,16,LIGHTGRAY); 
	puthz(250,56,"借阅书籍",16,16,LIGHTGRAY);
	puthz(420,56,"借阅时间",16,16,LIGHTGRAY);
	//puthz(550,56,"归还状态",16,16,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	for(line_y=73;line_y<417;)
	{
		line(15,line_y,625,line_y);
		line_y+=25;
	} 
	setfillstyle(1,LIGHTGRAY);
	bar(242,422,302,447);
	bar(312,422,372,447);
	setcolor(BLACK);
	rectangle(240,420,300,445);
	rectangle(310,420,370,445);
	puthz(247,427,"上一页",16,16,BLACK);
	puthz(317,427,"下一页",16,16,BLACK);
	//借阅人、书籍、时间 
	//如果时间不为空，sort by time 
	curr=head->next;
	out_ulendtime(temp,&page,count);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(540,10,630,40)==2||mouse_press(10,10,110,40)==2||mouse_press(120,10,220,40)==2||mouse_press(230,10,330,40)==2)//返回、未点击 
		{
			MouseS=1;
			continue;
		}
		else if(mouse_press(240,420,300,445)==2||mouse_press(310,420,370,445)==2)//上一页下一页、未点击 
		{
			MouseS=1;
			continue;
		}
		else if(mouse_press(540,10,630,40)==1)//返回、点击
		{
			return 24;
		}
		else if(mouse_press(240,420,300,445)==1)//上一页 
		{
            if(page<=1)
            {
                continue;
            }
            else if(page>1)
            {
            	delay(300);
            	page--;
				out_ulendtime(temp,&page,count);
            	continue;
            }
		}
		else if(mouse_press(310,420,370,445)==1)//下一页 
		{
			if(count%13 != 0) 
			{
				if(page >= count/13+1)
				{
					continue;
				}
				else if(page < count/13+1)
				{
					delay(100);
					page++;
					out_ulendtime(temp,&page,count);
					continue;
				}
			}
			else if(count%13 == 0)
			{
				if(page >= count/13)
				{
					continue;
				}
				else if(page < count/13)
				{
					delay(100);
					page++;
					out_ulendtime(temp,&page,count);
					continue;
				}
			}
		}
		else if(mouse_press(120,10,220,40)==1)
		{
			clrmous(MouseX,MouseY); 
			break; 
			out_ranklist(head,bhead);
			
		}
		else if(mouse_press(230,10,330,40)==1)
		{
			clrmous(MouseX,MouseY); 
			break;
			Draw_liushui(head);
		}
		else
		{
			MouseS=0;
			continue;
		}
	}
	
}
/**************************************************
函数：out_ranklist
作用：显示借阅榜单 
输入：bhead
输出：
**************************************************/
void out_ranklist(Link head,BLink bhead)
{
	int i,j,count=0,page=1;
	int line_y; 
	BLink node;
	setfillstyle(1,BLACK);
	bar(120,10,220,40);
	puthz(122,17,"借阅榜单",24,24,WHITE);
	setfillstyle(1,WHITE);
	bar(10,10,110,40);
	puthz(12,17,"借阅清单",24,24,BLACK);
	setfillstyle(1,WHITE);
	bar(230,10,330,40);
	puthz(232,17,"借阅流水",24,24,BLACK);
	bar(10,50,630,470);
	puthz(15,56,"排名",16,16,LIGHTGRAY);
	puthz(100,56,"编号",16,16,LIGHTGRAY); 
	puthz(170,56,"书名",16,16,LIGHTGRAY);
	puthz(350,56,"作者",16,16,LIGHTGRAY);
	puthz(550,56,"借阅次数",16,16,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	for(line_y=73;line_y<417;)
	{
		line(15,line_y,625,line_y);
		line_y+=25;
	} 
	setfillstyle(1,LIGHTGRAY);
	bar(242,422,302,447);
	bar(312,422,372,447);
	setcolor(BLACK);
	rectangle(240,420,300,445);
	rectangle(310,420,370,445);
	puthz(247,427,"上一页",16,16,BLACK);
	puthz(317,427,"下一页",16,16,BLACK);
	node=bhead->next;
	while(node!=NULL)
	{
		count++;
		node=node->next;
	}
	
	sortbylend(bhead);
	out_binfbylend(bhead,&page);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(540,10,630,40)==2||mouse_press(10,10,110,40)==2||mouse_press(120,10,220,40)==2||mouse_press(230,10,330,40)==2)//返回、未点击 
		{
			MouseS=1;
			continue;
		}
		else if(mouse_press(240,420,300,445)==2||mouse_press(310,420,370,445)==2)//上一页下一页、未点击 
		{
			MouseS=1;
			continue;
		}
		else if(mouse_press(540,10,630,40)==1)//返回、点击
		{
			return 24;
		}
		else if(mouse_press(240,420,300,445)==1)//上一页 
		{
            if(page<=1)
            {
                continue;
            }
            else if(page>1)
            {
            	delay(300);
            	page--;
				out_binfbylend(bhead,&page);
            	continue;
            }
		}
		else if(mouse_press(310,420,370,445)==1)//下一页 
		{
			if(count%13 != 0) 
			{
				if(page >= count/13+1)
				{
					continue;
				}
				else if(page < count/13+1)
				{
					delay(100);
					page++;
					out_binfbylend(bhead,&page);
					continue;
				}
			}
			else if(count%13 == 0)
			{
				if(page >= count/13)
				{
					continue;
				}
				else if(page < count/13)
				{
					delay(100);
					page++;
					out_binfbylend(bhead,&page);
					continue;
				}
			}
		}
		else if(mouse_press(10,10,110,40)==1)
		{
			clrmous(MouseX,MouseY); 
			break;
			Draw_lendlist(head,bhead);
		}
		else if(mouse_press(230,10,330,40)==1)
		{
			clrmous(MouseX,MouseY); 
			break;
			Draw_liushui(head);
		}
		else
		{
			MouseS=0;
			continue;
		}
	}
	sortbybkid(bhead); 
} 
/**************************************************
函数： Draw_liushui
作用：显示借阅流水（每日借阅量） 
输入：head 
输出： 
**************************************************/
void Draw_liushui(Link head)
{
	Excel_data arr[20];
	Link curr; 
	char temp[5];
	int i=-1,j=0;
	int sx[]={600-20,440-20+5,600-20+10,440-20,600-20,440-20-5,600-20,440-20+5};
	int sy[]={40+20-5,70+20,40+20,70+20-10,40+20+5,70+20,40+20-5,70+20};
	initexcel(arr);
	setfillstyle(1,BLACK);
	bar(230,10,330,40);
	puthz(232,17,"借阅流水",24,24,WHITE);
	setfillstyle(1,WHITE);
	bar(10,10,110,40);
	puthz(12,17,"借阅清单",24,24,BLACK);
	setfillstyle(1,WHITE);
	bar(120,10,220,40);
	puthz(122,17,"借阅榜单",24,24,BLACK);
	bar(10,50,630,470);
	//坐标轴 
	setcolor(BLACK);
	line(40+20,440-20,600-20,440-20);
	line(40+20,441-20,600-20,441-20);
	line(40+20,440-20,40+20,70+20); 
	line(41+20,440-20,41+20,70+20); 
	//箭头
	setfillstyle(1,BLACK);
	fillpoly(3,sx);
	fillpoly(3,sy);
	puthz(600-20,440-15,"日期",16,16,BLACK);
	puthz(40,70,"借",16,16,BLACK);
	puthz(40,70+18,"阅",16,16,BLACK);
	puthz(40,70+36,"量",16,16,BLACK);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	curr=head->next;
	while(curr!=NULL)
	{
		if(strcmp(curr->data.borrow_book1,"")!=0)
		{
			if(strcmp(arr[i].time,curr->data.borrow_time1)==0)
			{
				arr[i].count++;
				if(strcmp(curr->data.borrow_book2,"")!=0)
				{
					if(strcmp(arr[i].time,curr->data.borrow_time2)==0)
					{
						arr[i].count++;
						if(strcmp(curr->data.borrow_book3,"")!=0)
						{
							if(strcmp(arr[i].time,curr->data.borrow_time3)==0)
							{
								arr[i].count++;
							}
							else
							{
								i++;
								strcpy(arr[i].time,curr->data.borrow_time1);
								arr[i].count++;
							}
						}
					}
					else
					{
						i++;
						strcpy(arr[i].time,curr->data.borrow_time1);
						arr[i].count++;
						if(strcmp(curr->data.borrow_book3,"")!=0)
						{
							if(strcmp(arr[i].time,curr->data.borrow_time3)==0)
							{
								arr[i].count++;
							}
							else
							{
								i++;
								strcpy(arr[i].time,curr->data.borrow_time1);
								arr[i].count++;
							}
						}
					}
				}
			}
			else
			{
				i++;
				strcpy(arr[i].time,curr->data.borrow_time1);
				arr[i].count++;
				if(strcmp(curr->data.borrow_book2,"")!=0)
				{
					if(strcmp(arr[i].time,curr->data.borrow_time2)==0)
					{
						arr[i].count++;
						if(strcmp(curr->data.borrow_book3,"")!=0)
						{
							if(strcmp(arr[i].time,curr->data.borrow_time3)==0)
							{
								arr[i].count++;
							}
							else
							{
								i++;
								strcpy(arr[i].time,curr->data.borrow_time1);
								arr[i].count++;
							}
						}
					}
					else
					{
						i++;
						strcpy(arr[i].time,curr->data.borrow_time1);
						arr[i].count++;
						if(strcmp(curr->data.borrow_book3,"")!=0)
						{
							if(strcmp(arr[i].time,curr->data.borrow_time3)==0)
							{
								arr[i].count++;
							}
							else
							{
								i++;
								strcpy(arr[i].time,curr->data.borrow_time1);
								arr[i].count++;
							}
						}
					}
				}
			}
			curr=curr->next;
		}
		else
		{
			curr=curr->next;
		}
	}
	//x单位100，y单位20 
	for(j=0;j<=i;j++)
	{
		setfillstyle(1,BLACK);
		fillellipse(60-50+100*(j+1),420-20*arr[j].count,2,2);
		itoa(arr[j].count,temp,10);
		outtextxy(58-50+100*(j+1),400-20*arr[j].count,temp);
		outtextxy(35-50+100*(j+1),440-20,arr[j].time);
		if(j>=1)
		{
			line(60-50+100*(j),420-20*arr[j-1].count,60-50+100*(j+1),420-20*arr[j].count);
			line(60-50+100*(j),421-20*arr[j-1].count,60-50+100*(j+1),421-20*arr[j].count);
			line(60-50+100*(j),419-20*arr[j-1].count,60-50+100*(j+1),419-20*arr[j].count);
		}
	}
} 

void initexcel(Excel_data arr[])
{
	int i=0;
	for(i=0;i<20;i++)
	{
		arr[i].count=0;
		arr[i].time[0]='\0';
	}	
}
/**************************************************
函数：sortbylend
作用：按照借阅次数排序 
输入：bhead
输出：
**************************************************/
void sortbylend(BLink bhead)
{
	int swapped;
    BLink p,q,temp;
    BLink tail = NULL;

    // 如果链表为空或只有一个节点，无需排序
    if (bhead->next == NULL || bhead->next->next == NULL) 
	{
        return;
    }

    do{
        swapped = 0;
        p = bhead->next;
		q=p->next;
        while (p->next != tail) 
		{
            if (p->data.borrow_times < p->next->data.borrow_times) 
			{
                // 交换节点
                temp->data = p->data;
                p->data = q->data;
                q->data = temp->data;
                swapped = 1;
            }
            p = p->next;
            q=q->next;
        }
        tail = p;
    }while (swapped);

}
/**************************************************
函数：sortbybkid
作用：按照书籍编号排序 
输入：bhead
输出：
**************************************************/
void sortbybkid(BLink bhead)
{
	int swapped;
    BLink p,q,temp;
    BLink tail = NULL;

    // 如果链表为空或只有一个节点，无需排序
    if (bhead->next == NULL || bhead->next->next == NULL) 
	{
        return;
    }

    do{
        swapped = 0;
        p = bhead->next;
		q=p->next;
        while (p->next != tail) 
		{
            if (strcmp(p->data.bkid, p->next->data.bkid) > 0) 
			{
                // 交换节点
                temp->data = p->data;
                p->data = q->data;
                q->data = temp->data;
                swapped = 1;
            }
            p = p->next;
            q=q->next;
        }
        tail = p;
    }while (swapped);
}
/**********************************
函数：out_binfbylend
作用：按照借阅次数顺序输出书籍信息 
输入：bhead
	  page 
输出：
**********************************/
void out_binfbylend(BLink bhead,int *page)
{
	int ys=0,i=0,line_y=75;
	int y=75,count=0;
	int rank=1;
	char y0[4];
	char temp[5]={'\0'};
	char srank[5];
	BLink curr,node;	
	curr=bhead->next;
	ys=(*page);
	
	while(curr!=NULL)
	{
		curr=curr->next;
		count++;
	}
	setfillstyle(1,WHITE);
	bar(598,448,630,470);
	itoa(ys,y0,10);
	setcolor(BLACK);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(600,450,y0);
    node=bhead->next;
    if(count%13 == 0)//刚好整除 
	{
		if(ys > count/13) 
		{
			return;
 		}
		else if(ys <= count/13) 
		{
			setfillstyle(1,WHITE);
			bar(10,75,630,417);
			setcolor(LIGHTGRAY);
			for(line_y=73;line_y<417;)
			{
				line(15,line_y,625,line_y);
				line_y+=25;
			} 
			setcolor(BLACK);
			settextstyle(SMALL_FONT,HORIZ_DIR,7);
			for(i=0;i<(ys-1)*13;i++)
			{
				node=node->next;
			}
			for(i=0;i<13;i++)
			{
				outtextxy(100,y,node->data.bkid);
				puthz(170,y,node->data.title,16,16,BLACK);
				puthz(350,y,node->data.author,16,16,BLACK);
				itoa(node->data.borrow_times,temp,10);
				outtextxy(550,y,temp);
				strcpy(temp,'\0');
				node=node->next;
				y+=25;
			}
		}
	}
	else//有余数 
	{
		if(ys > count/13+1)//大于最后一页 
		{
			return;
		}
		else if(ys == count/13+1)//等于最后一页 
		{
			setfillstyle(1,WHITE);
			bar(10,75,630,417);
			setcolor(LIGHTGRAY);
			for(line_y=73;line_y<417;)
			{
				line(15,line_y,625,line_y);
				line_y+=25;
			} 
			setcolor(BLACK);
			settextstyle(SMALL_FONT,HORIZ_DIR,7);
			for(i=0;i<(ys-1)*13;i++)
			{
				node=node->next;
			}
			for(i=0;i<count%13;i++)
			{
				outtextxy(100,y,node->data.bkid);
				puthz(170,y,node->data.title,16,16,BLACK);
				puthz(350,y,node->data.author,16,16,BLACK);
				itoa(node->data.borrow_times,temp,10);
				outtextxy(550,y,temp);
				strcpy(temp,'\0');
				node=node->next;
				y+=25;
			}
		}
		else if(ys < count/13+1)//小于最后一页 
		{
			for(i=0;i<(ys-1)*13;i++)
			{
				node=node->next;
			}			
			setfillstyle(1,WHITE);
			bar(10,75,630,417);
			setcolor(LIGHTGRAY);
			for(line_y=73;line_y<417;)
			{
				line(15,line_y,625,line_y);
				line_y+=25;
			} 
			setcolor(BLACK);
			settextstyle(SMALL_FONT,HORIZ_DIR,7);
			for(i=0;i<13;i++)
			{
				outtextxy(100,y,node->data.bkid);
				puthz(170,y,node->data.title,16,16,BLACK);
				puthz(350,y,node->data.author,16,16,BLACK);
				itoa(node->data.borrow_times,temp,10);
				outtextxy(550,y,temp);
				strcpy(temp,'\0');
				node=node->next;
				y+=25;
			}
		}
	}
	
	if(count%13==0)
	{
		for(i=0,rank=1;i<(ys-1)*13;i++)
		{
			rank++;
		}
		for(i=0,y=75;i<13;i++,y+=25)
		{
			itoa(rank,srank,10);
			outtextxy(15,y,srank);
			rank++;
		}
	}
	else
	{
		if(ys < count/13+1)
		{
			for(i=0,rank=1;i<(ys-1)*13;i++)
			{
				rank++;
			}
			for(i=0,y=75;i<13;i++,y+=25)
			{
				itoa(rank,srank,10);
				outtextxy(15,y,srank);
				rank++;
			}
		}
		else if(ys == count/13+1)
		{
			for(i=0,rank=1;i<(ys-1)*13;i++)
			{
				rank++;
			}
			for(i=0,y=75;i < count%13;i++,y+=25)
			{
				itoa(rank,srank,10);
				outtextxy(15,y,srank);
				rank++;
			}
		}
	}
}  
/**********************************
函数：out_ulendtime
作用：输出借阅书籍的用户及借阅信息 
输入：
输出：
**********************************/
void out_ulendtime(Link temp[],int *page,int count)
{
	int ys=0,i=0,j=0,line_y=75;
	int y=75,curbook=0;
	char y0[4];
	ys=(*page);
	setfillstyle(1,WHITE);
	bar(598,448,630,470);
	itoa(ys,y0,10);
	setcolor(BLACK);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(600,450,y0);

    if(count%13 == 0)//刚好整除 
	{
		if(ys > count/13) 
		{
			return;
 		}
		else if(ys <= count/13) 
		{
			setfillstyle(1,WHITE);
			bar(10,75,630,417);
			setcolor(LIGHTGRAY);
			for(line_y=73;line_y<417;)
			{
				line(15,line_y,625,line_y);
				line_y+=25;
			} 
			setcolor(BLACK);
			settextstyle(SMALL_FONT,HORIZ_DIR,7);
			for(i=0;i<(ys-1)*13;i++)
			{
				j=i;
			}
			for(i=0;i<13;i++)
			{
				outtextxy(15,y,temp[j]->data.stuid);
				puthz(120,y,temp[j]->data.name,16,16,BLACK);
				
				if(strcmp(temp[j]->data.stuid,temp[j+2]->data.stuid)==0)//三本书的第一本 
				{
					curbook=1; 
				}
				else if(strcmp(temp[j]->data.stuid,temp[j+1]->data.stuid)==0)//两本书的第一本
				{
					curbook=1;
				} 
				else if(strcmp(temp[j]->data.stuid,temp[j+1]->data.stuid)!=0) //一本书 
				{
					curbook=1; 
				}
				
				if(j>=1 && strcmp(temp[j-1]->data.stuid,temp[j+1]->data.stuid)==0) 
				{
					curbook=2;
				}
				else if(j>=1 && strcmp(temp[j-1]->data.stuid,temp[j]->data.stuid)==0)
				{
					curbook=2;
				}
				if(j>=2 && strcmp(temp[j-2]->data.stuid,temp[j]->data.stuid)==0)
				{
					curbook=3;
				}
				
				if(curbook==1)
				{
					puthz(250,y,temp[j]->data.borrow_book1,16,16,BLACK);
					outtextxy(420,y,temp[j]->data.borrow_time1);
				}
				else if(curbook==2)
				{
					puthz(250,y,temp[j]->data.borrow_book2,16,16,BLACK);
					outtextxy(420,y,temp[j]->data.borrow_time2);
				}
				else if(curbook==3)
				{
					puthz(250,y,temp[j]->data.borrow_book3,16,16,BLACK);
					outtextxy(420,y,temp[j]->data.borrow_time3);
				}
				j++;
				y+=25;
			}
		}
	}
	else//有余数 
	{
		if(ys > count/13+1)//大于最后一页 
		{
			return;
		}
		else if(ys == count/13+1)//等于最后一页 
		{
			setfillstyle(1,WHITE);
			bar(10,75,630,417);
			setcolor(LIGHTGRAY);
			for(line_y=73;line_y<417;)
			{
				line(15,line_y,625,line_y);
				line_y+=25;
			} 
			setcolor(BLACK);
			settextstyle(SMALL_FONT,HORIZ_DIR,7);
			for(i=0;i<(ys-1)*13;i++)
			{
				j=i;
			}
			for(i=0;i<count%13;i++)
			{
				outtextxy(15,y,temp[j]->data.stuid);
				puthz(120,y,temp[j]->data.name,16,16,BLACK);
				
				if(count%13 == 1)//只有一本书 
				{
					puthz(250,y,temp[j]->data.borrow_book1,16,16,BLACK);
					outtextxy(420,y,temp[j]->data.borrow_time1);
				}
				else if(count%13 == 2)//两本书 
				{
					if(strcmp(temp[j]->data.stuid,temp[j+1]->data.stuid)==0)
					{
						curbook=1;
					}
					if(j>=1 && strcmp(temp[j-1]->data.stuid,temp[j]->data.stuid)==0)
					{
						curbook=2;
					}
				}
				else if(count%13 >= 3)//大于等于三本书 
				{
					if(strcmp(temp[j]->data.stuid,temp[j+2]->data.stuid)==0)//三本书的第一本 
					{
						curbook=1; 
					}
					else if(strcmp(temp[j]->data.stuid,temp[j+1]->data.stuid)==0)//两本书的第一本
					{
						curbook=1;
					} 
					else if(strcmp(temp[j]->data.stuid,temp[j+1]->data.stuid)!=0) //一本书 
					{
						curbook=1; 
					}
					
					if(j>=1 && strcmp(temp[j-1]->data.stuid,temp[j+1]->data.stuid)==0) 
					{
						curbook=2;
					}
					else if(j>=1 && strcmp(temp[j-1]->data.stuid,temp[j]->data.stuid)==0)
					{
						curbook=2;
					}
					
					if(j>=2 && strcmp(temp[j-2]->data.stuid,temp[j]->data.stuid)==0)
					{
						curbook=3;
					}
				}
				
				if(curbook==1)
				{
					puthz(250,y,temp[j]->data.borrow_book1,16,16,BLACK);
					outtextxy(420,y,temp[j]->data.borrow_time1);
				}
				else if(curbook==2)
				{
					puthz(250,y,temp[j]->data.borrow_book2,16,16,BLACK);
					outtextxy(420,y,temp[j]->data.borrow_time2);
				}
				else if(curbook==3)
				{
					puthz(250,y,temp[j]->data.borrow_book3,16,16,BLACK);
					outtextxy(420,y,temp[j]->data.borrow_time3);
				}
				j++;
				y+=25;
			}
		}
		else if(ys < count/13+1)//小于最后一页 
		{
			for(i=0;i<(ys-1)*13;i++)
			{
				j=i;
			}			
			setfillstyle(1,WHITE);
			bar(10,75,630,417);
			setcolor(LIGHTGRAY);
			for(line_y=73;line_y<417;)
			{
				line(15,line_y,625,line_y);
				line_y+=25;
			} 
			setcolor(BLACK);
			settextstyle(SMALL_FONT,HORIZ_DIR,7);
			for(i=0;i<13;i++)
			{
				outtextxy(15,y,temp[j]->data.stuid);
				puthz(120,y,temp[j]->data.name,16,16,BLACK);
				
				if(strcmp(temp[j]->data.stuid,temp[j+2]->data.stuid)==0)//三本书的第一本 
				{
					curbook=1; 
				}
				else if(strcmp(temp[j]->data.stuid,temp[j+1]->data.stuid)==0)//两本书的第一本
				{
					curbook=1;
				} 
				else if(strcmp(temp[j]->data.stuid,temp[j+1]->data.stuid)!=0) //一本书 
				{
					curbook=1; 
				}
				
				if(j>=1 && strcmp(temp[j-1]->data.stuid,temp[j+1]->data.stuid)==0) 
				{
					curbook=2;
				}
				else if(j>=1 && strcmp(temp[j-1]->data.stuid,temp[j]->data.stuid)==0)
				{
					curbook=2;
				}
				
				if(j>=2 && strcmp(temp[j-2]->data.stuid,temp[j]->data.stuid)==0)
				{
					curbook=3;
				}
				
				if(curbook==1)
				{
					puthz(250,y,temp[j]->data.borrow_book1,16,16,BLACK);
					outtextxy(420,y,temp[j]->data.borrow_time1);
				}
				else if(curbook==2)
				{
					puthz(250,y,temp[j]->data.borrow_book2,16,16,BLACK);
					outtextxy(420,y,temp[j]->data.borrow_time2);
				}
				else if(curbook==3)
				{
					puthz(250,y,temp[j]->data.borrow_book3,16,16,BLACK);
					outtextxy(420,y,temp[j]->data.borrow_time3);
				}
				j++;
				y+=25;
			}
		}
	}
}  

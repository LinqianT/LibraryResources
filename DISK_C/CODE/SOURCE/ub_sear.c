#include"common.h"
#include"LogTools.h"
#include"ub_sear.h"
int bookuser_search(BLink bhead,Link head,USER1 *p1)
{
	INPUT getsear={36,16,230-16*3,36,"",20,0,0};
	char gettitle[20]={'\0'},getauthor[20]={'\0'};
	int state=0,pre_state=0;
	int len1=0,len2=0;
	int page=1,count=0;
	int i=0,y=0;
	BLink node;
	node=bhead->next;
	while(node!=NULL)
	{
		count++;
		node=node->next;
	}
	Draw_bookInfSearch();//画图书搜索界面 
	out_binf(bhead,&page); 
	save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	while(1)
	{	
		if(state==1)
		{
			input_s(36+4,16,&getsear,6,0);
		}
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(540,10,630,40)==2||mouse_press(27-7,27-7,27+7,27+7)==2)//返回/搜索圈、未点击 
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
			return 4;
		}
		
		else if(mouse_press(260-7,27-7,260+7,27+7)==1)//状态1：编号 
		{
			pre_state=state;
			state=1;
			clrmous(MouseX,MouseY); 
			delay(100);
			setfillstyle(1,BLACK);
			fillellipse(260,27,5,5);
			if(pre_state=2)
			{
				setfillstyle(1,WHITE);
				fillellipse(260+60,27,5,5);
			}
			if(pre_state=3)
			{
				setfillstyle(1,WHITE);
				fillellipse(260+120,27,5,5);
			}
			save_bk_mou(MouseX,MouseY);//存取鼠标背景
			drawmous(MouseX,MouseY);//画鼠标
		}
		else if(mouse_press(260+60-7,27-7,260+60+7,27+7)==1)//状态2：书名 
		{
			pre_state=state;
			state=2;
			clrmous(MouseX,MouseY); 
			delay(100);
			setfillstyle(1,BLACK);
			fillellipse(260+60,27,5,5);
			if(pre_state=1)
			{
				setfillstyle(1,WHITE);
				fillellipse(260,27,5,5);
			}
			if(pre_state=3)
			{
				setfillstyle(1,WHITE);
				fillellipse(260+120,27,5,5);
			}
			save_bk_mou(MouseX,MouseY);//存取鼠标背景
			drawmous(MouseX,MouseY);//画鼠标
		}
		else if(mouse_press(260+120-7,27-7,260+120+7,27+7)==1)//状态3：作者 
		{
			pre_state=state;
			state=3;
			clrmous(MouseX,MouseY); 
			delay(100);
			setfillstyle(1,BLACK);
			fillellipse(260+120,27,5,5);
			if(pre_state=1)
			{
				setfillstyle(1,WHITE);
				fillellipse(260,27,5,5);
			}
			if(pre_state=2)
			{
				setfillstyle(1,WHITE);
				fillellipse(260+60,27,5,5);
			}
			save_bk_mou(MouseX,MouseY);//存取鼠标背景
			drawmous(MouseX,MouseY);//画鼠标
		}
		else if(mouse_press(36,16,230-16*3,36)==1 && state==2)
		{	
			len1=hz_input(36+4,16-2,230-16*3,36+12,gettitle,len1,WHITE);	
		} 
		else if(mouse_press(36,16,230-16*3,36)==1 && state==3)
		{	
			len2=hz_input(36+4,16-2,230-16*3,36+12,getauthor,len2,WHITE);
		} 
		else if(mouse_press(27-7,27-7,27+7,27+7)==1)//点击搜索 
		{
			//清除提示信息
			setfillstyle(1, WHITE);
			bar(230-16*3,16,230,36);
			if(getsear.string[0]=='\0' && gettitle[0]=='\0' && getauthor[0]=='\0')
			{
				puthz(230-16*3,16+2,"未输入",16,16,RED);
			}
		
			else
			{
				if(state==1)
				{
					sear_u_binf(getsear.string,state,bhead,p1,head);
					clrmous(MouseX,MouseY); 
					delay(100);
					Draw_BookInfSearch();
					out_binf(bhead,&page);
					save_bk_mou(MouseX,MouseY);//存取鼠标背景
					drawmous(MouseX,MouseY);//画鼠标
				}
				else if(state==2)
				{
					sear_u_binf(gettitle,state,bhead,p1,head);
					clrmous(MouseX,MouseY);
					delay(100);
					Draw_BookInfSearch();
					out_binf(bhead,&page);
					save_bk_mou(MouseX,MouseY);//存取鼠标背景
					drawmous(MouseX,MouseY);//画鼠标
				}
				else if(state==3)
				{
					sear_u_binf(getauthor,state,bhead,p1,head);
					clrmous(MouseX,MouseY); 
					delay(100);
					Draw_BookInfSearch();
					out_binf(bhead,&page);
					save_bk_mou(MouseX,MouseY);//存取鼠标背景
					drawmous(MouseX,MouseY);//画鼠标
				}
			}
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
				out_binf(bhead,&page);
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
					out_binf(bhead,&page);
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
					out_binf(bhead,&page);
					continue;
				}
			}
		}
		else //无操作 
		{		
			if(count%13==0)
			{
				for(i=1,y=75;y<417;i++,y+=25)
				{
					if(mouse_press(500,y,564,y+16)==1)
					{
						out_bookdtil(bhead,&page,&i,head,p1);
						printf("hello,world!");
						clrmous(MouseX,MouseY); 
						delay(300);
						Draw_bookInfSearch();//画图书搜索界面 
						out_binf(bhead,&page);
						save_bk_mou(MouseX,MouseY);//存取鼠标背景
						drawmous(MouseX,MouseY);//画鼠标
					}
				}
			}
			else
			{
				if(page<count/13+1)
				{
					for(i=1,y=75;y<417;i++,y+=25)
					{
						if(mouse_press(500,y,564,y+16)==1)
						{
							out_bookdtil(bhead,&page,&i,head,p1);
							clrmous(MouseX,MouseY); 
							delay(300);
							Draw_bookInfSearch();//画图书搜索界面 
							out_binf(bhead,&page);
							save_bk_mou(MouseX,MouseY);//存取鼠标背景
							drawmous(MouseX,MouseY);//画鼠标
						}
					}
				}
				if(page==count/13+1)
				{
					for(i=1,y=75;i<=count%13;i++,y+=25)
					{
						if(mouse_press(500,y,564,y+16)==1)
						{
							out_bookdtil(bhead,&page,&i,head,p1);
							clrmous(MouseX,MouseY); 
							delay(300);
							Draw_bookInfSearch();//画图书搜索界面 
							out_binf(bhead,&page);
							save_bk_mou(MouseX,MouseY);//存取鼠标背景
							drawmous(MouseX,MouseY);//画鼠标
						}
					}
				}
			}
			MouseS=0;
			continue;	 
		}
	} 
}
/**************************************************
函数：Draw_bookInfSearch
作用：书籍信息查询界面画图 
输入：
输出：
**************************************************/
void Draw_bookInfSearch()
{
	int line_y; 
	cleardevice();
	setfillstyle(1,BLUE);
	bar(0,0,640,480);
	//搜索框 
	setfillstyle(1,WHITE);
	bar(10,16,230,36);
	setcolor(DARKGRAY);
	circle(27,27,7);
	line(32,32,36,36);
	setcolor(WHITE);
	circle(260,27,7);
	fillellipse(260,27,5,5);
	circle(260+60,27,7);
	fillellipse(260+60,27,5,5);
	circle(260+120,27,7);
	fillellipse(260+120,27,5,5); 
	puthz(260+11,21,"编号",16,16,WHITE);
	puthz(260+11+60,21,"书名",16,16,WHITE);
	puthz(260+11+120,21,"作者",16,16,WHITE);
	//陈列:编号、书名、作者
	setfillstyle(1,WHITE); 
	bar(10,50,630,470);
	puthz(15,56,"编号",16,16,LIGHTGRAY);
	puthz(155,56,"书名",16,16,LIGHTGRAY);
	puthz(350,56,"作者",16,16,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	for(line_y=73;line_y<417;)
	{
		line(15,line_y,625,line_y);
		line_y+=25;
	} 
	//信息录入信息删除上一页下一页BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
	setfillstyle(1,LIGHTGRAY);
	bar(242,422,302,447);
	bar(312,422,372,447);
	setcolor(BLACK);
	rectangle(240,420,300,445);
	rectangle(310,420,370,445);
	puthz(247,427,"上一页",16,16,BLACK);
	puthz(317,427,"下一页",16,16,BLACK);
	//返回管理员主界面 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	setfillstyle(1,LIGHTGRAY);
	bar(542,12,632,42);
	setfillstyle(1,WHITE); 
	bar(540,10,630,40);
	puthz(560,17,"返回",24,24,BLACK);
}

/**************************************************
函数：out_bookdtil
作用：显示书籍详细信息并修改 
输入：bhead
	  *page 页码 
	  *order 序号 
输出：
**************************************************/
void out_bookdtil(BLink bhead,int *page,int *order,Link head,USER1 *p1)
{
	Link  p;
	INPUT newbkid ={275,175-1,500,175+22,"",3,0,0};
	int len1=0,len2=0;	
	int ys=0,sx=0;//页数、顺序（第几页第几个） 
	int i=0;
	char newtitle[20]={'\0'},newauthor[20]={'\0'};
	BLink curr;
	
	ys=(*page);
	sx=(*order);
	curr=bhead->next;
	p=head->next;
	for(i=0;i < 13*(ys-1)+sx-1;i++)
	{
		curr=curr->next;
	}
	 
	clrmous(MouseX,MouseY); 
	delay(300);
	setfillstyle(SOLID_FILL, CYAN);
    bar(120, 120, 520, 360);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(120, 120, 520, 160);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(480, 120, 520, 160);
    setcolor(RED);
    setlinestyle(0, 0, 3);
    line(485, 125, 515, 155);
    line(485, 155, 515, 125);
    line(485, 125, 485, 155);
    line(485, 125, 515, 125);
    line(515, 125, 515, 155);
    line(485, 155, 515, 155);
    puthz(140, 130, "详细信息", 32, 32, DARKGRAY);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(430, 320, 515, 355); //修改按钮
    puthz(440, 337 - 16, "借阅", 32, 32, BLACK);
    puthz(140, 180, "编号", 24, 24, BLACK);
	puthz(140,220,"书名",24,24,BLACK);
	puthz(140,260,"作者",24,24,BLACK); 
	setcolor(BLACK); 
	settextstyle(SMALL_FONT,HORIZ_DIR,8);
	outtextxy(180+30,180,curr->data.bkid);
	puthz(180+30,220,curr->data.title,24,24,BLACK);
	puthz(180+30,260,curr->data.author,24,24,BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if (mouse_press(430, 320, 515, 355) == 2||mouse_press(480, 120, 520, 170) == 2)
        {
            MouseS = 1;
            continue;
        }
        else if (mouse_press(480, 120, 520, 170) == 1)
        {
            MouseS = 0;
            break; //退出
        }
        
        else if (mouse_press(430, 320, 515, 355) == 1)//确认借阅 
        {
            while(p!=NULL)
            {
	            if(strcmp(p->data.stuid,p1->study_id)==0)
	            {
	            	if((strcmp(p->data.borrow_book1,curr->data.title)!=0)&&(strcmp(p->data.borrow_book2,curr->data.title)!=0)&&(strcmp(p->data.borrow_book3,curr->data.title)!=0))
	            	{
	            		if(strcmp(p->data.borrow_book1,"")!=0)
	            		{
	            		if(strcmp(p->data.borrow_book2,"")!=0)
	            		{
	            			if(strcmp(p->data.borrow_book3,"")!=0)
	            			{
	            				puthz(140,280+30,"借阅数目已达上限！",16,16,RED);
							}
							else 
							{
								strcpy(p->data.borrow_book3,curr->data.title);
								if(strcmp(p->data.borrow_time1,"")!=0)
								{
									if(strcmp(p->data.borrow_time2,"")!=0)
									{
										if(strcmp(p->data.borrow_time3,"")!=0)
										{
											break;
										}
										else 
										{
											get_time(p->data.borrow_time3);
										}
									}
									else 
									{
										get_time(p->data.borrow_time2);
									}
								}
								else
								{
									get_time(p->data.borrow_time1);
								}
								wr_user_info(head);
								strcpy(p1->borrow_book[2],curr->data.title);
								curr->data.borrow_times++;
								wr_book_info(bhead);
								sucdraw(3);
								delay(1000);
								save_bk_mou(MouseX,MouseY);
								clrmous(MouseX,MouseY);
								return 28;
							}
						}
						else 
						{
							strcpy(p->data.borrow_book2,curr->data.title);
							if(strcmp(p->data.borrow_time1,"")!=0)
								{
									if(strcmp(p->data.borrow_time2,"")!=0)
									{
										if(strcmp(p->data.borrow_time3,"")!=0)
										{
											break;
										}
										else 
										{
											get_time(p->data.borrow_time3);
										}
									}
									else 
									{
										get_time(p->data.borrow_time2);
									}
								}
								else
								{
									get_time(p->data.borrow_time1);
								}
							wr_user_info(head);
							strcpy(p1->borrow_book[1],curr->data.title);
							curr->data.borrow_times++;
							wr_book_info(bhead);
							sucdraw(3);
							delay(1000);
							save_bk_mou(MouseX,MouseY);
							clrmous(MouseX,MouseY);
							return 28;
						}
					}	
					else 
					{
						strcpy(p->data.borrow_book1,curr->data.title);
						if(strcmp(p->data.borrow_time1,"")!=0)
								{
									if(strcmp(p->data.borrow_time2,"")!=0)
									{
										if(strcmp(p->data.borrow_time3,"")!=0)
										{
											break;
										}
										else 
										{
											get_time(p->data.borrow_time3);
										}
									}
									else 
									{
										get_time(p->data.borrow_time2);
									}
								}
								else
								{
									get_time(p->data.borrow_time1);
								}
						wr_user_info(head);
						strcpy(p1->borrow_book[0],p->data.borrow_book1);
						curr->data.borrow_times++;
	            		wr_book_info(bhead);
						sucdraw(3);
						delay(1000);
						save_bk_mou(MouseX,MouseY);
						clrmous(MouseX,MouseY);
						return 28 ;
					}
					break;
				}
				else 
				{
					puthz(140,280+30,"该书已借阅！",16,16,RED);
					break;
				}
				}	
				else 
				{
					p=p->next;
				}
			}
		}
        else
        {
            MouseS = 0;
            continue; 
        }
	}
}
void draw_page_borrow(BLink bhead,int *page)
{
	setfillstyle(1,CYAN);
	bar(200,150,440,330);
	puthz(200+40,150+50,"借阅成功",32,32,BLUE);
	setcolor(BLACK);
	rectangle(290,280,375,330);
	setfillstyle(1,7);
	bar(290+2,280+2,375+2,330+2);
	puthz(300,290,"确定",32,32,BLACK); 
	
}
void sear_u_binf(char str[],int mode,BLink bhead,USER*p1,Link head)
{
	int flag=1,y=75,i=0,j=0;
	int count=1,curpg,curod;
	int line_y,all,page;
	int remember[20];
	BLink p,node;
	node=bhead->next;
	while(node!=NULL)
	{
		all++;
		node=node->next;
	}
	if(all%13==0)
	{
		page=all/13;
	}
	else if(all%13!=0)
	{
		page=all/13+1;
	}
	
	setfillstyle(1,WHITE); 
	bar(10,50,630,470);
	puthz(15,56,"编号",16,16,LIGHTGRAY);
	puthz(155,56,"书名",16,16,LIGHTGRAY);
	puthz(350,56,"作者",16,16,LIGHTGRAY);
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
	setcolor(BLACK);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	
	p=bhead->next;
	while(p!=NULL && mode==1)
	{
		if (strcmp(p->data.bkid,str) == 0)
		{
	        flag=0;
	        outtextxy(15,y,p->data.bkid);
			puthz(155,y,p->data.title,16,16,BLACK);
			puthz(350,y,p->data.author,16,16,BLACK);
			puthz(500,y,"查看详情",16,16,LIGHTBLUE);
	        break;
        }
	    else
	    {
		    p = p->next;
		    count++;
	    }
	}
	while(p!=NULL && mode==2)
	{
		if (strstr(p->data.title,str) != NULL)
		{
	        flag=0;
	        outtextxy(15,y,p->data.bkid);
			puthz(155,y,p->data.title,16,16,BLACK);
			puthz(350,y,p->data.author,16,16,BLACK);
			puthz(500,y,"查看详情",16,16,LIGHTBLUE);
			y+=25;
			p=p->next;
			remember[i]=count;
			j=i;
			i++;
			count++;
        }
	    else
	    {
		    p = p->next;
		    count++;
	    }
	}
	while(p!=NULL && mode==3)
	{
		if (strcmp(p->data.author,str) == 0)
		{
	        flag=0;
	        outtextxy(15,y,p->data.bkid);
			puthz(155,y,p->data.title,16,16,BLACK);
			puthz(350,y,p->data.author,16,16,BLACK);
			puthz(500,y,"查看详情",16,16,LIGHTBLUE);
			y+=25;
			p=p->next;
			remember[i]=count;
			j=i;
			i++;
			count++;
        }
	    else
	    {
		    p = p->next;
		    count++;
	    }
	}
	if(flag==1) 
	{
		puthz(230-16*3,16+2,"找不到",16,16,RED);
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(540,10,630,40)==2||mouse_press(20,415,110,445)==2||mouse_press(120,415,210,445)==2)//返回/录入/搜索圈、未点击 
        {
            MouseS=1;
			continue; 
        }
        else if(mouse_press(240,420,300,445)==2||mouse_press(310,420,370,445)==2)//上一页下一页、未点击 
		{
			MouseS=1;
			continue;
		}
		else if (mouse_press(540,10,630,40) == 1)//返回、点击 
        {
            return 26;
        }
        else 
		{
			if(mode==1)
			{
				if(count%13==0)
				{
					curpg=count/13;
					curod=13;
				}
				else
				{
					curpg=count/13+1;
					curod=count%13;
				}
				
				if(mouse_press(500,75,564,75+16)==1)
				{
					out_bookdtil(bhead,&curpg,&curod,head,p1);
					delay(200);
					sear_u_binf(str,mode,bhead,p1,head);
				} 
				
			}
			else if(mode==2)
			{
				for(i=0,y=75;i<=j;i++,y+=25)
				{
					if(remember[i]%13==0)
					{
						curpg=remember[i]/13;
						curod=13;
					}
					else
					{
						curpg=remember[i]/13+1;
						curod=remember[i]%13;
					}
					if(mouse_press(500,y,564,y+16)==1)
					{
						out_bookdtil(bhead,&curpg,&curod,head,p1);
						delay(200);
						return;
					}
				}
			}
			else if(mode==3)
			{
				for(i=0,y=75;i<=j;i++,y+=25)
				{
					if(remember[i]%13==0)
					{
						curpg=remember[i]/13;
						curod=13;
					}
					else
					{
						curpg=remember[i]/13+1;
						curod=remember[i]%13;
					}
					if(mouse_press(500,y,564,y+16)==1)
					{
						out_bookdtil(bhead,&curpg,&curod,head,p1);
						delay(200);
						sear_u_binf(str,mode,bhead,p1,head);
					}
				}
			}
			//无操作 
			MouseS=0;
			continue;
		}		
	}
}



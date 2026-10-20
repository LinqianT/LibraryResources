#include"common.h"
#include"Mb_sear.h"
#include"Lend_mng.h"
/*图书馆信息管理搜索界面
	功能：1.作者、编号、书名搜索/关键词搜索
		  2.显示信息
		  3.点击后跳转信息详情界面
		  4.添加：跳转添加信息界面
		  5.删除信息
		  6.翻页 
*/ 
int bookmng_search(BLink bhead)
{
	INPUT getsear={36,16,230-16*3,36,"",20,0,0};
	char gettitle[20]={'\0'},getauthor[20]={'\0'};
	int len1=0,len2=0;
	int state=0,pre_state=0;
	int page=1,count=0;
	int i=0,y=0;
	BLink node;
	node=bhead->next;
	while(node!=NULL)
	{
		count++;
		node=node->next;
	}
	
	clrmous(MouseX,MouseY); 
	delay(100);
	Draw_BookInfSearch();
	sortbybkid(bhead);
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
		if(mouse_press(540,10,630,40)==2||mouse_press(20,415,110,445)==2||mouse_press(27-7,27-7,27+7,27+7)==2||mouse_press(120,415,210,445)==2)//返回/录入/搜索圈、未点击 
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
		else if(mouse_press(20,415,110,445)==1)//录入、点击 
		{
			return 27;
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
					sear_binf(getsear.string,state,bhead);
					clrmous(MouseX,MouseY); 
					delay(100);
					Draw_BookInfSearch();
					out_binf(bhead,&page);
					save_bk_mou(MouseX,MouseY);//存取鼠标背景
					drawmous(MouseX,MouseY);//画鼠标
				}
				else if(state==2)
				{
					sear_binf(gettitle,state,bhead);
					clrmous(MouseX,MouseY); 
					delay(100);
					Draw_BookInfSearch();
					out_binf(bhead,&page);
					save_bk_mou(MouseX,MouseY);//存取鼠标背景
					drawmous(MouseX,MouseY);//画鼠标
				}
				else if(state==3)
				{
					sear_binf(getauthor,state,bhead);
					clrmous(MouseX,MouseY); 
					delay(100);
					Draw_BookInfSearch();
					out_binf(bhead,&page);
					save_bk_mou(MouseX,MouseY);//存取鼠标背景
					drawmous(MouseX,MouseY);//画鼠标
				}
			}
		}
		else if(mouse_press(120,415,210,445)==1) //删除
		{
			bkdel(bhead);
			clrmous(MouseX,MouseY); 
			delay(100);
			Draw_BookInfSearch();
			out_binf(bhead,&page);
			save_bk_mou(MouseX,MouseY);//存取鼠标背景
			drawmous(MouseX,MouseY);//画鼠标
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
						outuserdtil(bhead,&page,&i);
						clrmous(MouseX,MouseY); 
						delay(300);
						Draw_BookInfSearch();
						out_uinf(bhead,&page);
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
							outbookdtil(bhead,&page,&i);
							clrmous(MouseX,MouseY); 
							delay(300);
							Draw_BookInfSearch();
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
							outbookdtil(bhead,&page,&i);
							clrmous(MouseX,MouseY); 
							delay(300);
							Draw_BookInfSearch();
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
函数：Draw_BookInfSearch
作用：书籍信息查询界面画图 
输入：
输出：
**************************************************/
void Draw_BookInfSearch()
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
	bar(22,417,112,447);
	bar(122,417,212,447);
	bar(242,422,302,447);
	bar(312,422,372,447);
	setcolor(BLACK);
	rectangle(20,415,110,445);
	rectangle(120,415,210,445);
	rectangle(240,420,300,445);
	rectangle(310,420,370,445);
	puthz(40,422,"录入",24,24,BLACK);
	puthz(140,422,"删除",24,24,BLACK);
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
函数：bkdel
作用：删除书籍信息 
输入：head
输出：
**************************************************/
void bkdel(BLink bhead)
{
	INPUT delid= {180, 190, 500, 220,"",3,0,0};
	FILE* fp; 
	BLink p,q,curr;
	
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
    puthz(140, 130, "删除书籍", 24, 32, DARKGRAY);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(430, 320, 515, 355); //确定按钮
    puthz(440, 337 - 16, "确定", 32, 32, BLACK);
    puthz(140, 195, "编号", 16, 16, BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    bar(180, 190, 500, 220);
    
    while(1)
	{
		input_s(180+4,190+4,&delid,7,0);
		
		newmouse(&MouseX,&MouseY,&press);
		if (mouse_press(430, 320, 515, 355) == 2||mouse_press(480, 120, 520, 170) == 2)
        {
            MouseS = 1;
            continue;
        }
        else if (mouse_press(430, 320, 515, 355) == 1)
        {
            MouseS = 0;
            if(delid.string[0]=='\0')
			{
				puthz(140, 320, "请输入编号！", 16, 16, RED);
			} 
			else
			{
				if (judge_samebkid(delid.string,bhead)==1)
	            {
	                setfillstyle(SOLID_FILL, CYAN);
	                bar(130, 320, 400, 355);
	                puthz(140, 320, "编号不存在！", 16, 16, RED);
	            }
	            else
	            {
					q=bhead;
					p=bhead->next;
					while(p!=NULL)
					{
						if (strcmp(p->data.bkid,delid.string) == 0)
						{
					        q->next=p->next;
					        free(p);
					        break;
				        }
				        else
				        {
						    q = p;
				            p = p->next;
				        }
					}
					wr_book_info(bhead);
					sucdraw(1);
					delay(1000);
					return 29;
	            }
			} 
        }
        else if (mouse_press(480, 120, 520, 170) == 1)
        {
            MouseS = 0;
            delay(200);
            break; //退出
        }
        else
        {
            MouseS = 0;
            continue; 
        }
    }
    return;
}
/**************************************************
函数：outbookdtil
作用：显示书籍详细信息并修改 
输入：bhead
	  *page 页码 
	  *order 序号 
输出：
**************************************************/
void outbookdtil(BLink bhead,int *page,int *order)
{
	INPUT newbkid ={275,175-1,500,175+22,"",3,0,0};
	int len1=0,len2=0;	
	int ys=0,sx=0;//页数、顺序（第几页第几个） 
	int i=0;
	char newtitle[20]={'\0'},newauthor[20]={'\0'};
	BLink curr;
	ys=(*page);
	sx=(*order);
	curr=bhead->next;
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
    puthz(140, 130, "详细信息", 24, 32, DARKGRAY);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(430, 320, 515, 355); //修改按钮
    puthz(440, 337 - 16, "修改", 32, 32, BLACK);
    puthz(140, 180, "编号", 16, 16, BLACK);
	puthz(140,220,"书名",16,16,BLACK);
	puthz(140,260,"作者",16,16,BLACK); 
	setcolor(BLACK); 
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	outtextxy(180,175,curr->data.bkid);
	puthz(180,215,curr->data.title,16,16,BLACK);
	puthz(180,255,curr->data.author,16,16,BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    bar(275,175-1,500,175+22);
    bar(275,215-1,500,215+22);
    bar(275,255-1,500,255+22);
    save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		input_s(275+4,175-1,&newbkid,6,0);
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
        else if(mouse_press(275,215-1,500,215+22)==1)
        {
			len1=hz_input(275,215-1,500,215+22+10,newtitle,len1,WHITE);
		}
		else if(mouse_press(275,255-1,500,255+22)==1)
        {
			len2=hz_input(275,255-1,500,255+22+10,newauthor,len2,WHITE);
		}
        else if (mouse_press(430, 320, 515, 355) == 1)
        {
            MouseS = 0;
            if(newbkid.string[0]=='\0' && newtitle[0]=='\0'  && newauthor[0]=='\0') 
    		{
    			setfillstyle(SOLID_FILL, CYAN);
	            bar(140, 280+30, 425, 355);
    			puthz(140, 280+30, "未修改任何信息！", 16, 16, RED);
			}
			else
			{
				if (judge_samebkid(newbkid.string,bhead)==1)
	            {
	            	setfillstyle(SOLID_FILL, CYAN);
	                bar(140, 280+30, 425, 355);
	                puthz(140, 280+30, "编号已存在！", 16, 16, RED);
	            }
	            else
	            {
	            	if(newbkid.string[0]!='\0')
	            	{
	            		strcpy(curr->data.bkid,newbkid.string);
					}
					if(newtitle[0]!='\0')
					{
						strcpy(curr->data.title,newtitle);
					}
					if(newauthor[0]!='\0')
					{
						strcpy(curr->data.author,newauthor);
					}
					wr_book_info(bhead);
					sucdraw(2);
					delay(1000);
					return 26;
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

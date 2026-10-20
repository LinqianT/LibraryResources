#include"common.h"
#include"Mu_sear.h"
#include"Logtools.h"
 
 /*用户信息管理界面
 	功能：1.显示用户信息
	 	  2.搜索
		  3.删除信息
		  4.跳转添加信息界面
		  5.点击显示详细信息
		  6.翻页 
 */ 
int usermng_search(Link head)
{
	INPUT getsear={36,16,230-16*3,36,"",20,0,0};
	int state=0,pre_state=0;
	int page=1,count=0;
	int i=0,y=0,len=0;
	char getname[20]={'\0'}; 
	Link node;
	node=head->next;
	while(node!=NULL)
	{
		count++;
		node=node->next;
	}
	
	clrmous(MouseX,MouseY); 
	delay(250);
	Draw_usermngsearch();
	out_uinf(head,&page);
	save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	while(1)
	{
		if(state==1||state==3)
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
			return 30;
		}
		else if(mouse_press(260-7,27-7,260+7,27+7)==1)//状态1：学号 
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
		else if(mouse_press(260+60-7,27-7,260+60+7,27+7)==1)//状态2：姓名 
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
		else if(mouse_press(260+120-7,27-7,260+120+7,27+7)==1)//状态3：班级 
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
			len=hz_input(36+4,16-2,230-16*3,36+12,getname,len,WHITE);	
		} 
		else if(mouse_press(27-7,27-7,27+7,27+7)==1)//点击搜索 
		{
			//清除提示信息
			setfillstyle(1, WHITE);
			bar(230-16*3,16,230,36);
			if(getsear.string[0]=='\0' && getname[0]=='\0')
			{
				puthz(230-16*3,16+2,"未输入",16,16,RED);
			}
			else
			{
				if(state==1 || state==3)
				{
					sear_uinf(getsear.string,state,head);
					clrmous(MouseX,MouseY); 
					delay(100);
					Draw_usermngsearch();
					out_uinf(head,&page);
					save_bk_mou(MouseX,MouseY);//存取鼠标背景
					drawmous(MouseX,MouseY);//画鼠标
				}
				else if(state==2)
				{
					sear_uinf(getname,state,head);
					clrmous(MouseX,MouseY); 
					delay(100);
					Draw_usermngsearch();
					out_uinf(head,&page);
					save_bk_mou(MouseX,MouseY);//存取鼠标背景
					drawmous(MouseX,MouseY);//画鼠标
				}
				else
				{
					continue; 
				}
			}
		}
		else if(mouse_press(120,415,210,445)==1) //删除
		{
			userdel(head);
			clrmous(MouseX,MouseY); 
			delay(100);
			Draw_usermngsearch();
			out_uinf(head,&page);
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
            	delay(100);
            	page--;
				out_uinf(head,&page);
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
					out_uinf(head,&page);
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
					out_uinf(head,&page);
					continue;
				}
			}
			
		}
		else 
		{
			if(count%13==0)
			{
				for(i=1,y=75;y<417;i++,y+=25)
				{
					if(mouse_press(500,y,564,y+16)==1)
					{
						outuserdtil(head,&page,&i);
						clrmous(MouseX,MouseY); 
						delay(300);
						Draw_usermngsearch();
						out_uinf(head,&page);
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
							outuserdtil(head,&page,&i);
							clrmous(MouseX,MouseY); 
							delay(300);
							Draw_usermngsearch();
							out_uinf(head,&page);
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
							outuserdtil(head,&page,&i);
							clrmous(MouseX,MouseY); 
							delay(300);
							Draw_usermngsearch();
							out_uinf(head,&page);
							save_bk_mou(MouseX,MouseY);//存取鼠标背景
							drawmous(MouseX,MouseY);//画鼠标
						}
					}
				}
			}
			//无操作 
			
			MouseS=0;
			continue;
		}		
	} 
}
/**************************************************
函数：Draw_usermngsearch
作用：用户信息查询界面画图 
输入：
输出：
**************************************************/
void Draw_usermngsearch() 
{ 
	int line_y;
	cleardevice();
 	setfillstyle(1,BLUE);
	bar(0,0,640,480);
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
	puthz(260+11,21,"学号",16,16,WHITE);
	puthz(260+11+60,21,"姓名",16,16,WHITE);
	puthz(260+11+120,21,"班级",16,16,WHITE);
	setfillstyle(1,WHITE);
	bar(10,50,630,470);
	puthz(15,56,"学号",16,16,LIGHTGRAY);
	puthz(155,56,"姓名",16,16,LIGHTGRAY); 
	puthz(155+105,56,"性别",16,16,LIGHTGRAY);
	puthz(155+105+105,56,"班级",16,16,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	for(line_y=73;line_y<417;)
	{
		line(15,line_y,625,line_y);
		line_y+=25;
	} 
	//信息录入信息删除上一页下一页BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
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
	
	//返回管理员端主界面界面AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA	
	setfillstyle(1,LIGHTGRAY);
	bar(542,12,632,42);
	setfillstyle(1,WHITE); 
	bar(540,10,630,40);
	puthz(560,17,"返回",24,24,BLACK); 
}
/**************************************************
函数：userdel
作用：删除用户信息 
输入：head
输出：
**************************************************/
void userdel(Link head)
{
	INPUT delid= {180, 190, 500, 220,"",3,0,0};
	FILE* fp; 
	Link p,q,curr;
		
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
    puthz(140, 130, "删除用户", 24, 32, DARKGRAY);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(430, 320, 515, 355); //确定按钮
    puthz(440, 337 - 16, "确定", 32, 32, BLACK);
    puthz(140, 195, "学号", 16, 16, BLACK);
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
				setfillstyle(SOLID_FILL, CYAN);
	            bar(130, 320, 400, 355);
				puthz(140, 320, "请输入学号！", 16, 16, RED);
			} 
			else
			{
				if (judge_samestuid(delid.string,head)==1)
	            {
	                setfillstyle(SOLID_FILL, CYAN);
	                bar(130, 320, 400, 355);
	                puthz(140, 320, "学号不存在！", 16, 16, RED);
	            }
	            else
	            {
					q=head;
					p=head->next;
					while(p!=NULL)
					{
						if (strcmp(p->data.stuid,delid.string) == 0)
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
					wr_user_info(head);
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
函数：outuserdtil
作用：显示用户详细信息并修改 
输入：head
	  *page 页码 
	  *order 序号 
输出：
**************************************************/
void outuserdtil(Link head,int *page,int *order)
{
	int len=0;
	char newname[20]={'\0'};
	INPUT newid ={220,175-1,275,175+22,"",3,0,0};
	//INPUT newname ={400,175-1,500,175+22,"",20,0,0};
	INPUT newgender ={220,215-1,275,215+22,"",6,0,0};
	INPUT newclass ={320,240-1,500,240+22,"",10,0,0};
	INPUT newpassword ={140,280-1,500,280+22,"",12,0,0};	
	int ys=0,sx=0;//页数、顺序（第几页第几个） 
	int i=0;
	Link curr;
	ys=(*page);
	sx=(*order);
	curr=head->next;
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
    puthz(140, 180, "学号", 16, 16, BLACK);
    puthz(320,180,"姓名",16,16,BLACK);
	puthz(140,220,"性别",16,16,BLACK);
	puthz(320,220,"班级",16,16,BLACK);
	puthz(140,260,"密码",16,16,BLACK); 
	setcolor(BLACK); 
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	outtextxy(180,175,curr->data.stuid);
	//outtextxy(360,175,curr->data.name);
	puthz(360,175,curr->data.name,16,16,BLACK);
	outtextxy(180,215,curr->data.gender);
	outtextxy(360,215,curr->data.class);
	outtextxy(180,255,curr->data.password);
    setfillstyle(SOLID_FILL, WHITE);
    bar(220,175-1,275,175+22);
    bar(400,175-1,500,175+22);
    bar(220,215-1,275,215+22);
    bar(320,240-1,500,240+22);
    bar(140,280-1,500,280+22);
    save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		input_s(220+2,174,&newid,6,0);
		//input_s(400+2,174,&newname,6,0);
		input_s(220+2,214,&newgender,6,0);
		input_s(320+2,239,&newclass,6,0);
		input_s(140+2,279,&newpassword,6,0);
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
        else if(mouse_press(400,175-1,500,175+22)==1)
		{
			len=hz_input(400,175-1,500,175+22+10,newname,len,WHITE);
		}
        else if (mouse_press(430, 320, 515, 355) == 1)
        {
            MouseS = 0;
            if(newid.string[0]=='\0' && newname[0]=='\0' && newgender.string[0]=='\0' && newclass.string[0]=='\0' && newpassword.string[0]=='\0') 
    		{
    			setfillstyle(SOLID_FILL, CYAN);
	            bar(140, 280+30, 425, 355);
    			puthz(140, 280+30, "未修改任何信息！", 16, 16, RED);
			}
			else
			{
				if (judge_samestuid(newid.string,head)==0)
	            {
	            	setfillstyle(SOLID_FILL, CYAN);
	                bar(140, 280+30, 425, 355);
	                puthz(140, 280+30, "学号已存在！", 16, 16, RED);
	            }
	            else
	            {
	            	if(newid.string[0]!='\0')
	            	{
	            		strcpy(curr->data.stuid,newid.string);
					}
					if(newname[0]!='\0')
					{
						strcpy(curr->data.name,newname);
					}
					if(newgender.string[0]!='\0')
					{
						strcpy(curr->data.gender,newgender.string);
					}
					if(newclass.string[0]!='\0')
	            	{
	            		strcpy(curr->data.class,newclass.string);
					}
					if(newpassword.string[0]!='\0')
	            	{
	            		strcpy(curr->data.password,newpassword.string);
					}
					wr_user_info(head);
					sucdraw(2);
					delay(1000);
					return 29;
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

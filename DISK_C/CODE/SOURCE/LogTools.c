/**************************************************
File Name: LogTools.c
Description: 登录注册等所需的工具函数
Function List: input_s  键盘输入函数
               judge_samestuid  判断学号是否重复 
			   judge_password  判断密码是否符合要求
			   wr_user_info  将注册信息写入文件
			   right_key  判断密码是否正确
			   wr_usernow  写入登录信息
			   right_ID  判断身份证号是否正确
			   re_user_info  将新密码写入文件
**************************************************/

#include "common.h"
#include "LogTools.h"

/**************************************************
函数: input_s
作用：键盘输入函数
输入：x  输入位置左边界
	  y  输入位置上边界
	  size  字符大小
	  mode  输入模式，0为可见信息如用户名、身份证号，1为不可见信息如密码
返回： 
**************************************************/
void input_s(int x, int y, INPUT *word, int size, int mode)
{
	if(press == 1)
	{
		if(mouse_press(word->x1,word->y1,word->x2,word->y2)==1)
		{
			word->flag = 1;
			
			clrmous(MouseX,MouseY);
			setcolor(RED);
			setlinestyle(0,0,1);
			rectangle(word->x1,word->y1,word->x2,word->y2);
			setcolor(DARKGRAY);
			line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
		}
		else
		{
			word->flag = 0;
			
			clrmous(MouseX,MouseY);
			setcolor(WHITE);
			setlinestyle(0,0,1);
			rectangle(word->x1,word->y1,word->x2,word->y2);
			line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
		}	
	}
	
	//flag为1时表示可以接收键盘输入
	if(word->flag == 1)
	{
		char t;
		
		if(kbhit())
		{
			t = getch();
			
			if(t=='\b')
			{
				if(word->cursor > 0)
				{
					(word->string)[word->cursor-1]='\0';
					(word->cursor)--;
				}
			}
			else if(t>='!' && t<='~')
			{
				if(word->cursor < word->length)
				{
					(word->string)[word->cursor]=t;
					(word->string)[word->cursor+1]='\0';
					(word->cursor)++;
				}
			}
			
			setcolor(DARKGRAY);
			setlinestyle(0,0,1);
			setfillstyle(SOLID_FILL,WHITE);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			settextstyle(SMALL_FONT,HORIZ_DIR,size);
			bar(word->x1+2,word->y1+2,word->x2-2,word->y2-2);
			if(mode == 0)
			{
				setcolor(DARKGRAY);
				outtextxy(x,y,word->string);
				line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
			}
			else
			{
				int i;
				for(i=0;i<word->cursor;i++)
				{
					outtextxy(x+i*(2*size-2),y,"*");
				}
				line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
			}
		}
	}
}
/**************************************************
函数：nodeinit/bnodeinit 
作用：初始化用户/书籍信息链表 
输入：head/bhead
返回： 
**************************************************/
Link nodeinit(Link head)
{
	FILE* fp;
	Link temp,tail;
	int n;
	//建立head头结点，在这个程序中head指向头结点，头结点data部分没有内容，其后续节点才有真正的数据
	if((head=(Link)malloc(sizeof(Node)))==NULL)
	{
		printf("memory error WrBookInf");
		delay(3000);			
		exit(1);//分配空间不足，退出程序
	}
	temp=tail=head;
	
	if((fp=fopen("database\\UserInf.dat","rb"))==NULL)
	{
		closegraph();
		printf("\nUserInfo.dat error file");
		delay(3000);
		exit(1);//打开失败，退出程序
	}
	
	while(1)
	{
		temp = (Link)malloc(sizeof(Node));
		temp->next=NULL;
		n=fread(&(temp->data),sizeof(USER),1,fp);
		if(n==0)
		{
			free(temp);
			break;
		}
		tail->next = temp;
		tail = temp;
		temp = temp->next;
	}

	if(fclose(fp) != 0)//关闭文件
	{
		printf("\nError in closing file UserInfo.");
		delay(3000);
		exit(1);
	}
	return head;
}

BLink bnodeinit(BLink bhead)
{
	FILE* fp;
	BLink temp,tail;
	int n;
	//建立head头结点，在这个程序中head指向头结点，头结点data部分没有内容，其后续节点才有真正的数据
	if((bhead=(BLink)malloc(sizeof(BNode)))==NULL)
	{
		printf("memory error WrBookInf");
		delay(3000);			
		exit(1);//分配空间不足，退出程序
	}
	temp=tail=bhead;
	
	if((fp=fopen("database\\BookInf.dat","rb"))==NULL)
	{
		closegraph();
		printf("\nBookInfo.dat error file");
		delay(3000);
		exit(1);//打开失败，退出程序
	}
	
	while(1)
	{
		temp = (BLink)malloc(sizeof(BNode));
		temp->next=NULL;
		n=fread(&(temp->data),sizeof(BOOK),1,fp);
		if(n==0)
		{
			free(temp);
			break;
		}
		tail->next = temp;
		tail = temp;
		temp = temp->next;
	}

	if(fclose(fp) != 0)//关闭文件
	{
		printf("\nError in closing file UserInfo.");
		delay(3000);
		exit(1);
	}
	return bhead;
}
/**************************************************
函数：judge_stuid 
作用：判断学号是否已存在
输入： ID 学号
	   head 链表头结点
返回：0表示存在，1表示不存在
**************************************************/
int judge_samestuid(char ID[],Link head)
{
	Link p;
	int flag=1;
	
	p=head->next;
	while(p!=NULL)
	{
		if (strcmp(p->data.stuid,ID) == 0)
		{
	        flag=0;
	        break;
        }
	    else
	    {
		    p = p->next;
	    }
	}
	return flag;
}

/**************************************************
函数：judge_bkid
作用：通过链表判断书籍编号是否已存在
输入： ID 书籍编号 
	   bhead 链表头结点
返回： 0表示存在，1表示不存在
**************************************************/
int judge_samebkid(char ID[],BLink bhead)
{
	BLink p;
	int flag=1;
	
	p=bhead->next;
	while(p!=NULL)
	{
		if (strcmp(p->data.bkid,ID) == 0)
		{
	        flag=0;
	        break;
        }
	    else
	    {
		    p = p->next;
	    }
	}
	return flag;
}


/**************************************************
函数：judge_password
作用：判断密码是否符合要求
输入： password  密码
返回： 0表示不符合要求，1表示符合要求
**************************************************/
int judge_password(char password[])
{
	int i;
	int flag=1;
	
	for(i=0;i<13;i++)
		if(password[i]=='\0') break;
	
	if(i<5)	//密码不超过五位则不符合要求
		flag=0;
	
	return flag;
}

/**************************************************
函数：insert_user
作用：用户信息链表插入节点并排序 
输入： Name 姓名 
       key  密码
	   ID   学号
	   Class 班级
	   sex  性别 
	   head 链表头结点 
输出： 
**************************************************/
void insert_user(char Name[],char sex[],char ID[],char key[],char Class[],Link head) 
{
    // 创建新节点并设置数据
    Link node;
    Link p,q;
	int i;
    if((node=(Link)malloc(sizeof(Node)))==NULL)
	{
		printf("memory error WrBookInf");
		delay(3000);			
		exit(1);//分配空间不足，退出程序
	}
    // 设置新节点的数据
    strcpy(node->data.name, Name);
    strcpy(node->data.gender, sex);
    strcpy(node->data.stuid, ID);
    strcpy(node->data.password, key);
    strcpy(node->data.class, Class);
    strcpy(node->data.seat,'\0');
    strcpy(node->data.age,"");
    strcpy(node->data.string,"");
    itoa(0,node->data.balance,10);
    itoa(0,node->data.arrears,10);
    strcpy(node->data.borrow_book1,"");
    strcpy(node->data.borrow_book2,"");
    strcpy(node->data.borrow_book3,"");
    strcpy(node->data.collect_book1,"");
    strcpy(node->data.collect_book2,"");
    strcpy(node->data.collect_book3,"");
    strcpy(node->data.borrow_time1,"");
    strcpy(node->data.borrow_time2,"");
    strcpy(node->data.borrow_time3,"");
	node->data.x1=0;
	node->data.y1=0;
	node->data.x2=0;
	node->data.y2=0;
	node->data.resv_floor=0;
	node->data.seat_state=2;//暂时没有进行选座是2，离开时0，正在位置是 1
	node->data.borrow_state=0;
	node->next=NULL;
	q=head;
	p=head->next;
	if(head->next==NULL) //链表为空时
	{
		head->next = node;
		node->next=NULL;
	}
	else //循环访问链表中的所有节点
	{
		while(p != NULL)
		{
			if (strcmp(node->data.stuid,p->data.stuid)<0)
			{
				//如果node节点的学号比p节点的学号小，则插在p的前面，完成插入后，提前退出子程序
				q->next = node;
				node->next = p; 
				break;
			}
			else
			{
				//如果node节点的学号比p节点的学号大，继续向后移动指针（依然保持pq一前一后）
				q = p;
				p = p->next;
			}
		}
		//如果没能提前退出循环，则说明之前没有插入，那么当前node节点的学号是最大值，此时插在链表的最后面
		q->next = node;
	}
}

/**************************************************
函数：wr_user_info
作用：将用户信息写入文件
输入： head
输出： 
**************************************************/ 
void wr_user_info(Link head)
{
	FILE *fp;
	Link curr; 
	
	if((fp=fopen("database\\UserInf.dat","wb"))==NULL)
	{
		printf("\nUserInfo.txt error file");
		delay(3000);
		exit(1);//打开失败，退出程序
	}
	
	curr=head->next;
	while(curr!=NULL)
	{
		fwrite(&(curr->data),sizeof(USER),1,fp);
		curr=curr->next;
	}

	if(fclose(fp) != 0)//关闭文件
	{
		printf("\nError in closing file UserInfo.");
		delay(3000);
		exit(1);
	}
}
/**************************************************
函数：out_uinf
作用：输出用户信息 
输入：head
输出： 
**************************************************/
void out_uinf(Link head,int *page)
{
	int ys=0,i=0,line_y=75;
	int y=75,count=0;
	char y0[4];
	Link curr,node;	
	curr=head->next;
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
    outtextxy(600,450,y0);
    node=head->next;
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
				outtextxy(15,y,node->data.stuid);
				//outtextxy(155,y,node->data.name);
				puthz(155,y,node->data.name,16,16,BLACK);
				outtextxy(155+105,y,node->data.gender);
				outtextxy(155+105+105,y,node->data.class);
				puthz(500,y,"查看详情",16,16,LIGHTBLUE);
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
				outtextxy(15,y,node->data.stuid);
				//outtextxy(155,y,node->data.name);
				puthz(155,y,node->data.name,16,16,BLACK);
				outtextxy(155+105,y,node->data.gender);
				outtextxy(155+105+105,y,node->data.class);
				puthz(500,y,"查看详情",16,16,LIGHTBLUE);
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
				outtextxy(15,y,node->data.stuid);
				//outtextxy(155,y,node->data.name);
				puthz(155,y,node->data.name,16,16,BLACK);
				outtextxy(155+105,y,node->data.gender);
				outtextxy(155+105+105,y,node->data.class);
				puthz(500,y,"查看详情",16,16,LIGHTBLUE);
				node=node->next;
				y+=25;
			}
		}
	}
} 

/**************************************************
函数：sear_uinf
作用：查找用户信息 
输入：mode查找模式，1学号，2姓名，3班级 
输出：
**************************************************/
void sear_uinf(char str[],int mode,Link head)
{
	int flag=1,y=75,i=0,j=0;
	int count=1,curpg,curod;
	int line_y,all,page;
	int remember[20];
	Link p,node;
	node=head->next;
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
	puthz(15,56,"学号",16,16,LIGHTGRAY);
	puthz(155,56,"姓名",16,16,LIGHTGRAY); 
	puthz(155+105,56,"性别",16,16,LIGHTGRAY);
	puthz(155+105+105,56,"班级",16,16,LIGHTGRAY);
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
	setcolor(LIGHTGRAY);
	for(line_y=73;line_y<417;)
	{
		line(15,line_y,625,line_y);
		line_y+=25;
	} 
	setcolor(BLACK); 
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	
	p=head->next;
	while(p!=NULL && mode==1)
	{
		if (strcmp(p->data.stuid,str) == 0)
		{
	        flag=0;
	        outtextxy(15,y,p->data.stuid);
			//outtextxy(155,y,node->data.name);
			puthz(155,y,p->data.name,16,16,BLACK);
			outtextxy(155+105,y,p->data.gender);
			outtextxy(155+105+105,y,p->data.class);
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
		if (strstr(p->data.name,str) != NULL)
		{
	        flag=0;
	        outtextxy(15,y,p->data.stuid);
			//outtextxy(155,y,node->data.name);
			puthz(155,y,p->data.name,16,16,BLACK);
			outtextxy(155+105,y,p->data.gender);
			outtextxy(155+105+105,y,p->data.class);
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
		if (strstr(p->data.class,str) != NULL)
		{
	        flag=0;
	        outtextxy(15,y,p->data.stuid);
			//outtextxy(155,y,node->data.name);
			puthz(155,y,p->data.name,16,16,BLACK);
			outtextxy(155+105,y,p->data.gender);
			outtextxy(155+105+105,y,p->data.class);
			puthz(500,y,"查看详情",16,16,LIGHTBLUE);
			y+=25;
			p=p->next;
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
		else if(mouse_press(20,415,110,445)==1)//录入、点击 
		{
			return 30;
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
		
		else if (mouse_press(540,10,630,40) == 1)//返回、点击 
        {
        	MouseS = 0;
        	delay(100);
        	break;
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
					outuserdtil(head,&curpg,&curod);
					delay(100);
					sear_uinf(str,mode,head);
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
						outuserdtil(head,&curpg,&curod);
						delay(200);
						sear_uinf(str,mode,head);
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
						outuserdtil(head,&curpg,&curod);
						delay(200);
						sear_uinf(str,mode,head);
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
函数：insert_book
作用：书籍信息链表插入节点并排序 
输入： ID      编号 
	   Title   书名 
	   Author  作者 
	   head    链表头结点 
输出： 
**************************************************/
void insert_book(char ID[],char Title[],char Author[],BLink bhead) 
{
	// 创建新节点并设置数据
    BLink node;
    BLink p,q;
    if((node=(BLink)malloc(sizeof(BNode)))==NULL)
	{
		printf("memory error WrBookInf");
		delay(3000);			
		exit(1);//分配空间不足，退出程序
	}
    // 设置新节点的数据
    strcpy(node->data.bkid, ID);
    strcpy(node->data.title, Title);
    strcpy(node->data.author, Author);
    node->data.borrow_times=0;
	node->next = NULL;
	 
	q=bhead;
	p=bhead->next;
	if(bhead->next==NULL) //链表为空时
	{
		bhead->next = node;
		node->next=NULL;
	}
	else //循环访问链表中的所有节点
	{
		while(p != NULL)
		{
			if (strcmp(node->data.bkid,p->data.bkid)<0)
			{
				//如果node节点的学号比p节点的学号小，则插在p的前面，完成插入后，提前退出子程序
				q->next = node;
				node->next = p; 
				break;
			}
			else
			{
				//如果node节点的学号比p节点的学号大，继续向后移动指针（依然保持pq一前一后）
				q = p;
				p = p->next;
			}
		}
		//如果没能提前退出循环，则说明之前没有插入，那么当前node节点的学号是最大值，此时插在链表的最后面
		q->next = node;
	}
}
/**************************************************
函数：wr_book_info
作用：将书籍信息写入文件
输入： bhead
输出： 
**************************************************/
void wr_book_info(BLink bhead)
{
	FILE *fp;
	BLink curr; 
	
	if((fp=fopen("database\\BookInf.dat","wb"))==NULL)
	{
		printf("\nBookInfo.dat error file");
		delay(3000);
		exit(1);//打开失败，退出程序
	}
	
	curr=bhead->next;
	while(curr!=NULL)
	{
		fwrite(&(curr->data),sizeof(BOOK),1,fp);
		curr=curr->next;
	}

	if(fclose(fp) != 0)//关闭文件
	{
		printf("\nError in closing file BookInfo.");
		delay(3000);
		exit(1);
	}
} 
/**************************************************
函数：out_binf
作用：输出书籍信息 
输入：bhead
输出： 
**************************************************/
void out_binf(BLink bhead,int *page)
{
	int ys=0,i=0,line_y=75;
	int y=75,count=0;
	char y0[4];
	BLink curr,node;	
	curr=bhead->next;
	ys=(*page);
	
	while(curr!=NULL)
	{
		curr=curr->next;
		count++;
	}
	setcolor(WHITE);
	bar(598,448,630,470);
	itoa(ys,y0,10);
	setfillstyle(1,WHITE);
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
				outtextxy(15,y,node->data.bkid);
				puthz(155,y,node->data.title,16,16,BLACK);
				puthz(350,y,node->data.author,16,16,BLACK);
				puthz(500,y,"查看详情",16,16,LIGHTBLUE);
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
				outtextxy(15,y,node->data.bkid);
				puthz(155,y,node->data.title,16,16,BLACK);
				puthz(350,y,node->data.author,16,16,BLACK);
				puthz(500,y,"查看详情",16,16,LIGHTBLUE);
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
				outtextxy(15,y,node->data.bkid);
				puthz(155,y,node->data.title,16,16,BLACK);
				puthz(350,y,node->data.author,16,16,BLACK);
				puthz(500,y,"查看详情",16,16,LIGHTBLUE);
				node=node->next;
				y+=25;
			}
		}
	}
} 
/**************************************************
函数：sear_binf
作用：查找书籍信息 
输入：mode查找模式，1编号，2书名，3作者 
输出：
**************************************************/
void sear_binf(char str[],int mode,BLink bhead)
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
		if (strstr(p->data.author,str) != NULL)
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
		else if(mouse_press(20,415,110,445)==1)//录入、点击 
		{
			return 27;
		}
		else if(mouse_press(120,415,210,445)==1) //删除
		{
			userdel(bhead);
			clrmous(MouseX,MouseY); 
			delay(100);
			Draw_BookInfSearch();
			out_binf(bhead,&page);
			save_bk_mou(MouseX,MouseY);//存取鼠标背景
			drawmous(MouseX,MouseY);//画鼠标
		} 
		
		else if (mouse_press(540,10,630,40) == 1)//返回、点击 
        {
        	MouseS = 0;
        	delay(200);
        	break;
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
					outbookdtil(bhead,&curpg,&curod);
					delay(200);
					sear_binf(str,mode,bhead);
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
						outbookdtil(bhead,&curpg,&curod);
						delay(200);
						sear_binf(str,mode,bhead);
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
						outbookdtil(bhead,&curpg,&curod);
						delay(200);
						sear_binf(str,mode,bhead);
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
函数：sucdraw
作用：信息录入、删除、修改成功绘图 
输入： flag 0录入成功，1删除成功，2修改成功 
输出：
**************************************************/
void sucdraw(int flag)
{
	int i;
	cleardevice();
	delay(100);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setcolor(DARKGRAY);
	for(i=0;i<3;i++)
	{
		arc(307,194,0,360,86+i);
		line(270+i,188+i,261+i,204+i);
		line(270+i,188-i,299+i,209-i);
		line(299,209-i,352,166-i);
		line(352,166-i,357,172-i);

		line(305,237-i,356,174-i);
		line(305,237-i,260+i,204+i);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(302,218,DARKGRAY);  //对勾颜色 
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(310,142,DARKGRAY);
	 } 
	if(flag==0) 
	{
		puthz(250,327,"录入成功",32,33,GREEN);//输出字体 
	}
	if(flag==1)
	{
		puthz(250,327,"删除成功",32,33,GREEN);//输出字体 
	}
	if(flag==2)
	{
		puthz(250,327,"修改成功",32,33,GREEN);//输出字体 
	} 
	if(flag==3)
	{
		puthz(250,327,"借阅成功",32,33,GREEN);
	}
}

/**************************************************
函数：Link_free
作用：信息录入、删除、修改成功绘图 
输入： flag 0录入成功，1删除成功，2修改成功 
输出：
**************************************************/
void Link_free(Link head,BLink bhead)
{
	Link p = head, pr = NULL; //定义p指针指向头节点
	BLink q= bhead, qr = NULL;
    while (p != NULL)
    {                //当p的指针域不为NULL
        pr = p;      //将每一个节点的地址赋值给pr指针
        p = p->next; //使p指向下一个节点
        free(pr);
    }
    while (q != NULL)
    {                //当p的指针域不为NULL
        qr = q;      //将每一个节点的地址赋值给pr指针
        q = q->next; //使p指向下一个节点
        free(pr);
    }
}

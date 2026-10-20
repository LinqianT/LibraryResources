/**********************************************/
/*界面：数字资源访问平台
作者：dongyilei
功能：实现热门书籍的浏览并可以选择借阅 
函数 ：resource_platform;
		resource_platform_screen;
头文件：res_plat;
界面跳转：

*/ 
#include"common.h"
#include"res_plat.h"
#include"LogTools.h"
#include"timetool.h"
#include"Lend_mng.h"
int resource_platform(BLink bhead,USER1 *p1,Link head)
{
	BLink p=bhead->next;
	int i;
	char **temp;
	char **string;
	temp=(char **)malloc((sizeof(char *))*4);
	for(i=0;i<4;i++)
	{
		temp[i]=(char *)malloc(sizeof(char)*30); 
	}
	string=(char **)malloc((sizeof(char *))*4);
	for(i=0;i<4;i++)
	{
		string[i]=(char *)malloc(sizeof(char)*30);
	}
	/*p = (int **)malloc((sizeof(int*))*m); 
 
for (i=0;i<m;i++)
{
       p[i] = (int *)malloc(sizeof(int)*n); 
}*/

	//改一个暂时的数组去存储排名前三的书籍，让他记住书籍的名称，然后在判断mouse_pess,传参的时候就没有问题了 
	resource_platform_screen(bhead,temp);
	//传二维字符数组 
	for(i=0;i<4;i++)
	{
		strcpy(string[i],p->data.title); 
		p=p->next;
	}
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(550,430,620,470)==1)
		{
			cleardevice();
			save_bk_mou(MouseX,MouseY);
			clrmous(MouseX,MouseY);
			for(i=0;i<3;i++)
			{
				free(temp[i]);
			}
			free(temp);
			temp=NULL;
			for(i=0;i<3;i++)
			{
				free(string[i]);
			}
			free(string);
			string=NULL;
			return 4;
		}
		else if(mouse_press(140,150,220,170)==1)//1
		{
			save_bk_mou(MouseX,MouseY);
			clrmous(MouseX,MouseY);
			skimming(p1,string[0],head,bhead,temp);//传长度为20的一维字符数组 
		}
		else if(mouse_press(140+175,150,220+175,170)==1)//2
			{
				save_bk_mou(MouseX,MouseY);
				clrmous(MouseX,MouseY);
				skimming(p1,string[1],head,bhead,temp);
			}
		else if(mouse_press(140+175*2,150,220+175*2,170)==1)//3
		{
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			skimming(p1,string[2],head,bhead,temp);
		}
		else if(mouse_press(140,150+130,220,170+130)==1)//4
		{
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			skimming(p1,string[3],head,bhead,temp);
		}
		else if(mouse_press(140+175,150+130,220+175,170+130)==1)//5
		{
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			skimming(p1,string[4],head,bhead,temp);
		}
		else if(mouse_press(140+175*2,150+130,220+175*2,170+130)==1)//6
		{
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			skimming(p1,string[5],head,bhead,temp);
		}
		else if(mouse_press(140,150+130*2,220,170+130*2)==1)//7
		{
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			skimming(p1,string[6],head,bhead,temp);
		}
		else if(mouse_press(140+175,150+130*2,220+175,170+130*2)==1)//8
		{
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			skimming(p1,string[7],head,bhead,temp);
		}
		else if(mouse_press(140+175*2,150+130*2,220+175*2,170+130*2)==1)//9
		{
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			skimming(p1,string[8],head,bhead,temp);
		}
	}
	
}
char ** resource_platform_screen(BLink bhead,char **temp)
{
	int i,j;
	int k=0;
	BLink p;
	int v1[]={140,95,125,95,125,145,230,145,230,95,215,95};
	int	v2[]={178,95,140,80,140,130,178,145,215,130,215,80,178,95};
	int v3[]={140+175,95+130,125+175,95+130,125+175,145+130,230+175,145+130,230+175,95+130,215+175,95+130,140+175,95+130};
	int v4[]={178+175,95+130,140+175,80+130,140+175,130+130,178+175,145+130,215+175,130+130,215+175,80+130,178+175,95+130};
	int v5[]={140+175,95,125+175,95,125+175,145,230+175,145,230+175,145,230+175,95,215+175,95,140+175,95+130};
	int v6[]={178+175,95,140+175,80,140+175,130,178+175,145,215+175,130,215+175,80,178+175,95};
	int v7[]={140,95+130,125,95+130,125,145+130,230,145+130,230,145+130,230,95+130,215,95+130,140,95+130};
	int v8[]={178,95+130,140,80+130,140,130+130,178,145+130,215,130+130,215,80+130,178,95+130};
	int v9[]={140+175*2,95,125+175*2,95,125+175*2,145,230+175*2,145,230+175*2,95,215+175*2,95};
	int v10[]={178+175*2,95,140+175*2,80,140+175*2,130,178+175*2,145,215+175*2,130,215+175*2,80,178+175*2,95};
	int v11[]={140,95+130*2,125,95+130*2,125,145+130*2,230,145+130*2,230,95+130*2,215,95+130*2};
	int v12[]={178,95+130*2,140,80+130*2,140,130+130*2,178,145+130*2,215,130+130*2,215,80+130*2,178,95+130*2};
	int v13[]={140+175*2,95+130*2,125+175*2,95+130*2,125+175*2,145+130*2,230+175*2,145+130*2,230+175*2,95+130*2,215+175*2,95+130*2};
	int v14[]={178+175*2,95+130*2,140+175*2,80+130*2,140+175*2,130+130*2,178+175*2,145+130*2,215+175*2,130+130*2,215+175*2,80+130*2,178+175*2,95+130*2};
	int v15[]={140+175*2,95+130,125+175*2,95+130,125+175*2,145+130,230+175*2,145+130,230+175*2,95+130,215+175*2,95+130};//6
	int v16[]={178+175*2,95+130,140+175*2,80+130,140+175*2,130+130,178+175*2,145+130,215+175*2,130+130,215+175*2,80+130,178+175*2,95+130};//7
	int v17[]={140+175,95+130*2,125+175,95+130*2,125+175,145+130*2,230+175,145+130*2,230+175,95+130*2,215+175,95+130*2};
	int v18[]={178+175,95+130*2,140+175,80+130*2,140+175,130+130*2,178+175,145+130*2,215+175,130+130*2,215+175,80+130*2,178+175,95+130*2};
	p=bhead->next;
	sortbylend(bhead);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setfillstyle(1,15);
	bar(40,60,600,420);
	setcolor(BLACK);
	rectangle(40,60,600,420);
	line(40,180,600,180);
	line(40,200,600,200);
	line(40,300,600,300);
	line(40,320,600,320);
	rectangle(550,430,620,470);
	setfillstyle(1,7);
	bar(550+2,430+2,620+2,470+2);
	puthz(550+5,430+5,"返回",32,32,BLACK);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			line(178+175*(i-1),95+130*(j-1),178+175*(i-1),145+130*(j-1));
		}
		
	}
		setcolor(BLACK);
		drawpoly(6,v1);
		drawpoly(7,v2);
		drawpoly(6,v3);
		drawpoly(7,v4);
		drawpoly(7,v5);
		drawpoly(7,v6);
		drawpoly(7,v7);
		drawpoly(7,v8);
		drawpoly(6,v9);
		drawpoly(7,v10);
		drawpoly(6,v11);
		drawpoly(7,v12);
		drawpoly(6,v13);
		drawpoly(7,v14);
		drawpoly(6,v15);
		drawpoly(7,v16);
		drawpoly(6,v17);
		drawpoly(7,v18);
		for(i=0;i<3;i++)
		{
			if(p!=NULL)
			{
				for(j=0;j<3;j++)
				{
					if(p!=NULL)
					{
						puthz(140+175*j,150+130*i,p->data.title,16,16,BLACK); 
						strcpy(temp[k],p->data.title);
						k++;
						p=p->next;
					}
					
				}
			}
		}
	return temp;
}
void skimming(USER1*p1,char book_name[],Link head,BLink bhead,char **temp)
              //p1       temp[0]          head        bhead         temp
//传进来当前用户结构体，书名，用户头指针，书籍头指针，排名前三读的书（resource_platform_screen要用到后两个形参） 
{
	Link p;
	BLink curr; 
	p=head->next;
	curr=bhead->next;
	skimming_screen(book_name);
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);
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
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(580,400,630,450)==1)//返回 
		{
			delay(100); 
			save_bk_mou(MouseX,MouseY);
			clrmous(MouseX,MouseY);
			resource_platform_screen(bhead,temp);
			break;
		} 
		else if(mouse_press(300,400,450,450)==1)//确认借阅 
		{
		 	//要处理：将借阅信息写进链表，将借阅信息写入当前用户， 画出借阅成功的界面，返回浏览排名前三的书籍，借阅时间，借阅次数 
			//形参可传：当前用户结构体，书名，用户头指针，书籍头指针，排名前三读的书
			//(USER1*p1,char book_name[],Link head,BLink bhead,char **temp)
			//遍历链表，找到当前用户的学号（比较p1->study_id和p->data.stuid）(写到else外面比较好以免嵌套结构太复杂)
			//1.单独遍历书籍的链表，要读到书籍的借阅次数 ,没有借满的话将借阅信息写入链表并复制给当前用户p1 
			//2.读取用户借阅时间并写入链表
			//3.借阅次数随着点击的次数++并写入书籍的链表
			//4.画出借阅成功的界面
			//5.delay之后调用函数resource_platform_screen,回到当前界面的主函数
			while(curr!=NULL)
			{
				
				if(strcmp(curr->data.title,book_name)==0)
				{
					break;
				}
				else 
				{
					curr=curr->next;
				}
			}
			if(strcmp(p->data.borrow_book1,"")!=0)
			{
				if(strcmp(p->data.borrow_book2,"")!=0)
				{
					if(strcmp(p->data.borrow_book3,"")!=0)
					{
						puthz(50,400,"借阅数目已达上限！",24,24,WHITE);
					}
					else 
					{
						strcpy(p->data.borrow_book3,book_name);
						strcpy(p1->borrow_book[2],book_name);
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
						p->data.borrow_state=1;
						wr_user_info(head);
						curr->data.borrow_times++;
						wr_book_info(bhead);
						drawpage_scborrow();
						delay(500);
						resource_platform_screen(bhead,temp);
						break;
					}
				}
				else
				{
					strcpy(p->data.borrow_book2,book_name);
					strcpy(p1->borrow_book[1],book_name);
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
					p->data.borrow_state=1;
					wr_user_info(head);
					curr->data.borrow_times++;
					wr_book_info(bhead);
					drawpage_scborrow();
					delay(500);
					resource_platform_screen(bhead,temp);
					break;
				}
			} 
			else 
			{
				strcpy(p->data.borrow_book1,book_name);
				strcpy(p1->borrow_book[0],book_name);
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
				p->data.borrow_state=1;
				wr_user_info(head);
				curr->data.borrow_times++;
				wr_book_info(bhead);
				drawpage_scborrow();
				delay(500);
				resource_platform_screen(bhead,temp);
				break;
			}
		}	
	}
}
void skimming_screen(char *book_name)
{
	char *book1="追风筝的人";
	char *book2="肖申克的救赎";
	char *book3="红楼梦"; 
	char string[500];
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setfillstyle(1,6);
	bar(40,40,240,300);
	setfillstyle(1,4);
	pieslice(150,140,0,180,40);
	setfillstyle(1,14);
	pieslice(150,140,180,360,40);
	setcolor(BLACK); 
	line(189,245,45,80);
	setcolor(BLACK);
	rectangle(580,400,630,450);
	rectangle(300,400,450,450);
	setfillstyle(1,7);
	bar(580+2,400+2,630+2,450+2);
	bar(300+3,400+3,450+3,450+3);
	puthz(300+5,400+10,"确认借阅",32,32,BLACK);
	puthz(580+5,400+20,"返回",24,24,BLACK);
	setfillstyle(1,15);
	bar(250,40,635,390);
	puthz(255,50,"书名：",32,32,BLACK);
	puthz(350,50,book_name,32,32,BLACK);
	if(strcmp(book_name,"")!=0)
	{
		if(strcmp(book_name,book1)==0)
		{
			puthz(40+5,40+5,"风筝的人",32,32,YELLOW);
			puthz(190,250,"追",48,48,YELLOW);
			puthz(255,85,"简介：该书是美籍阿富汗作家卡勒德胡赛尼创作的第一部长篇小说，全书围绕风筝与阿富汗的两个少年展开，讲述了一个富家少年与家中仆人，关于人性的背叛与救赎的故事。小说属于成长类文学范畴的作品，描写了主人公阿米尔寻求灵魂救赎的成长历程，作者想要呼唤人们的良知，告诫人们要善良。",24,24,BLACK);
		}
		else if(strcmp(book_name,book2)==0)
		{
			puthz(40+5,40+5,"救赎",32,32,YELLOW);
			puthz(120,250,"肖申克的",32,32,YELLOW);
			puthz(255,85,"《肖申克的救赎》是美国作家斯蒂芬·埃德温·金的中篇小说，也是其代表作。收录于小说合集《四季奇谭》中，副标题为“春天的希望”。斯蒂芬·金塑造的安迪却像一只浴火后重生的火凤凰，健康自信地飞出了炼狱的火坑。这样的结果同样寄托着作者要使荒原上的人们坚守善良人性并“振奋”起来的创作主旨。",24,24,BLACK);
		}
		else if(strcmp(book_name,book3)==0)
		{
			puthz(40+5,40+5,book_name,32,32,YELLOW); 
			puthz(255,85,"《红楼梦》是一部百科全书式的长篇小说。以宝黛爱情悲剧为主线，以四大家族的荣辱兴衰为背景，描绘出十八世纪中国封建社会的方方面面，以及封建专制下新兴资本主义民主思想的萌动。结构宏大、情节委婉、细节精致，人物形象栩栩如生，声口毕现，堪称中国古代小说中的经典。",24,24,BLACK);
		}
		else 
		{
			puthz(40+5,40+5,book_name,32,32,YELLOW);
			puthz(255,85,"这本书展现了作者深刻的洞察力和丰富的想象力。通过生动的描述和细腻的情感描写，读者仿佛置身于故事中心。作品的篇章结构紧凑，情节紧凑，引人入胜，读者很容易沉浸其中，难以自拔。作者的笔触纯熟、细腻，每一个细节都展现了作者对日常生活的观察和思考。人物形象栩栩如生，情感真挚动人。",24,24,BLACK);
			
		}
	}
	else
	{
			
			printf("2222");
	}
	delay(500);
	
	
}
void drawpage_scborrow()
{
	setfillstyle(1,CYAN);
	bar(200,150,440,330);
	bar(240,190,400,290);
	setfillstyle(1,15);
	bar(220,170,420,310);
	bar(260,210,380,270);
	puthz(240,225,"借阅成功！",32,32,BLACK);
	save_bk_mou(MouseX,MouseY);
	clrmous(MouseX,MouseY);
}
 

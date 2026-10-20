#include"common.h"
#include"Mb_add.h"
#include"LogTools.h"

/*书籍信息添加界面 
	功能：输入书名、编号、作者、简介 
*/ 

int bookmng_add(BLink bhead)
{
	int len1=0;
	int len2=0;
	char title[20]={'\0'};
	char author[20]={'\0'};
	INPUT bkid ={90,68,450,97,"",3,0,0};

	clrmous(MouseX,MouseY); 
	delay(100);
	Draw_bookmngadd();
	save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	while(1)
	{
		input_s(90+4,68+4,&bkid,7,0);
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(540,10,630,40)==2||mouse_press(440,10,530,40)==2)//返回、确认，未点击 
		{
			MouseS=1;
			continue;
		}
		else if(mouse_press(540,10,630,40)==1)//返回、点击
		{
			return 26;
		}
		else if(mouse_press(90,118,450,147)==1)
		{
			len1=hz_input(90,118,450,147+10,title,len1,WHITE);
		}
		else if(mouse_press(90,168,450,197)==1)
		{
			len2=hz_input(90,168,450,197+10,author,len2,WHITE);
		}
		else if(mouse_press(440,10,530,40)==1)//确认、点击 
		{
			//清除提示信息
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			bar(450,68,620,450);
			
			//判断是否输入完全
			if(bkid.string[0]=='\0')
			{
				puthz(450+4,68+3,"请输入编号",16,16,RED);
			}
			if(title[0]=='\0')
			{
				puthz(450+4,118+3,"请输入书名",16,16,RED);
			}
			if(author[0]=='\0')
			{
				puthz(450+4,168+3,"请输入作者",16,16,RED);
			}
			if(bkid.string[0]!='\0' && title[0]!='\0' && author[0]!='\0')//已输入
			{
				if(judge_samebkid(bkid.string,bhead)==0)
				{
					puthz(450+4,68+3,"编号已存在",16,16,RED);
				}
				//写入书籍信息
				else
				{
					insert_book(bkid.string,title,author,bhead);
					wr_book_info(bhead);
					sucdraw(0);
					delay(1000);
					return 26;
				}
			}
			continue;
		}
		else //无操作 
		{
			MouseS=0;
			continue;
		}		
	} 

}

void Draw_bookmngadd() 
{
	cleardevice();	
	setfillstyle(1,BLUE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(10,50,630,470);
	
	puthz(20,17,"录入新书籍",24,24,WHITE);
	puthz(20,70,"编号",24,24,DARKGRAY);
	puthz(20,120,"书名",24,24,DARKGRAY);
	puthz(20,170,"作者",24,24,DARKGRAY); 
	//puthz(20,220,"简介",24,24,DARKGRAY); 

	setfillstyle(1,WHITE);
	bar(90,68,450,97);
	bar(90,118,450,147);
	bar(90,168,450,197);
	//bar(90,220,450,460);
	
	setfillstyle(1,LIGHTGRAY);
	bar(442,12,532,42);
	setfillstyle(1,WHITE); 
	bar(440,10,530,40);
	puthz(460,17,"确认",24,24,BLACK); 
	//返回查询界面AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA	
	setfillstyle(1,LIGHTGRAY);
	bar(542,12,632,42);
	setfillstyle(1,WHITE); 
	bar(540,10,630,40);
	puthz(560,17,"返回",24,24,BLACK); 
}

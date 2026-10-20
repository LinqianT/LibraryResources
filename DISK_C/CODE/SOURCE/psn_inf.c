/**************************************************/
/*页面 ：psn/-inform;
  作者：dongyilei;
  功能：实现个人信息的修改和填写，可以记录用户的个人资料；
  函数 ：(1)personal_information_screen;
  		 (2)personal_information;
		(3)input_inform;
  页面跳转：(1)personal_information;
   			(2)persona_center;
	*/ 

#include"common.h"
#include"LogTools.h"
#include"psn_inf.h"
int personal_information(USER1 *p1,Link head)//修改个人信息 
{
  	INPUT myclass ={220,165,500,200,"",20,0,0};
	INPUT stuid ={220,215,500,250,"",3,0,0};
	INPUT gender ={220,265,500,300,"",10,0,0};
	INPUT age ={220,315,500,350,"",12,0,0};
	INPUT astring ={220,365,500,400,"",20,0,0};
	int len=0;
	char name[20]={'\0'};
	Link p;
	p=head->next;
	psn_inform_screen(p1);
	while(1)
	{
		input_s(220+4,165+4,&myclass,7,0);
		input_s(220+4,215+4,&stuid,7,0);
		input_s(220+4,265+4,&gender,7,0);
		input_s(220+4,315+4,&age,7,0);
		input_s(220+4,365+4,&astring,7,0);
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(515,160,635,210)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 10;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(515,295,635,345)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			return 10;
			save_bk_mou(MouseX,MouseY);
			drawmous(MouseX,MouseY);
		}
		else if(mouse_press(540,10,630,40)==1)
		{
			cleardevice();
			clrmous(MouseX,MouseY);
			save_bk_mou(MouseX,MouseY);
			return 5;
		}
		else if(mouse_press(90,118,450,147)==1)
		{
			len=hz_input(220,115,500,150,name,len,WHITE);
		}
		else if(mouse_press(500,400,630,470)==1)
		{
			if(name[0]!='\0')
				strcpy(p1->name,name);
			if(myclass.string[0]!='\0')
				strcpy(p1->my_class,myclass.string);
			if(gender.string[0]!='\0')
				strcpy(p1->gender,gender.string);
			if(astring.string[0]!='\0')
				strcpy(p1->string,astring.string);
			if(age.string[0]!='\0')
				strcpy(p1->age,age.string);
			while(p!=NULL)
			{
				if(strcmp(p1->study_id,p->data.stuid)==0)
				{
					strcpy(p->data.name,p1->name);
					strcpy(p->data.class,p1->my_class);
					strcpy(p->data.gender,p1->gender);
					strcpy(p->data.string,p1->string);
					strcpy(p->data.age,p1->age);
					wr_user_info(head);
					delay(100);
					cleardevice();
					clrmous(MouseX,MouseY);
					return 5;
					save_bk_mou(MouseX,MouseY);
					drawmous(MouseX,MouseY);
				}
				else 
				{
					p=p->next;
				}
			}
		}
		
	}

}
void psn_inform_screen(USER1 *p1)//个人信息修改界面的图 
{
	
	setbkcolor(BLACK);
	setfillstyle(1,1);
	bar(0,0,640,480);
	setcolor(WHITE);
	rectangle(210,10,470,75);
	setfillstyle(1,15);
	bar(220,115,500,150);
	bar(220,165,500,200);
	bar(220,215,500,250);
	bar(220,265,500,300);
	bar(220,315,500,350);
	bar(220,365,500,400);
	puthz(210+60,10+15,"个人资料",32,32,WHITE);
	puthz(100+10,100+10,"姓名",32,32,WHITE);
	setcolor(BLACK); 
	settextstyle(2,0,8);
	outtextxy(220+2,215+2,p1->study_id);
	puthz(100+10,155+10,"班级",32,32,WHITE);
	puthz(100+10,205+10,"学号",32,32,WHITE);
	puthz(100+10,255+10,"性别",32,32,WHITE);
	puthz(100+10,308+10,"年龄",32,32,WHITE);
	puthz(60+10,355+10,"个人签名",32,32,WHITE);
	setfillstyle(1,7);
	setcolor(BLACK);
	bar(500+1,400+1,630+1,470+1);
	rectangle(500,400,630,470);
	puthz(500+20,400+15,"确定",48,48,BLACK);
	setfillstyle(1,WHITE); 
	bar(540,10,630,40);
	bar(542,12,632,42);
	puthz(560,17,"退出",24,24,BLACK); 
	
}
char input_inform(char* inform,int x,int y,int lim,int color,int n)
{
	int i=0;                                       
	int j=0;  
	char c;        
	FILE *fp;
	fp=fopen("c:\\CODE\\file\\user.txt","a+");
	fseek(fp,n,0) ;                                                                         //读取键盘输入的内容
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL,color);                    //设置填充形式
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);             //设置线型
	setcolor(BLACK);                                   //设置输出形式
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	line(x+10,y+6, x+10,y+25);                         //画输入提示光标
	while(bioskey(1))
	{
		i=bioskey(0);
	}
	while(1)
	{
	    c=bioskey(0);  
		fputc(c,fp); 
		fflush(fp);  
		if(j<lim)
		{
			if(c!='\n'&&c!='\r'&&c!=' '&&c!=033)       //如果读入非换行、回车、空格或退出
			{
				if(c!='\b')                            //如果读入非退格
				{
					*(inform+j)=c;                         //将读入的c存入输入内容字符串name
					*(inform+j+1)='\0';                    //结束字符串name
					bar(x+8+j*18,y+3,x+12+j*18,y+24);  //清除光标（注意在原光标坐标上加上已经输入的内容）
					outtextxy(x+8+j*18,y-1,inform+j);      //在输入框中显示输入的字符（在其实光标右侧j*18处画字符）
					j++;                               //输入数加一
					line(x+10+j*18,y+6,x+10+j*18,y+20);//在新输入的字符后重画光标
				}
				else if (c=='\b'&&j>0)                 //如果读入退格
				{
					bar(x-10+j*18,y+3,x+7+j*18,y+24);  //清除上一输入字符
					bar(x+8+j*18,y+3,x+12+j*18,y+24);  //清除光标
					j--;                               //输入数减一
					line(x+10+j*18,y+6,x+10+j*18,y+20);//在上一输入的字符后重画光标
					*(inform+j)='\0';                      //清除字符串name读入的上一字符
					*(inform+j+1)='\0';                    //结束字符串name
				}
			}
			else                                       //如果读入换行、回车、空格或退出
			{
				setfillstyle(SOLID_FILL, color);       //结束当前输入操作
				bar(x+8+j*18,y+3,x+12+j*18,y+24);      //清除光标
				break;
			}
		}
		else if(j>=lim)                               //如果达到输入限制
		{
			if(c!='\n'&&c!='\r'&&c!=' '&&c!=033)      //其余功能不变
			{                                         //读入除换行、回车、空格、退出或退格以外字符不再存储与显示
				if(c=='\b'&&j>0)
				{
					bar(x+8+j*18,y+3,x+12+j*18,y+24);
					bar(x-10+j*18,y+3,x+7+j*18,y+24);
					j--;
					line(x+10+j*18,y+6,x+10+j*18,y+20);
					*(inform+j)='\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x+8+j*18,y+3,x+12+j*18,y+24); 
				break;
			}
		}                            //读取键盘输入内容
	}
	fclose(fp);

}


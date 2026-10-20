 //图书馆座位管理界面
#include"common.h"
#include"Ms_sec.h" 
#include"sec_resv.h"
int mseat_sec(Link head) 
{
	Link curr;
	Link temp[20];
	int count=0,i=0;
	clrmous(MouseX,MouseY); 
	delay(100);
	sec_resv_screen(head);
	curr=head->next;
	while(curr!=NULL)
	{
		if(curr->data.seat_state==1 && curr->data.resv_floor==2)
		{
			temp[i]=curr;
			i++;
			count=i;
		}
		curr=curr->next;
	}
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(560,420,620,460)==2)
		{
			MouseS=1;
			continue; 
		}
		else if(mouse_press(560,420,620,460)==1)
		{
			return 33;
		}
		else
		{
			for(i=0;i<count;i++)
			{
				if(mouse_press(temp[i]->data.x1,temp[i]->data.y1,temp[i]->data.x2,temp[i]->data.y2)==1)
				{
					outseatdtil(temp[i]);
					clrmous(MouseX,MouseY); 
					delay(300);
					sec_resv_screen(head);
				}
			}
			MouseS=0;
			continue;
		}
	}
}

void outseatdtil(Link curr)
{
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
    puthz(140, 130, "座位预约详情", 24, 32, DARKGRAY);
    puthz(140, 180, "学号", 24, 24, BLACK);
	puthz(140,220+5,"姓名",24,24,BLACK);
	puthz(140,260+10,"班级",24,24,BLACK); 
	settextstyle(SMALL_FONT,HORIZ_DIR,8);
	outtextxy(180+30,180,curr->data.stuid);
	puthz(180+30,220+5,curr->data.name,24,24,BLACK);
	outtextxy(180+30,260+10,curr->data.class);
	
	save_bk_mou(MouseX,MouseY);//存取鼠标背景
	drawmous(MouseX,MouseY);//画鼠标
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(480, 120, 520, 170) == 2) 
		{
			MouseS=1;
			continue;
		}
		if(mouse_press(480, 120, 520, 170) == 1)
        {
            MouseS = 0;
            break; //退出
        }
        else
        {
            MouseS = 0;
            continue; 
        }
	}
} 


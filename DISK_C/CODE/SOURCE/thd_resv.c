#include"common.h"
#include"thd_resv.h"
#include"sec_resv.h"
#include"LogTools.h"
int thd_floor_resv(USER1 *p1,Link head)
{
	int i;
	int j;
	int state=0;
	int pre_state=0;
	Link n;
	n=head->next;
	p1->seat_state=1;
	thd_resv_screen(head);
	delay(300);
	setfillstyle(1,2);
	while(n!=NULL)
	{
		if(strcmp(p1->study_id,n->data.stuid)==0)
		{
			while(1)
			{
				newmouse(&MouseX,&MouseY,&press);
			
				for(i=1;i<5;i++)
				{
					if(mouse_press(215,30+30*(i-1),235,50+30*(i-1))==1)
					{
						draw_seat(215,30+30*(i-1),235,50+30*(i-1),1+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(215,170+30*(i-1),235,190+30*(i-1))==1)
					{
						draw_seat(215,170+30*(i-1),235,190+30*(i-1),9+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(340,30+30*(i-1),360,60+30*(i-1))==1)
					{
						draw_seat(340,30+30*(i-1),360,50+30*(i-1),2+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(340,170+30*(i-1),360,190+30*(i-1))==1)
					{
						draw_seat(340,170+30*(i-1),360,190+30*(i-1),10+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(215,310+30*(i-1),235,330+30*(i-1))==1)
					{
						draw_seat(215,310+30*(i-1),235,330+30*(i-1),17+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(340,310+30*(i-1),360,330+30*(i-1))==1)
					{
						draw_seat(340,310+30*(i-1),360,330+30*(i-1),18+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(380,30+30*(i-1),400,50+30*(i-1))==1)
					{
						draw_seat(380,30+30*(i-1),400,60+50*(i-1),25+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(505,30+30*(i-1),525,50+30*(i-1))==1)
					{
						draw_seat(505,30+30*(i-1),525,50+30*(i-1),26+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(380,170+30*(i-1),400,190+30*(i-1))==1)
					{
						draw_seat(380,170+30*(i-1),400,190+30*(i-1),33+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(505,170+30*(i-1),525,190+30*(i-1))==1)
					{
						draw_seat(505,170+30*(i-1),525,190+30*(i-1),34+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(380,310+30*(i-1),400,330+30*(i-1))==1)
					{
						draw_seat(380,310+30*(i-1),400,330+30*(i-1),41+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(505,310+30*(i-1),525,330+30*(i-1))==1)
					{
						draw_seat(505,310+30*(i-1),525,330+30*(i-1),42+2*(i-1),n,head,p1,3);
						thd_resv_screen(head);
					}
					else if(mouse_press(560,420,620,460)==1)
					{
						save_bk_mou(MouseX,MouseY);
						clrmous(MouseX,MouseY);
						delay(100);
						return 9;
					}
				} 
			}
		}
		else 
		{
			n=n->next;
		}
		
	}
		
}
void thd_resv_screen(Link head)
{
	
	Link m;
	int i,j,k;
	int a,b,c;
	int v1[]={215,30,215,50,235,50,235,60,215,60,215,80,235,80,235,90,215,90,215,110,235,110,235,120,215,120,215,140,235,140,360,140,360,120,340,120,340,110,360,110,360,90,340,90,340,80,360,80,360,60,340,60,340,50,360,50,360,30,340,30,215,30};
	int v2[]={380,30,380,50,400,50,400,60,380,60,380,80,400,80,400,90,380,90,380,110,400,110,400,120,380,120,380,140,400,140,525,140,525,120,505,120,505,110,525,110,525,90,505,90,505,80,525,80,525,60,505,60,505,50,525,50,525,30,505,30,380,30};
	int v3[]={215,170,215,190,235,190,235,200,215,200,215,220,235,220,235,230,215,230,215,250,235,250,235,260,215,260,215,280,235,280,360,280,360,260,340,260,340,250,360,250,360,230,340,230,340,220,360,220,360,200,340,200,340,190,360,190,360,170,340,170,215,170};
	int v4[]={380,170,380,190,400,190,400,200,380,200,380,220,400,220,400,230,380,230,380,250,400,250,400,260,380,260,380,280,400,280,525,280,525,260,505,260,505,250,525,250,525,230,505,230,505,220,525,220,525,200,505,200,505,190,525,190,525,170,505,170,380,170} ;
	int v5[]={215,310,215,330,235,330,235,340,215,340,215,360,235,360,235,370,215,370,215,390,235,390,235,400,215,400,215,420,360,420,360,400,340,400,340,390,360,390,360,370,340,370,340,360,360,360,360,340,340,340,340,330,360,330,360,310,215,310};
	int v6[]={380,310,380,330,400,330,400,340,380,340,380,360,400,360,400,370,380,370,380,390,400,390,400,400,380,400,380,420,525,420,525,400,505,400,505,390,525,390,525,370,505,370,505,360,525,360,525,340,505,340,505,330,525,330,525,310,380,310};
	setbkcolor(BLACK);
	setfillstyle(1,15);
	bar(0,0,640,480);
	rectangle(55,95,200,375);
	drawpoly(31,v1);
	drawpoly(31,v2);
	drawpoly(31,v3);
	drawpoly(31,v4);
	drawpoly(29,v5);
	drawpoly(29,v6);
	puthz(55+5,160+20,"书架区",32,32,BLACK);
	setcolor(BLACK);
	rectangle(560,420,625,460);
	setfillstyle(1,7);
	bar(560+2,420+2,625+2,460+2);
	puthz(560+2,420+2,"返回",32,32,BLACK);
	for(i=1;i<=4;i++)
	{
		line(235,30*i,235,30*i+20);
	}
	for(j=1;j<=4;j++)
	{
		line(340,30*j,340,30*j+20);
	}
	for(k=0;k<4;k++)
	{
		line(235,170+30*k,235,190+30*k);
		
	}
	for(a=0;a<4;a++)
	{
		line(340,170+30*a,340,190+30*a);
	}
	for(b=0;b<4;b++)
	{
		line(400,30+30*b,400,30*b+30+20);
	}
	for(c=0;c<4;c++)
	{
		line(505,30+30*c,505,30+30*c+20);
	}
	for(i=0;i<4;i++)
	{
		line(400,170+30*i,400,190+30*i);
	}
	for(j=0;j<4;j++)
	{
		line(505,170+30*j,505,190+30*j);

	}
	for(k=0;k<4;k++)
	{
		line(235,310+30*k,235,330+30*k);
	}
	for(a=0;a<4;a++)
	{
		line(340,310+30*a,340,330+30*a);
	}
	for(b=0;b<4;b++)
	{
		line(400,310+30*b,400,330+30*b);
	}
	for(c=0;c<4;c++)
	{
		line(505,310+30*c,505,330+30*c);
	}
	settextstyle(1,0,1);
	for(i=0;i<2;i++)
	{
		for(j=0;j<12;j++)
		{
			if(j<=3)
			{
				char str1[20];
				itoa(2*(j+1)-1+i,str1,10);
				outtextxy(220+125*i,30+30*j,str1);
			}
			
			else if((j>3)&&(j<=7))
			{
				char str2[20];
				itoa(2*(j+1)-1+i,str2,10);
				outtextxy(215+125*i,170+30*(j-4),str2);
			}
			else if((j>7)&&(j<=11))
			{
				char str3[20];
				itoa(2*(j+1)-1+i,str3,10);
				outtextxy(215+125*i,310+30*(j-8),str3);
			}
		}
		
	}
	 for(i=0;i<2;i++)
	{
		for(j=0;j<12;j++)
		{
			if(j<=3)
			{
				char str1[20];
				itoa(2*(j+1)-1+i+24,str1,10);
				outtextxy(380+125*i,30+30*j,str1);
			}
			
			else if((j>3)&&(j<=7))
			{
				char str2[20];
				itoa(2*(j+1)-1+i+24,str2,10);
				outtextxy(380+125*i,170+30*(j-4),str2);
			}
			else if((j>7)&&(j<=11))
			{
				char str3[20];
				itoa(2*(j+1)-1+i+24,str3,10);
				outtextxy(380+125*i,310+30*(j-8),str3);
			}
		}
		
	}
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);
	m=head->next;
	while(m!=NULL)
	{	if(m->data.resv_floor==3)
		{
			if(m->data.seat_state==1)
			{
				setfillstyle(1,GREEN);
				bar(m->data.x1,m->data.y1,m->data.x2,m->data.y2);
				puthz(m->data.x1,m->data.y1,"人",16,16,BLACK);
				m=m->next;
				continue;
			}
			else
			{
				m=m->next;
			}
		}
		else 
		{
			m=m->next;
		}
	}
}


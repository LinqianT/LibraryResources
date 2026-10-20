 //图书馆座位管理界面
#include"common.h"
#include"Ms_sec.h" 
#include"thd_resv.h"
#include"Ms_thd.h" 
int mseat_thd(Link head) 
{
	Link curr;
	Link temp[20];
	int count=0,i=0;
	clrmous(MouseX,MouseY); 
	delay(100);
	thd_resv_screen(head);
	curr=head->next;
	while(curr!=NULL)
	{
		if(curr->data.seat_state==1 && curr->data.resv_floor==3)
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
					thd_resv_screen(head);
				}
			}
			MouseS=0;
			continue;
		}
	}
}


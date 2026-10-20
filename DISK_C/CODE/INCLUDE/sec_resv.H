#ifndef _SEC_RESV_H_
#define _SEC_RESV_H_


int sec_floor_resv(USER1 *p1,Link head);
void draw_seat(int x1,int y1,int x2,int y2,int seat,Link p,Link head,USER*p1,int floor);
void sec_resv_screen(Link head);
int choose_seat_screen(Link head,Link p);
int  judge_seat(int x1,int y1,int x2,int y2,Link head,int floor);

#endif

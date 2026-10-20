#ifndef _MY_COL_H_
#define _MY_COL_H_

int my_collection(USER1*p1,Link head,BLink bhead);
void collection_screen(Link p);
int add_page();
void collection_screen_new(Link p,Link head);
int judge_borrow_room(Link p);
int judge_borrow_book(BLink curr,Link p);
#endif

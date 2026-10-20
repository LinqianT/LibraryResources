#ifndef _UB_SEAR_H_
#define _UB_SEAR_H_

int bookuser_search(BLink bhead,Link head,USER1 *p1);
void Draw_bookInfSearch();
void out_bookdtil(BLink bhead,int *page,int *order,Link head,USER1 *p1);
void drawpage_borrow();
void sear_u_binf(char str[],int mode,BLink bhead,USER*p1,Link head);



#endif

#ifndef _LEND_MNG_H_
#define _LEND_MNG_H_

int lending_mng(Link head,BLink bhead);
void Draw_lendmain();
void Draw_lendlist(Link head,BLink bhead);
void out_ranklist(Link head,BLink bhead);
void Draw_liushui(Link head);
void initexcel(Excel_data arr[]);
void sortbylend(BLink bhead);
void sortbybkid(BLink bhead);
void out_binfbylend(BLink bhead,int *page);
void out_ulendtime(Link temp[],int *page,int count);

#endif

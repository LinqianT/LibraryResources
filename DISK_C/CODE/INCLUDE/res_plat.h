#ifndef _RES_PLAT_H_
#define _RES_PLAT_H_

int resource_platform(BLink bhead,USER1 *p1,Link head);
char ** resource_platform_screen(BLink bhead,char **temp);
void skimming(USER1*p1,char book_name[],Link head,BLink bhead,char **temp);
void skimming_screen(char *book_name);
void drawpage_scborrow();


#endif 


/**************************************************
File Name: LogTools.h

Description: 用户及书籍信息处理所需的工具函数的头文件
Function List: input_s  键盘输入函数
               judge_samestuid  判断学号是否存在 
			   judge_ID  判断身份证号是否符合要求
			   judge_password  判断密码是否符合要求
			   wr_user_info  将注册信息写入文件
			   right_key  判断密码是否正确
			   wr_usernow  写入登录信息
			   right_ID  判断身份证号是否正确
			   re_user_info  将新密码写入文件
**************************************************/

#ifndef _LOGTOOLS_H_
#define _LOGTOOLS_H_

void input_s(int x,int y,INPUT *word,int size,int mode);
Link nodeinit(Link head);
BLink bnodeinit(BLink bhead);

int judge_samestuid(char stuid[],Link head);
int judge_samebkid(char ID[],BLink bhead);

int judge_password(char password[]);

void insert_user(char Name[],char sex[],char ID[],char key[],char Class[],Link head); 
void wr_user_info(Link head);
void out_uinf(Link head,int *page);
void sear_uinf(char str[],int mode,Link head);

void insert_book(char ID[],char Title[],char Author[],BLink bhead); 
void wr_book_info(BLink bhead);
void out_binf(BLink bhead,int *page);
void sear_binf(char str[],int mode,BLink bhead);

void sucdraw(int flag); 
void Link_free(Link head,BLink); 

#endif


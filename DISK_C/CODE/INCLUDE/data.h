#ifndef _DATA_H_
#define _DATA_H_ 


typedef struct
{
	int x1;//输入框坐标
	int y1;
	int x2;
	int y2;
	char string[19];
	char length;//输入的最大长度
	char cursor;//光标位置
	char flag;//0代表不能输入，1代表可以输入
}INPUT;

typedef struct User
{
	char stuid[10];//学号
	char name[20]; // 姓名
	char class[10];//班级
	char gender[6];//性别
	char password[12];//密码
	char seat[10];
	char borrow_book1[20];
	char borrow_book2[20];
	char borrow_book3[20];
	int x1;
	int y1;
	int x2;
	int y2;
	int resv_floor;
	int seat_state;
	char collect_book1[20];
	char collect_book2[20];
	char collect_book3[20];
	char string[30];
	char age[5];
	char balance[5];
	char arrears[5];
	char payment[10];
	int  borrow_state;
	char borrow_time1[30];
	char borrow_time2[30];
	char borrow_time3[30];
}USER;//用户信息
typedef struct node
{
	struct User data; //数据域
	struct node *next; //指针域
}Node,*Link; 

typedef struct Book
{
	int borrow_times;
	char bkid[10];// 编号 
	char title[20];// 书名 
	char author[20];//作者 
}BOOK;//书籍信息 
typedef struct bnode
{
	struct Book data; //数据域
	struct bnode *next; //指针域
}BNode,*BLink; 

typedef struct {
	char name[20];
	char key[20];
	char key_again[20];
	char id[20];
	char my_class[10];
	char study_id[20];
	char gender[10];
	char age[5];
	char string[30];
	char  balance[5];
	char arrears[5];
	char payment[10];
	char borrow_book[10][20];
	char collect_book[10][20];
	char seat[5];
	int seat_state;
	int borrow_state;
	char *borrow_time; 
}USER1;

typedef struct{
	char time[20];
	int count;
}Excel_data;

#endif

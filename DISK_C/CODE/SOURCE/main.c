#include"common.h"
#include"main.h"
void main()
{
	int *seat_state=0;
	USER1 user1={0};
	USER1 user2={0}; 
	USER1 *p1=&user1;
	USER1 *p2=&user2;
	char *s1="none";
	char *s6="none";
	char *s18="none";
	char *s25="none";
	char *s41="none";
	int page=0;
	int graphdriver=VGA;//VGA画图的初始化 
	int graphmode=VGAHI;
	Link head ; // 定义链表
	BLink bhead;
	initgraph(&graphdriver,&graphmode,".\\BGI");
	mouseinit();//鼠标的初始化
	memset(&user1,'\0',sizeof(user1));
	head=nodeinit(head);	//链表的初始化
	bhead=bnodeinit(bhead);
	page=welcome(s1,s6,s18,s25,s41);
	//将链表与文件同步
	
	while(1)
	{
		switch(page)
		{
			case 0:
				page=login_user(p1, p2,head);//用户的登录界面 
				break;
			case 1:
				page=register_user(p1,head);//用户注册界面 
				break;
			case 3:
				page=reset_key(p1,head);//用重置密码 
				break;
			case 4:
				page=after_login(head);//登陆后的首界面，可以选择个人中心，预约选座，热门书籍浏览，文献检索 
				break;
			case 5:
				page=personal_center(p1,head);//个人中心界面 
				break;
			case 6:
				page=my_borrow(p1,head);//查看我的借阅 
				break;
			case 7:
				page=my_collection(p1,head,bhead);//查看我的收藏 
				break;
			case 8:
				page=thd_floor_resv(p1,head);//查看三楼的预约情况 
				break;
			case 9:
				page=reservation(p1,head);//查看整个图书馆的座位情况 
				break;
			case 10:
				page=personal_information(p1,head);//修改个人信息 
				break;
			case 11:
				page=borrow_one();
				break;
			case 12:
				page=borrow_payment(p1,head);//进行借阅缴费 
				break;
			case 13:
				page=fth_floor_resv(p1,head);//查看四楼的座位预约情况 
				break;
			/*case 14:
				page=book_renew();
				break;*/
			case 15:
				page=sec_floor_resv(p1,head);//查看二楼的座位预约情况 
				break;
			
			/*case 16:
				page=third_floor_reservation();
				break;*/
			
			case 17:
				page=resource_platform(bhead,p1,head);//浏览热门书籍 
				break;
			/*case 18:
				page=introduction();
				break;
			case 19:
				page=document_search();
				break;
			case 20:
				page=article_recommand();
				break;
			case 21:
				page=search_result();
				break;
			case 22:
				closegragh();
				exit(0);*/
			case 23:
				page=mng_login();//管理员登录 
				break;
			case 24:
				page=manage_mainpage();//管理员登录后主界面 
				break;

			case 26:
				page=bookmng_search(bhead);//文献检索管理员端 
				break;
			case 27:
				page=bookmng_add(bhead);//添加书籍 
				break;
			case 28:
				page=bookuser_search(bhead,head,p1);//搜索 
				break;
			case 29:
				page=usermng_search(head);
				break;
			case 30:
				page=usermng_add(head);
				break;

			case 32:
				page=lending_mng(head,bhead);
				break;				
			case 33:
				page=mng_seat(p1,head);
				break;
			case 34:
				page=mseat_sec(head);
				break;
			case 35:
				page=mseat_thd(head);
				break;
			case 16:
				page=mseat_for(head);
				break;
			case 36:
				page=psn_resv(p1,head);
				break;
			case 37:
				page=welcome();
				break;
			case 38:
				Link_free(head,bhead);//释放内存 
				closegraph();
				exit(0);
		}
	  }
}


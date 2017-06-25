#include"deal.h"
#include"resturant.h"
using namespace std;

void welcome();//程序进入后的欢迎界面显示函数

void loginsystem();//登录函数

void loadsystem();//注册函数

bool  threechecks(resturant temp);//三次密码输入检验函数

void function(resturant temp);//服务功能模块

void foodchange(resturant temp);//自身菜单维护

void showorder(resturant temp);//订菜顾客显示

void cancelorder(resturant temp);//订单审核
#include"deal.h"
#include"resturant.h"
#include"customer.h"
using namespace std;

void welcome();//程序进入后的欢迎界面显示函数

void infochange(customer temp);//自身信息维护

void loginsystem();//登录函数

void loadsystem();//注册函数

bool  threechecks(customer temp);//三次密码输入检验函数

void function(customer temp);//服务功能模块

void takeorder(customer temp);//餐馆食物选择，订单自动生成

void cannel(customer temp);//申请取消订单


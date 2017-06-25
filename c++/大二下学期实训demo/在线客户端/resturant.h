#ifndef _H_RESTURANT
#define _H_RESTURANT
#include<iostream>
#include<string>
#include<map>
using namespace std;

class resturant  {
private:
	string name;
	string food[20];
	string pwd;
	int money;
	bool flag;//用于三次错误输入后的锁定
	int cost[20];
public:
	//构造函数 初始化成员
	resturant(string name = "undefined", string pwd = "undefined", int money = 0, bool flag = true, string food = "undefined", int cost = 0)
	{
		this->name = name;
		this->pwd = pwd;
		this->money = money;
		this->flag = flag;
		for (int i = 0; i < 20; i++)
		{
			this->food[i] = food;
		}
		for (int j = 0; j < 20; j++)
		{
			this->cost[j] = cost;
		}
	}
	//设置密码函数 用来自身信息维护
	void set_pwd(string pwd);
	//设置菜单
	void set_food(string food, int m);
	//设置餐单金额
	void set_cost(int cost, int n);
	//设置账户金额
	void set_money(int money);
	//设置账户名
	void set_name(string name);
	//设置锁定标志
	void set_flag(bool flag);
	//展示菜单
	string* get_food();
	//展示菜单金额
	int* get_cost();
	//显示账户余额
	int get_money();
	//展示账户名
	string get_name();
	//展示密码
	string get_pwd();
	//展示锁定标志
	bool get_flag();
	//密码匹配 用来登录或修改密码时的核查
	bool checkpwdbyname();
	//用来显示账户信息
	void show();
	void showto_customer()
	{
		cout << "餐馆:" << this->name  << "有以下菜肴:" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << "编号" << i << "菜名：" << this->food[i] << "金额：" << this->cost[i] << endl;
		}
	}

};

#endif
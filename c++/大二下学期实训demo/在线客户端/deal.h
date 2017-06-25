#ifndef _H_DEAL
#define _H_DEAL
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class deal{
private:
	string customer_name;
	string resturant_name;
	string address;
	int foodnumber;
	string order_time;
	string customer_cell;
	int money;
	bool custflag;
	bool restflag;
public:
	//构造函数 初始化成员
	deal(string customer_name = "undefined", string resturant_name = "undefined",
		string address = "undefined", int foodnumber = 0, string order_time = "undefined",
		string customer_cell = "undefined", int money = 0, bool custflag = true, bool restflag = true)
	{
		this->customer_name = customer_name;
		this->resturant_name = resturant_name;
		this->address = address;
		this->foodnumber = foodnumber;
		this->order_time = order_time;
		this->customer_cell = customer_cell;
		this->money = money;
		this->custflag = custflag;
		this->restflag = restflag;
	}
	//订单金额设置
	void set_money(int money);
	//顾客订单状态设置
	void set_custflag(bool custflag);
	//餐馆订单状态设置
	void set_restflag(bool restflag);
	//食品编号设置
	void set_foodnumber(int foodnumber);



	//顾客获取
	string get_customer_name();
	//餐馆获取
	string get_resturant_name();
	//地址获取
	string get_address();
	//食品获取
	int get_foodnumber();
	//订单时间获取
	string get_order_time();
	//顾客电话获取
	string get_customer_cell();
	//订单金额获取
	int get_money();
	//显示顾客订单状态
	bool get_custflag();
	//显示餐馆订单状态
	bool get_restflag();



	//检查订单，返回订单状态信息
	char checkdealbyfalg();
	//以订单中餐馆名搜索订单，返回bool值
	bool checkdealbyresturant(string name);
	//以订单中餐馆名搜索订单，返回bool值
	bool checkdealbycustomer(string name);
	//显示订单状态信息
	void showflaginfo();
	//订单信息显示
	void show();


};

#endif
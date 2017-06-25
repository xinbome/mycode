#include<iostream>
#include<string>
#include<map>
using namespace std;


class customer{
private:
	string name;
	string pwd;
	int money;
	string cell;
	bool flag;
public:
	//构造函数 初始化成员
	customer(string name = "undefined", string pwd = "undefined",
		int money = 0, string cell = "undefined", bool flag = true)
	{
		this->name = name;
		this->pwd = pwd;
		this->money = money;
		this->cell = cell;
		this->flag = flag;
	}
	//密码匹配 用来登录或修改密码时的核查
	bool checkpwdbyname();
	//设置密码函数 用来自身信息维护
	void set_pwd(string pwd);
	//设置账户金额
	void set_money(int money);
	void set_name(string name)
	{
		this->name = name;
	}
	void set_cell(string cell)
	{
		this->cell = cell;
	}
	void set_flag(bool flag)
	{
		this->flag = flag;
	}
	//显示账户余额
	int get_money();
	//显示账户名称
	string get_name();
	//显示账户密码
	string get_pwd();
	//显示联系电话
	string get_cell();
	//显示账户状态信息
	bool get_flag();
	//账户信息显示
	void show()
	{
		cout << "您账号名为" << this->name << endl;
		cout << "您密码为" << this->pwd << endl;
		cout << "您账户余额为为" << this->money << endl;
		cout << "您的电话号码为" << this->cell << endl;
	}

};
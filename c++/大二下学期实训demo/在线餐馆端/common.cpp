#include"common.h"

extern map<string, resturant> reststore;
extern vector<deal>dealstore;

void welcome()
{
	cout << "欢迎来到在线网络订餐系统" << endl;
	cout << "这是商家版客户端" << endl;
	cout << "注册新商家用户，请按1" << endl;
	cout << "登录商家用户，请按2" << endl;
	cout << "保存数据退出系统，请按3" << endl;
}

bool  threechecks(resturant temp)
{
	string temppwd;
	for (int i = 0; i < 2; i++)
	{
		if (temp.checkpwdbyname() == true)
		{
			return true;
		}
		cout << "密码输入错误" << endl;
		cout << "请重新输入" << endl;
		fflush(stdin);
		cin >> temppwd;
		temp.set_pwd(temppwd);
	}
	return false;
}

void foodchange(resturant temp)
{
	char choice = '0';
	int num = 0;
	string change[20];
	int costchange[20];
	char quitflag = '0';
	while (1)
	{
		cout << "1增加或修改菜肴" << endl;
		cout << "2删除已有菜肴" << endl;
		fflush(stdin);
		cin >> choice;
		switch (choice)
		{
		case'1':
		{
			reststore[temp.get_name()].show();
			cout << "请输入要增加或修改的编号" << endl;
			fflush(stdin);
			cin >> num;
			cout << "请输入菜肴名称" << endl;
			fflush(stdin);
			cin >> change[num];
			cout << "请输入菜肴的价格" << endl;
			fflush(stdin);
			cin >> costchange[num];
			reststore[temp.get_name()].set_food(change[num], num);
			reststore[temp.get_name()].set_cost(costchange[num], num);
			reststore[temp.get_name()].show();
			system("pause");
			system("cls");
			break;
		}
		case'2':
		{
			reststore[temp.get_name()].show();
			cout << "请输入要删除的编号" << endl;
			fflush(stdin);
			cin >> num;
			change[num] = "undefined";
			reststore[temp.get_name()].set_food(change[num], num);
			reststore[temp.get_name()].show();
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			cout << "输入有误" << endl;
		}
		}
		cout << "退出菜肴信息维护，请按q，按其它键继续" << endl;
		fflush(stdin);
		cin >> quitflag;
		if (quitflag == 'q'){ break; }
	}
}

void showorder(resturant temp)
{
	int count=0;
	for (unsigned int i = 0; i < dealstore.size(); i++)
	{
		if ((dealstore[i].checkdealbyresturant(temp.get_name()) == true) && (dealstore[i].checkdealbyfalg() == '1'))
		{
			dealstore[i].show();
		}
		else
		{
			count++;
		}
	}
	if (count == dealstore.size()){ cout << "很抱歉，现在没人点单！" << endl; }
	system("pause");
	system("cls");
}

void cancelorder(resturant temp)
{
	//餐馆端的订单取消 均不涉及金额操作  金额操作都在客户端
	char orderchoice = '0';
	char ynchoice = '0';
	int count = 0;
	for (unsigned int m = 0; m < dealstore.size(); m++)
	{
		if ((dealstore[m].checkdealbyresturant(temp.get_name()) == true) && (dealstore[m].checkdealbyfalg() == '2'))
		{
			dealstore[m].show();
			//进行审核消单操作
			cout << "是否同意取消该订单,按y同意，按n拒绝" << endl;
			cin >> ynchoice;
			if (ynchoice == 'y')
			{
				dealstore[m].set_restflag(false);
				cout << "成功取消" << endl;
			}
			else
			{
				dealstore[m].set_custflag(true);
				cout << "您拒绝了了该用户的取消请求，该订单现在为有效订单" << endl;
			}
		}
		else
		{
			count++;
		}
	}
	if (count == dealstore.size()){ cout << "当前没有待取消的订单" << endl; }
	system("pause");
	system("cls");
}

void function(resturant temp)
{
	//服务功能首界面
	char functionchoice = '0';
	while (1)
	{
		system("cls");
		cout << reststore[temp.get_name()].get_name() << "您好" << endl;
		cout << "这里是服务功能模块" << endl;
		cout << "按1维护自己菜单" << endl;
		cout << "按2查看当前点餐对象，显示送餐地址、选则的菜品、订餐时间、订餐电话" << endl;
		cout << "按3审核顾客消单请求" << endl;
		cout << "按4退出服务功能模块" << endl;
		while (1)
		{
			fflush(stdin);
			cin >> functionchoice;
			if (functionchoice != '1'&& functionchoice != '2'&&functionchoice != '3'&&functionchoice != '4')
			{
				cout << "输入有误，请重新输入" << endl;
			}
			else
			{
				break;
			}
		}
		if (functionchoice == '1'){ foodchange(temp); }
		if (functionchoice == '2'){ showorder(temp); }
		if (functionchoice == '3'){ cancelorder(temp); }
		if (functionchoice == '4'){ break; }
	}
}

void loadsystem()
{
	string tempfood[20];
	int tempcost[20];
	string tempname;
	string temppwd;
	string checktemppwd;
	int tempmoney = 0;
	char foodquit = '0';
	cout << "欢迎注册在线网络订餐系统商户账户" << endl;
	cout << "请输入您要注册的商家名" << endl;
	fflush(stdin);
	cin >> tempname;
	while (1)
	{
		cout << "请输入您的密码" << endl;
		fflush(stdin);
		cin >> temppwd;
		cout << "请输入确认您的密码" << endl;
		fflush(stdin);
		cin >> checktemppwd;
		if (checktemppwd != temppwd)
		{
			cout << "两次密码输入不一致，请重新输入" << endl;
		}
		else
		{
			break;
		}
	}
	int n = 0;
	for (; n < 20; n++)
	{
		cout << "请输入您餐馆的菜名称" << endl;
		fflush(stdin);
		cin >> tempfood[n];
		cout << "请输入您餐馆的菜的金额" << endl;
		fflush(stdin);
		cin >> tempcost[n];
		cout << " 输入q退出菜单设置,按其他键继续" << endl;
		cin >> foodquit;
		if (foodquit == 'q'){ break; }
	}
	resturant tre(tempname, temppwd, tempmoney, true);
	for (int m = 0; m <= n; m++)
	{
		tre.set_food(tempfood[m], m);
		tre.set_cost(tempcost[m], m);
	}
	reststore.insert(pair<string, resturant>(tre.get_name(), tre));
	cout << "注册成功" << endl;
}

void loginsystem()
{
	char loginchoice = '0';
	resturant temp;
	string tempname;
	string temppwd;

	//登录界面 已有账户匹配
	while (1)
	{
		cout << "请输入您要登陆的商家账户名称" << endl;
		fflush(stdin);
		cin >> tempname;
		temp.set_name(tempname);
		if (reststore[tempname].get_food()[0] == "undefined")
		{
			reststore.erase("undefined");//消除map容器里创建的错误,自动初始化的数值
			cout << "该账户不存在" << endl;
		}
		else
		{
			break;
		}
	}
	//登录界面 密码匹配
	cout << "请输入账户密码，三次错误输入该账户即会锁定" << endl;
	fflush(stdin);
	cin >> temppwd;
	temp.set_pwd(temppwd);
	if (threechecks(temp) == false)
	{
		cout << "三次错误输入密码，此账户已经锁定" << endl << "即将退出系统" << endl;
		reststore[temp.get_name()].set_flag(false);
		system("pause");
		exit(0);
	}

	system("cls");
	cout << "成功登录" << endl;
	reststore[temp.get_name()].show();
	system("pause");
	system("cls");
	function(temp);
}

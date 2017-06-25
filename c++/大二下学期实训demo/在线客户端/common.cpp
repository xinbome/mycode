#include"common.h"

extern map<string, resturant> reststore;
extern map<string, customer> custstore;
extern  vector<deal>dealstore;

void infochange(customer temp)
{
	system("cls");
	char choice = '0';
	int num = 0;
	string tempstring;
	char quitflag = '0';
	while (1)
	{
		cout << "1修改密码" << endl;
		cout << "2修改电话号码" << endl;
		cout << "3继续进行充值" << endl;
		fflush(stdin);
		cin >> choice;
		switch (choice)
		{
		case'1':
		{
			custstore[temp.get_name()].show();
			cout << "请输入要修改的密码" << endl;
			fflush(stdin);
			cin >> tempstring;
			custstore[temp.get_name()].set_pwd(tempstring);
			cout << "修改成功" << endl;
			system("pause");
			system("cls");
			break;
		}
		case'2':
		{
			custstore[temp.get_name()].show();
			cout << "请输入要修改的电话号码" << endl;
			fflush(stdin);
			cin >> tempstring;
			custstore[temp.get_name()].set_cell(tempstring);
			cout << "修改成功" << endl;
			system("pause");
			system("cls");
			break;
		}
		case'3':
		{
			custstore[temp.get_name()].show();
			cout << "请输入要存入的金额" << endl;
			fflush(stdin);
			cin >> num;
			num = num + custstore[temp.get_name()].get_money();
			custstore[temp.get_name()].set_money(num);
			cout << "成功存入" << endl;
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			cout << "输入有误" << endl;
		}
		}
		cout << "退出账号信息维护，请按q,其余键继续" << endl;
		fflush(stdin);
		cin >> quitflag;
		if (quitflag == 'q'){ break; }
	}
}

void takeorder(customer temp)

{
	system("cls");
	int wantedfood = 0;
	string wantedresturant = "0";
	string wantedtime = "0";
	int  wantedmoney = 0;
	string wantedaddress = "0";
	char ynchoice = '0';
	map<string, resturant>::iterator it;
	for (it = reststore.begin(); it != reststore.end(); ++it)
	{
		it->second.showto_customer();
	}
	cout << "请输入您想要的餐馆" << endl;
	fflush(stdin);
	cin >> wantedresturant;
	cout << "请输入您想要的套餐编号" << endl;
	fflush(stdin);
	cin >> wantedfood;
	cout << "请输入您的订餐时间" << endl;
	fflush(stdin);
	cin >> wantedtime;
	cout << "请输入您的地址" << endl;
	fflush(stdin);
	cin >> wantedaddress;
	deal d(custstore[temp.get_name()].get_name(), wantedresturant, wantedaddress, wantedfood, wantedtime, custstore[temp.get_name()].get_cell(), wantedmoney, true, false);
	wantedmoney = reststore[wantedresturant].get_cost()[wantedfood];
	d.set_money(wantedmoney);//订单赋予金额
	cout << "成功下单" << endl;
	cout << "是否确认订单，并进行支付，按y确认按n取消订单" << endl;
	fflush(stdin);
	cin >> ynchoice;
	if (ynchoice == 'y')
	{
		custstore[temp.get_name()].set_money(custstore[temp.get_name()].get_money() - wantedmoney);//用户账户扣钱
		reststore[wantedresturant].set_money(reststore[wantedresturant].get_money() + wantedmoney);//商家账户加钱
		d.set_restflag(true);
		cout << "确认支付" << endl;
	}
	else
	{
		d.set_custflag(false);
		cout << "订单未支付，自动注销该单" << endl;
	}
	dealstore.push_back(d);
	d.show();
	system("pause");
}

void cannel(customer temp)
{
	int count = 0;
	char ynchoice = '0';
	for (unsigned int m = 0; m < dealstore.size(); m++)
	{
		if ((dealstore[m].checkdealbycustomer(temp.get_name()) == true) && (dealstore[m].checkdealbyfalg() == '1'))
		{
			dealstore[m].show();
			cout << "是否申请取消订单，按y申请取消" << endl;
			fflush(stdin);
			cin >> ynchoice;
			if (ynchoice == 'y')
			{
				dealstore[m].set_custflag(true);
				cout << "已申请取消" << endl;
			}
			dealstore[m].set_custflag(false);
		}
		else
		{
			count++;
		}

		//商家同意取消后的账户金额变动-----------------------------------------------------------------------------
		if ((dealstore[m].checkdealbycustomer(temp.get_name()) == true) && (dealstore[m].checkdealbyfalg() == '3') && dealstore[m].get_money() != 0)//餐馆刚确认取消的订单
		{
			custstore[temp.get_name()].set_money(custstore[temp.get_name()].get_money() + dealstore[m].get_money());//返还顾客的订单金额
			reststore[dealstore[m].get_resturant_name()].set_money(reststore[dealstore[m].get_resturant_name()].get_money() - dealstore[m].get_money());//扣除已经到账的金额
		}
	}

	if (count == dealstore.size()){ cout << "当前没有您的订单" << endl; }
	system("pause");
}

void welcome()
{
	cout << "欢迎来到在线网络订餐系统" << endl;
	cout << "这是顾客版客户端" << endl;
	cout << "注册新用户，请按1" << endl;
	cout << "登录消费者用户，请按2" << endl;
	cout << "保存数据退出系统，请按3" << endl;
}

bool  threechecks(customer temp)
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

void function(customer temp)
{
	//服务功能首界面
	char functionchoice = '0';
	while (1)
	{
		system("cls");
		cout << custstore[temp.get_name()].get_name() << "您好" << endl;
		cout << "这里是服务功能模块" << endl;
		cout << "按1维护个人信息" << endl;
		cout << "按2显示可选餐馆，并进行下单，自动生成订单,并支付" << endl;
		cout << "按3提出消单请求" << endl;
		cout << "按4退出服务功能模块" << endl;
		while (1)
		{
			fflush(stdin);
			cin >> functionchoice;
			if (functionchoice != '1'&& functionchoice != '2'&&functionchoice != '3'&&functionchoice != '4'&&functionchoice != '5')
			{
				cout << "输入有误，请重新输入" << endl;
			}
			else
			{
				break;
			}
		}
		if (functionchoice == '1'){ infochange(temp); }
		if (functionchoice == '2'){ takeorder(temp); }
		if (functionchoice == '3'){ cannel(temp); }
		if (functionchoice == '4'){ break; }
	}
}

void loadsystem()
{
	system("cls");
	string tempcell;
	string tempname;
	string temppwd;
	string checktemppwd;
	int tempmoney = 0;
	cout << "欢迎注册在线网络订餐系统消费者账户" << endl;
	cout << "请输入您要注册的账户名" << endl;
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

	cout << "请输入您的手机号" << endl;
	fflush(stdin);
	cin >> tempcell;
	cout << "请输入您要预存的金额" << endl;
	fflush(stdin);
	cin >> tempmoney;
	customer tre(tempname, temppwd, tempmoney, tempcell, true);
	custstore.insert(pair<string, customer>(tre.get_name(), tre));
	cout << "注册成功" << endl;
	system("pause");
}

void loginsystem()
{
	char loginchoice = '0';
	customer temp;
	string tempname;
	string temppwd;

	//登录界面 已有账户匹配
	while (1)
	{
		cout << "请输入您要登陆的商家账户名称" << endl;
		fflush(stdin);
		cin >> tempname;
		temp.set_name(tempname);
		if (custstore[tempname].get_cell() == "undefined")
		{
			custstore.erase("undefined");//消除map容器里创建的错误,自动初始化的数值
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
		custstore[temp.get_name()].set_flag(false);
		system("pause");
		exit(0);
	}

	system("cls");
	cout << "成功登录" << endl;
	custstore[temp.get_name()].show();
	system("pause");
	system("cls");
	function(temp);
}


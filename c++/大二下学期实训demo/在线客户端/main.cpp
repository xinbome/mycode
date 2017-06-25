#include"common.h"
#include<fstream>
using namespace std;

map<string, resturant> reststore;
map<string, customer> custstore;
vector<deal>dealstore;

void main()
{
	//文本输入-------------------------------------------------------------------------------------------------------------------------------------
	string currentstring = "0";
	int currentint;
	bool currentbool;
	resturant current;
	//将文本中的resturant类写入内存中的map关联容器
	ifstream restfin("resturant.txt");
	while (restfin.good() == true && (!restfin.eof()))
	{
		currentstring = "0";
		restfin >> currentstring;
		if (currentstring == "0"){ break; }
		current.set_name(currentstring);
		for (int s = 0; s < 20; s++)
		{
			restfin >> currentstring;
			current.set_food(currentstring, s);
			restfin >> currentint;
			current.set_cost(currentint, s);
		}
		restfin >> currentstring;
		current.set_pwd(currentstring);

		restfin >> currentint;
		current.set_money(currentint);

		restfin >> currentbool;
		current.set_flag(currentbool);
		reststore.insert(pair<string, resturant>(current.get_name(), current));
		//reststore[current.get_name()].show();
	}
	restfin.close();

	//从文件中读取deal的信息并加载到内存中的vector容器
	string currentcustomer_name = "0";
	string currentresturant_name;
	string currentaddress;
	int currentfoodnumber;
	string currentorder_time;
	string currentcustomer_cell;
	int currentmoney;
	bool currentcustflag;
	bool currentrestflag;
	ifstream dealfin("deal.txt");
	while (dealfin.good() == true)
	{
		dealfin >> currentcustomer_name >> currentresturant_name >> currentaddress >> currentfoodnumber >> currentorder_time >> currentcustomer_cell >> currentmoney >> currentcustflag >> currentrestflag;
		deal currentdeal(currentcustomer_name, currentresturant_name, currentaddress, currentfoodnumber, currentorder_time, currentcustomer_cell, currentmoney, currentcustflag, currentrestflag);
		if (currentcustomer_name == "0"){ break; }//如果文件没创立则退出循环
		dealstore.push_back(currentdeal);
	}
	dealfin.close();

	//将文本中的customer类写入内存中的map关联容器
	customer currentcust;
	ifstream custfin("customer.txt");
	while (custfin.good() == true)
	{
		currentstring = "0";
		custfin >> currentstring;
		if (currentstring == "0"){ break; }
		currentcust.set_name(currentstring);

		custfin >> currentstring;
		currentcust.set_pwd(currentstring);

		custfin >> currentint;
		currentcust.set_money(currentint);

		custfin >> currentstring;
		currentcust.set_cell(currentstring);

		custfin >> currentbool;
		currentcust.set_flag(currentbool);

		custstore.insert(pair<string, customer>(currentcust.get_name(), currentcust));
	}
	custfin.close();





	//系统首界面-----------------------------------------------------------------------------------------------------------------------------------
	char welcomechoice = '0';
	while (1)
	{
		system("cls");
		welcome();
		while (1)
		{
			fflush(stdin);
			cin >> welcomechoice;
			if (welcomechoice != '1'&& welcomechoice != '2'&&welcomechoice != '3')
			{
				cout << "输入有误，请重新输入" << endl;
			}
			else
			{
				break;
			}
		}
		if (welcomechoice == '1'){ loadsystem(); }
		if (welcomechoice == '2'){ loginsystem(); }
		if (welcomechoice == '3'){ break; }
	}
	//-------------------------------------------------------------------------------------------------------------------------







	//内存数据输出到文本
	//输出resturant信息--------------------------------------------------------------------------------------------------------
	ofstream restfout("resturant.txt", ios::trunc);
	if (restfout.good() == false)
	{
		cout << "warning" << endl;
	}
	map<string, resturant>::iterator it;
	for (it = reststore.begin(); it != reststore.end(); ++it)
	{
		restfout << it->second.get_name() << endl;
		for (int k = 0; k < 20; k++)
		{
			restfout << it->second.get_food()[k] << endl;
			restfout << it->second.get_cost()[k] << endl;
		}
		restfout << it->second.get_pwd() << endl;
		restfout << it->second.get_money() << endl;
		restfout << it->second.get_flag() << endl;
	}
	restfout << flush;
	restfout.close();

	//输出deal信息-----------------------------------------------------------------------
	ofstream dealfout("deal.txt", ios::trunc);
	if (dealfout.good() == false)
	{
		cout << "warning" << endl;
	}
	for (unsigned int z = 0; z < dealstore.size(); z++)
	{
		//dealstore[z].show();
		dealfout << dealstore[z].get_customer_name() << endl;
		dealfout << dealstore[z].get_resturant_name() << endl;
		dealfout << dealstore[z].get_address() << endl;
		dealfout << dealstore[z].get_foodnumber() << endl;
		dealfout << dealstore[z].get_order_time() << endl;
		dealfout << dealstore[z].get_customer_cell() << endl;
		dealfout << dealstore[z].get_money() << endl;
		dealfout << dealstore[z].get_custflag() << endl;
		dealfout << dealstore[z].get_restflag() << endl;
	}
	dealfout << flush;
	dealfout.close();

	//输出customer信息
	ofstream custfout("customer.txt", ios::trunc);
	if (custfout.good() == false)
	{
		cout << "warning" << endl;
	}
	map<string, customer>::iterator the;
	for (the = custstore.begin(); the != custstore.end(); ++the)
	{
		custfout << the->second.get_name() << endl;
		custfout << the->second.get_pwd() << endl;
		custfout << the->second.get_money() << endl;
		custfout << the->second.get_cell() << endl;
		custfout << the->second.get_flag() << endl;
	}
	custfout << flush;
	custfout.close();
}
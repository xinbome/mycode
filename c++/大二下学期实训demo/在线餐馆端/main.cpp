#include"common.h"
#include<fstream>
using namespace std;

map<string, resturant> reststore;
vector<deal>dealstore;


void main()
{
	string currentstring = "0";
	int currentint;
	bool currentbool;
	resturant current;
	//���ı��е�resturant��д���ڴ��е�map��������
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

	//���ļ��ж�ȡdeal����Ϣ�����ص��ڴ��е�vector����
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
		if (currentcustomer_name == "0"){ break; }//����ļ�û�������˳�ѭ��
		dealstore.push_back(currentdeal);
	}
	dealfin.close();


	//ϵͳ�׽���-----------------------------------------------------------------------------------------------------------------------------------
	char welcomechoice = '0';
	while (1)
	{
		system("cls");
		welcome();
		while (1)
		{
			fflush(stdin);
			cin >> welcomechoice;
			if (welcomechoice != '1'&& welcomechoice != '2'&&welcomechoice!='3')
			{
				cout << "������������������" << endl;
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


	//���resturant��Ϣ--------------------------------------------------------------------------------------------------------
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

	//���deal��Ϣ-----------------------------------------------------------------------
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
}
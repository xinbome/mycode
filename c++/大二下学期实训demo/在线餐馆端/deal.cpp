#include"deal.h"
extern  vector<deal>dealstore;

string deal::get_customer_name()
{
	return(this->customer_name);
}

string deal::get_resturant_name()
{
	return(this->resturant_name);
}

string deal::get_address()
{
	return(this->address);
}

int deal::get_foodnumber()
{
	return(this->foodnumber);
}

string deal::get_order_time()
{
	return(this->order_time);
}

string deal::get_customer_cell()
{
	return(this->customer_cell);
}

int deal::get_money()
{
	return(this->money);
}

bool deal::get_custflag()
{
	return(this->custflag);
}

bool deal::get_restflag()
{
	return(this->restflag);
}

void deal::set_custflag(bool custflag)
{
	this->custflag = custflag;
}

void deal::set_restflag(bool restflag)
{
	this->restflag = restflag;
}

void deal::set_money(int money)
{
	this->money = money;
}

void deal::set_foodnumber(int foodnumber)
{
	this->foodnumber = foodnumber;
}

char deal::checkdealbyfalg()
{
	char info = '0';
	if (this->get_restflag() == true && this->get_custflag() == true)
	{
		info = '1';
	}
	if (this->get_restflag() == true && this->get_custflag() == false)
	{
		info = '2';
	}
	if (this->get_restflag() == false && this->get_custflag() == false)
	{
		info = '3';
	}
	if (this->get_restflag() == false && this->get_custflag() == true)
	{
		info = '4';
	}
	return info;
}

bool deal::checkdealbyresturant(string name)
{
	if (this->resturant_name == name)
		return(true);
	else
		return(false);
}

void deal::showflaginfo()
{
	if (this->checkdealbyfalg() == '1')
	{
		cout << "��ǰ����Ϊ��Ч����" << endl;
	}
	if (this->checkdealbyfalg() == '2')
	{
		cout << "��ǰ�����˿����ύȡ���������͹ݷ���ȷ��" << endl;
	}

	if (this->checkdealbyfalg() == '3')
	{
		cout << "��ǰ������ȡ��" << endl;
	}

	if (this->checkdealbyfalg() == '4')
	{
		cout << "��ǰ������֧��" << endl;
	}
}

void deal::show()
{
	cout << "�˿�����" << customer_name << endl << "���ͷ���" << resturant_name << endl;
	cout << "�����ײͱ��" << foodnumber << endl << "���������" << money << endl;
	cout << "�˿͵绰" << customer_cell << endl << "������ַ" << address <<endl<< "����ʱ��" << order_time << endl;
	this->showflaginfo();
}

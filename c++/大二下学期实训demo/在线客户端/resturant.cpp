#include"resturant.h"
extern map<string, resturant> reststore;

void resturant::set_pwd(string pwd)
{
	this->pwd = pwd;
}

void resturant::set_flag(bool flag)
{
	this->flag = flag;
}

void resturant::set_food(string food, int m)
{
	this->food[m] = food;
}

void resturant::set_cost(int cost, int n)
{
	this->cost[n] = cost;
}

void resturant::set_name(string name)
{
	this->name = name;
}

void  resturant::set_money(int money)
{
	this->money = money;
}

int resturant::get_money()
{
	return(this->money);
}

string resturant::get_name()
{
	return(this->name);
}

string* resturant::get_food()
{
	return(this->food);
}

int* resturant::get_cost()
{
	return(this->cost);
}

string resturant::get_pwd()
{
	return(this->pwd);
}

bool resturant::get_flag()
{
	return(this->flag);
}

void resturant::show()
{
	cout << "���Ĳ͹�" << this->name << endl << "����Ϊ" << this->pwd << endl << "�˻����Ϊ" << this->money << endl << "�����²���" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << "���" << i << "������" << this->food[i] << "��" << this->cost[i] << endl;
	}
}

bool resturant::checkpwdbyname()
{
	if (this->get_pwd() == reststore[this->get_name()].get_pwd())
	{
		return true;
	}
	else
	{
		return false;
	}
}
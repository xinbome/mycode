#include"customer.h"

extern map<string, customer> custstore;

bool customer::checkpwdbyname()
{
	if (this->get_pwd() == custstore[this->get_name()].get_pwd())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void customer::set_pwd(string pwd)
{
	this->pwd = pwd;
}

void  customer::set_money(int money)
{
	this->money = money;
}

int customer::get_money()
{
	return(this->money);
}

string customer::get_name()
{
	return(this->name);
}

string customer::get_pwd()
{
	return(this->pwd);
}

string customer::get_cell()
{
	return(this->cell = cell);
}

bool customer::get_flag()
{
	return(this->flag);
}


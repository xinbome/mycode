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
	//���캯�� ��ʼ����Ա
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
	//�����������
	void set_money(int money);
	//�˿Ͷ���״̬����
	void set_custflag(bool custflag);
	//�͹ݶ���״̬����
	void set_restflag(bool restflag);
	//ʳƷ�������
	void set_foodnumber(int foodnumber);



	//�˿ͻ�ȡ
	string get_customer_name();
	//�͹ݻ�ȡ
	string get_resturant_name();
	//��ַ��ȡ
	string get_address();
	//ʳƷ��ȡ
	int get_foodnumber();
	//����ʱ���ȡ
	string get_order_time();
	//�˿͵绰��ȡ
	string get_customer_cell();
	//��������ȡ
	int get_money();
	//��ʾ�˿Ͷ���״̬
	bool get_custflag();
	//��ʾ�͹ݶ���״̬
	bool get_restflag();



	//��鶩�������ض���״̬��Ϣ
	char checkdealbyfalg();
	//�Զ����в͹�����������������boolֵ
	bool checkdealbyresturant(string name);
	//�Զ����в͹�����������������boolֵ
	bool checkdealbycustomer(string name);
	//��ʾ����״̬��Ϣ
	void showflaginfo();
	//������Ϣ��ʾ
	void show();


};

#endif
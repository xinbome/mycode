#ifndef _H_RESTURANT
#define _H_RESTURANT
#include<iostream>
#include<string>
#include<map>
using namespace std;

class resturant  {
private:
	string name;
	string food[20];
	string pwd;
	int money;
	bool flag;//�������δ�������������
	int cost[20];
public:
	//���캯�� ��ʼ����Ա
	resturant(string name = "undefined", string pwd = "undefined", int money = 0, bool flag = true, string food = "undefined", int cost = 0)
	{
		this->name = name;
		this->pwd = pwd;
		this->money = money;
		this->flag = flag;
		for (int i = 0; i < 20; i++)
		{
			this->food[i] = food;
		}
		for (int j = 0; j < 20; j++)
		{
			this->cost[j] = cost;
		}
	}
	//�������뺯�� ����������Ϣά��
	void set_pwd(string pwd);
	//���ò˵�
	void set_food(string food, int m);
	//���ò͵����
	void set_cost(int cost, int n);
	//�����˻����
	void set_money(int money);
	//�����˻���
	void set_name(string name);
	//����������־
	void set_flag(bool flag);
	//չʾ�˵�
	string* get_food();
	//չʾ�˵����
	int* get_cost();
	//��ʾ�˻����
	int get_money();
	//չʾ�˻���
	string get_name();
	//չʾ����
	string get_pwd();
	//չʾ������־
	bool get_flag();
	//����ƥ�� ������¼���޸�����ʱ�ĺ˲�
	bool checkpwdbyname();
	//������ʾ�˻���Ϣ
	void show();
	void showto_customer()
	{
		cout << "�͹�:" << this->name  << "�����²���:" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << "���" << i << "������" << this->food[i] << "��" << this->cost[i] << endl;
		}
	}

};

#endif
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
	//���캯�� ��ʼ����Ա
	customer(string name = "undefined", string pwd = "undefined",
		int money = 0, string cell = "undefined", bool flag = true)
	{
		this->name = name;
		this->pwd = pwd;
		this->money = money;
		this->cell = cell;
		this->flag = flag;
	}
	//����ƥ�� ������¼���޸�����ʱ�ĺ˲�
	bool checkpwdbyname();
	//�������뺯�� ����������Ϣά��
	void set_pwd(string pwd);
	//�����˻����
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
	//��ʾ�˻����
	int get_money();
	//��ʾ�˻�����
	string get_name();
	//��ʾ�˻�����
	string get_pwd();
	//��ʾ��ϵ�绰
	string get_cell();
	//��ʾ�˻�״̬��Ϣ
	bool get_flag();
	//�˻���Ϣ��ʾ
	void show()
	{
		cout << "���˺���Ϊ" << this->name << endl;
		cout << "������Ϊ" << this->pwd << endl;
		cout << "���˻����ΪΪ" << this->money << endl;
		cout << "���ĵ绰����Ϊ" << this->cell << endl;
	}

};
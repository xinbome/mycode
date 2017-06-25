#include"common.h"

extern map<string, resturant> reststore;
extern vector<deal>dealstore;

void welcome()
{
	cout << "��ӭ�����������綩��ϵͳ" << endl;
	cout << "�����̼Ұ�ͻ���" << endl;
	cout << "ע�����̼��û����밴1" << endl;
	cout << "��¼�̼��û����밴2" << endl;
	cout << "���������˳�ϵͳ���밴3" << endl;
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
		cout << "�����������" << endl;
		cout << "����������" << endl;
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
		cout << "1���ӻ��޸Ĳ���" << endl;
		cout << "2ɾ�����в���" << endl;
		fflush(stdin);
		cin >> choice;
		switch (choice)
		{
		case'1':
		{
			reststore[temp.get_name()].show();
			cout << "������Ҫ���ӻ��޸ĵı��" << endl;
			fflush(stdin);
			cin >> num;
			cout << "�������������" << endl;
			fflush(stdin);
			cin >> change[num];
			cout << "��������ȵļ۸�" << endl;
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
			cout << "������Ҫɾ���ı��" << endl;
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
			cout << "��������" << endl;
		}
		}
		cout << "�˳�������Ϣά�����밴q��������������" << endl;
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
	if (count == dealstore.size()){ cout << "�ܱ�Ǹ������û�˵㵥��" << endl; }
	system("pause");
	system("cls");
}

void cancelorder(resturant temp)
{
	//�͹ݶ˵Ķ���ȡ�� �����漰������  ���������ڿͻ���
	char orderchoice = '0';
	char ynchoice = '0';
	int count = 0;
	for (unsigned int m = 0; m < dealstore.size(); m++)
	{
		if ((dealstore[m].checkdealbyresturant(temp.get_name()) == true) && (dealstore[m].checkdealbyfalg() == '2'))
		{
			dealstore[m].show();
			//���������������
			cout << "�Ƿ�ͬ��ȡ���ö���,��yͬ�⣬��n�ܾ�" << endl;
			cin >> ynchoice;
			if (ynchoice == 'y')
			{
				dealstore[m].set_restflag(false);
				cout << "�ɹ�ȡ��" << endl;
			}
			else
			{
				dealstore[m].set_custflag(true);
				cout << "���ܾ����˸��û���ȡ�����󣬸ö�������Ϊ��Ч����" << endl;
			}
		}
		else
		{
			count++;
		}
	}
	if (count == dealstore.size()){ cout << "��ǰû�д�ȡ���Ķ���" << endl; }
	system("pause");
	system("cls");
}

void function(resturant temp)
{
	//�������׽���
	char functionchoice = '0';
	while (1)
	{
		system("cls");
		cout << reststore[temp.get_name()].get_name() << "����" << endl;
		cout << "�����Ƿ�����ģ��" << endl;
		cout << "��1ά���Լ��˵�" << endl;
		cout << "��2�鿴��ǰ��Ͷ�����ʾ�Ͳ͵�ַ��ѡ��Ĳ�Ʒ������ʱ�䡢���͵绰" << endl;
		cout << "��3��˹˿���������" << endl;
		cout << "��4�˳�������ģ��" << endl;
		while (1)
		{
			fflush(stdin);
			cin >> functionchoice;
			if (functionchoice != '1'&& functionchoice != '2'&&functionchoice != '3'&&functionchoice != '4')
			{
				cout << "������������������" << endl;
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
	cout << "��ӭע���������綩��ϵͳ�̻��˻�" << endl;
	cout << "��������Ҫע����̼���" << endl;
	fflush(stdin);
	cin >> tempname;
	while (1)
	{
		cout << "��������������" << endl;
		fflush(stdin);
		cin >> temppwd;
		cout << "������ȷ����������" << endl;
		fflush(stdin);
		cin >> checktemppwd;
		if (checktemppwd != temppwd)
		{
			cout << "�����������벻һ�£�����������" << endl;
		}
		else
		{
			break;
		}
	}
	int n = 0;
	for (; n < 20; n++)
	{
		cout << "���������͹ݵĲ�����" << endl;
		fflush(stdin);
		cin >> tempfood[n];
		cout << "���������͹ݵĲ˵Ľ��" << endl;
		fflush(stdin);
		cin >> tempcost[n];
		cout << " ����q�˳��˵�����,������������" << endl;
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
	cout << "ע��ɹ�" << endl;
}

void loginsystem()
{
	char loginchoice = '0';
	resturant temp;
	string tempname;
	string temppwd;

	//��¼���� �����˻�ƥ��
	while (1)
	{
		cout << "��������Ҫ��½���̼��˻�����" << endl;
		fflush(stdin);
		cin >> tempname;
		temp.set_name(tempname);
		if (reststore[tempname].get_food()[0] == "undefined")
		{
			reststore.erase("undefined");//����map�����ﴴ���Ĵ���,�Զ���ʼ������ֵ
			cout << "���˻�������" << endl;
		}
		else
		{
			break;
		}
	}
	//��¼���� ����ƥ��
	cout << "�������˻����룬���δ���������˻���������" << endl;
	fflush(stdin);
	cin >> temppwd;
	temp.set_pwd(temppwd);
	if (threechecks(temp) == false)
	{
		cout << "���δ����������룬���˻��Ѿ�����" << endl << "�����˳�ϵͳ" << endl;
		reststore[temp.get_name()].set_flag(false);
		system("pause");
		exit(0);
	}

	system("cls");
	cout << "�ɹ���¼" << endl;
	reststore[temp.get_name()].show();
	system("pause");
	system("cls");
	function(temp);
}

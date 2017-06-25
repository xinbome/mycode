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
		cout << "1�޸�����" << endl;
		cout << "2�޸ĵ绰����" << endl;
		cout << "3�������г�ֵ" << endl;
		fflush(stdin);
		cin >> choice;
		switch (choice)
		{
		case'1':
		{
			custstore[temp.get_name()].show();
			cout << "������Ҫ�޸ĵ�����" << endl;
			fflush(stdin);
			cin >> tempstring;
			custstore[temp.get_name()].set_pwd(tempstring);
			cout << "�޸ĳɹ�" << endl;
			system("pause");
			system("cls");
			break;
		}
		case'2':
		{
			custstore[temp.get_name()].show();
			cout << "������Ҫ�޸ĵĵ绰����" << endl;
			fflush(stdin);
			cin >> tempstring;
			custstore[temp.get_name()].set_cell(tempstring);
			cout << "�޸ĳɹ�" << endl;
			system("pause");
			system("cls");
			break;
		}
		case'3':
		{
			custstore[temp.get_name()].show();
			cout << "������Ҫ����Ľ��" << endl;
			fflush(stdin);
			cin >> num;
			num = num + custstore[temp.get_name()].get_money();
			custstore[temp.get_name()].set_money(num);
			cout << "�ɹ�����" << endl;
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			cout << "��������" << endl;
		}
		}
		cout << "�˳��˺���Ϣά�����밴q,���������" << endl;
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
	cout << "����������Ҫ�Ĳ͹�" << endl;
	fflush(stdin);
	cin >> wantedresturant;
	cout << "����������Ҫ���ײͱ��" << endl;
	fflush(stdin);
	cin >> wantedfood;
	cout << "���������Ķ���ʱ��" << endl;
	fflush(stdin);
	cin >> wantedtime;
	cout << "���������ĵ�ַ" << endl;
	fflush(stdin);
	cin >> wantedaddress;
	deal d(custstore[temp.get_name()].get_name(), wantedresturant, wantedaddress, wantedfood, wantedtime, custstore[temp.get_name()].get_cell(), wantedmoney, true, false);
	wantedmoney = reststore[wantedresturant].get_cost()[wantedfood];
	d.set_money(wantedmoney);//����������
	cout << "�ɹ��µ�" << endl;
	cout << "�Ƿ�ȷ�϶�����������֧������yȷ�ϰ�nȡ������" << endl;
	fflush(stdin);
	cin >> ynchoice;
	if (ynchoice == 'y')
	{
		custstore[temp.get_name()].set_money(custstore[temp.get_name()].get_money() - wantedmoney);//�û��˻���Ǯ
		reststore[wantedresturant].set_money(reststore[wantedresturant].get_money() + wantedmoney);//�̼��˻���Ǯ
		d.set_restflag(true);
		cout << "ȷ��֧��" << endl;
	}
	else
	{
		d.set_custflag(false);
		cout << "����δ֧�����Զ�ע���õ�" << endl;
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
			cout << "�Ƿ�����ȡ����������y����ȡ��" << endl;
			fflush(stdin);
			cin >> ynchoice;
			if (ynchoice == 'y')
			{
				dealstore[m].set_custflag(true);
				cout << "������ȡ��" << endl;
			}
			dealstore[m].set_custflag(false);
		}
		else
		{
			count++;
		}

		//�̼�ͬ��ȡ������˻����䶯-----------------------------------------------------------------------------
		if ((dealstore[m].checkdealbycustomer(temp.get_name()) == true) && (dealstore[m].checkdealbyfalg() == '3') && dealstore[m].get_money() != 0)//�͹ݸ�ȷ��ȡ���Ķ���
		{
			custstore[temp.get_name()].set_money(custstore[temp.get_name()].get_money() + dealstore[m].get_money());//�����˿͵Ķ������
			reststore[dealstore[m].get_resturant_name()].set_money(reststore[dealstore[m].get_resturant_name()].get_money() - dealstore[m].get_money());//�۳��Ѿ����˵Ľ��
		}
	}

	if (count == dealstore.size()){ cout << "��ǰû�����Ķ���" << endl; }
	system("pause");
}

void welcome()
{
	cout << "��ӭ�����������綩��ϵͳ" << endl;
	cout << "���ǹ˿Ͱ�ͻ���" << endl;
	cout << "ע�����û����밴1" << endl;
	cout << "��¼�������û����밴2" << endl;
	cout << "���������˳�ϵͳ���밴3" << endl;
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
		cout << "�����������" << endl;
		cout << "����������" << endl;
		fflush(stdin);
		cin >> temppwd;
		temp.set_pwd(temppwd);
	}
	return false;
}

void function(customer temp)
{
	//�������׽���
	char functionchoice = '0';
	while (1)
	{
		system("cls");
		cout << custstore[temp.get_name()].get_name() << "����" << endl;
		cout << "�����Ƿ�����ģ��" << endl;
		cout << "��1ά��������Ϣ" << endl;
		cout << "��2��ʾ��ѡ�͹ݣ��������µ����Զ����ɶ���,��֧��" << endl;
		cout << "��3�����������" << endl;
		cout << "��4�˳�������ģ��" << endl;
		while (1)
		{
			fflush(stdin);
			cin >> functionchoice;
			if (functionchoice != '1'&& functionchoice != '2'&&functionchoice != '3'&&functionchoice != '4'&&functionchoice != '5')
			{
				cout << "������������������" << endl;
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
	cout << "��ӭע���������綩��ϵͳ�������˻�" << endl;
	cout << "��������Ҫע����˻���" << endl;
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

	cout << "�����������ֻ���" << endl;
	fflush(stdin);
	cin >> tempcell;
	cout << "��������ҪԤ��Ľ��" << endl;
	fflush(stdin);
	cin >> tempmoney;
	customer tre(tempname, temppwd, tempmoney, tempcell, true);
	custstore.insert(pair<string, customer>(tre.get_name(), tre));
	cout << "ע��ɹ�" << endl;
	system("pause");
}

void loginsystem()
{
	char loginchoice = '0';
	customer temp;
	string tempname;
	string temppwd;

	//��¼���� �����˻�ƥ��
	while (1)
	{
		cout << "��������Ҫ��½���̼��˻�����" << endl;
		fflush(stdin);
		cin >> tempname;
		temp.set_name(tempname);
		if (custstore[tempname].get_cell() == "undefined")
		{
			custstore.erase("undefined");//����map�����ﴴ���Ĵ���,�Զ���ʼ������ֵ
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
		custstore[temp.get_name()].set_flag(false);
		system("pause");
		exit(0);
	}

	system("cls");
	cout << "�ɹ���¼" << endl;
	custstore[temp.get_name()].show();
	system("pause");
	system("cls");
	function(temp);
}


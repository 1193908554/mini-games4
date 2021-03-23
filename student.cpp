#include"student.h"

//Ĭ�Ϲ���
Student::Student()
{

}

//�вι��죨ѧ�š����������룩
Student::Student(int id, string name, string pwd)
{
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	initComputer();
}

//�˵�����
void Student::operMenu()
{
	cout << "��ӭѧ����" << this->m_Name << "��¼" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.����ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.�鿴�ҵ�ԤԼ       |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        3.�鿴ȫ��ԤԼ       |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        4.ȡ��ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.ע����¼           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;

	cout << "��ѡ�����Ĳ�����" << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "������ԤԼʱ��:" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int date = 0;//����
	int interval = 0;// ʱ���  ���绹������
	int room = 0;//�������

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "������������������!" << endl;
		}
	}

	cout << "����������ԤԼʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}
		else
		{
			cout << "������������������!" << endl;
		}
	}

	cout << "��ѡ�������" << endl;
	for (vector< ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << it->m_ComId << "�Ż�������Ϊ��" << it->m_MaxNum << endl;
	}

	while (true)
	{
		cin >> room;
		if (room > 0 && room <= vCom.size())
		{
			break;
		}
		else
		{
			cout << "������������������!" << endl;
		}
	}



	ofstream ofs;

	ofs.open(ORDER_FILE, ios::app);//׷��

	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�ԤԼδ�ɹ��������³���" << endl;
		ofs.close();
		return;
	}

	ofs << "date:" << date << " ";			   //ԤԼʱ��
	ofs << "interval:" << interval << " ";     //ԤԼʱ���
	ofs << "stuId:" << this->m_Id << " ";	   //ѧ��ѧ��
	ofs << "stuName:" << this->m_Name << " ";  //ѧ������
	ofs << "roomId:" << room << " ";		   //�������
	ofs << "status:" << 1 << endl;             //ԤԼ״̬

	ofs.close();

	cout << "ԤԼ�ɹ��������" << endl;

	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (0 == of.m_Size)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == this->m_Id)
		{   //�����ַ��������ֲ��ܶԱ�  ������ת��c���Է���ַ���c_str()   
			//Ȼ����ת��������  atoi()
			cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << "\t";
			cout << "ʱ�Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����")  << "\t";
			cout << "������" << of.m_orderDate[i]["roomId"] << "\t";
			string status = "״̬��";//0 ȡ��ԤԼ  1 �����  2 ��ԤԼ   -1 ԤԼʧ��
			if ("1" == of.m_orderDate[i]["status"])
			{
				status += "�����";
			}
			else if ("2" == of.m_orderDate[i]["status"])
			{
				status += "ԤԼ�ɹ�";
			}
			else if ("-1" == of.m_orderDate[i]["status"])
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
} 

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (0 == of.m_Size)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";

		cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << " ";
		cout << "ʱ�Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ�ţ�" << of.m_orderDate[i]["stuId"] << " ";
		cout << "������" << of.m_orderDate[i]["stuName"] << " ";
		cout << "������" << of.m_orderDate[i]["roomId"] << " ";
		string status = "״̬��";//0 ȡ��ԤԼ  1 �����  2 ��ԤԼ   -1 ԤԼʧ��
		if ("1" == of.m_orderDate[i]["status"])
		{
			status += "�����";
		}
		else if ("2" == of.m_orderDate[i]["status"])
		{
			status += "ԤԼ�ɹ�";
		}
		else if ("-1" == of.m_orderDate[i]["status"])
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (0 == of.m_Size)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v;//������������ ���������±���
	int index = 1;//���
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == this->m_Id)//�ж��Ƿ�������ѧ��
		{
			if (atoi(of.m_orderDate[i]["status"].c_str()) == 1
				|| atoi(of.m_orderDate[i]["status"].c_str()) == 2)//���ԤԼ�ɹ���ԤԼ��
			{
				v.push_back(i);//��������������Ϣ �� �ļ��е� �ı��

				cout << index++ << endl;
				cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << " ";
				cout << "ʱ�Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����") << " ";
				cout << "������" << of.m_orderDate[i]["roomId"] << " ";
				string status = "״̬��";//0 ȡ��ԤԼ  1 �����  2 ��ԤԼ   -1 ԤԼʧ��
				if ("1" == of.m_orderDate[i]["status"])
				{
					status += "�����";
				}
				else if ("2" == of.m_orderDate[i]["status"])
				{
					status += "ԤԼ�ɹ�";
				}
				else if ("-1" == of.m_orderDate[i]["status"])
				{
					status += "���δͨ����ԤԼʧ��";
				}
				else
				{
					status += "ԤԼ��ȡ��";
				}
				cout << status << endl;
			}
		}
	}

	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;//��������ѧ����Ҫȡ����ԤԼ����
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 1)
			{
				break;
			}
			cout << "��¼����λ�ã�" << v[select - 1] << endl;
			of.m_orderDate[v[select - 1]]["status"] = "0";
			of.updateOrder();//����ԤԼ��¼
			cout << "ȡ���ɹ���" << endl;
			break;
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}


//��ʼ��������Ϣ
void Student::initComputer()
{
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);//���ļ�

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c); 
	}
	//cout << "��ǰ��������Ϊ��" << vCom.size() << endl;

	ifs.close();//�ر�
}
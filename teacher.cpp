#include"teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	//��ʼ������
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.�鿴ȫ��ԤԼ       |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.���ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.ע����¼           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;

	cout << "��ѡ�����Ĳ�����" << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (0 == of.m_Size)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "=========================ԤԼ��¼����============================" << endl;
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

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;

	if (0 == of.m_Size)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int>v;//������������ ���������±���
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderDate[i]["status"].c_str()) == 1)//�ж��Ƿ�������ѧ��
		{
			v.push_back(i);//��������������Ϣ �� �ļ��е� �ı��

			cout << index++ << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << " ";
			cout << "ʱ�Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "������" << of.m_orderDate[i]["roomId"] << " ";
			string status = "״̬�������";//0 ȡ��ԤԼ  1 �����  2 ��ԤԼ   -1 ԤԼʧ��
		    /*if ("1" == of.m_orderDate[i]["status"])
			{
				status += "�����";
			}*/
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0������" << endl;

	int select = 0;//���������ʦ��Ҫ��˵ı��
	int ret = 0;//������˵Ľ��
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			cout << "��������˽��" << endl;
			cout << "1��ͨ��" << endl;
			cout << "2����ͨ��" << endl;

			while (true)
			{
				cin >> ret;
				if (1 == ret)
				{
					of.m_orderDate[v[select - 1]]["status"] = "2";
					break;
				}
				else if (2 == ret)
				{
					of.m_orderDate[v[select - 1]]["status"] = "-1";
					break;
				}
				else
				{
					cout << "����������������룡" << endl;
				}
			}

			of.updateOrder();//����ԤԼ��¼
			cout << "�����ϣ�" << endl;
			break;
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}
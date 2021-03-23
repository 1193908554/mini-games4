#include"manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι��죨���������룩
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������
	this->initVector();	

	//��ȡ������Ϣ
	initComputer();

}

//�˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.����˺�           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.�鿴�˺�           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        3.�鿴����           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        4.���ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.ע����¼           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;

	cout << "��ѡ�����Ĳ�����" << endl;

}

//����˺�
void Manager::addPerson()
{
	string fileName;//�ļ�����
	string tip;//��ʾid��

	ofstream ofs;

	int select = 0;

	string errorTip;//�ظ�����

	while (true)
	{
		cout << "����������˺����ͣ�" << endl;
		cout << "1�����ѧ��" << endl;
		cout << "2�������ʦ" << endl;

		cin >> select;

		if (1 == select)
		{
			fileName = STUDENT_FILE;
			tip = "������ѧ�ţ�";
			errorTip = "ѧ���ظ�������������";
			break;
		}
		else if (2 == select)
		{
			fileName = TEACHER_FILE;
			tip = "������ְ���ţ�";
			errorTip = "ְ�����ظ�������������";
			break;
		}
		else
		{
			cout << "�����������������!" << endl;
			system("pause");
			system("cls");
			operMenu();//�ٴ���ʾ�ӽ���
		}
	} 

	ofs.open(fileName, ios::out | ios::app);//out - д    app - ׷��

	int id;//ѧ�� �� ְ����
	string name;//����
	string pwd;//����


	while (true)
	{
		cout << tip << endl;
		cin >> id;

		bool ret = this->checkRepeat(id, select);

		if (ret)//�ظ�
		{
			cout << errorTip << endl;
		}
		else//���ظ�  �˳�ѭ��
		{
			break;
		}
	}

	cout << "����������:" << endl;
	cin >> name;

	cout << "����������:" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << "\n";
	cout << "��ӳɹ�" << endl;

	

	system("pause");
	system("cls");

	ofs.close();//�ر��ļ�������

	//����ӵ��˺Ų������̸��µ�������  ���Դ˿���Ҫ����������һ�ζ�ȡ����
	this->initVector();

}

//ѧ��	
void PrintStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
 }

//�鿴�˺�
void Manager::showPerson()
{
	
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;

	int select = 0;//��¼�û���ѡ��

	cin >> select;
	//����ʹ�������ֱ�������
	if (1 == select)//ѧ��
	{
		cout << "=========����ѧ����Ϣ����=========" << endl;
		for_each(vStu.begin(), vStu.end(), PrintStudent);
	}
	else//��ʦ
	{
		cout << "=========���н�ʦ��Ϣ����=========" << endl;
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			cout << "ְ���ţ�" << it->m_EmpId 
				<< "\t������" << it->m_Name << "\t���룺" << it->m_Pwd << endl;
		}
	}

	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << "\t�����������" << it->m_MaxNum << endl;
	}

	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::clearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);//�ļ����ھ�ɾ����д����
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ��������Ϣ
void Manager::initComputer()
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

//��ʼ������
void Manager::initVector()
{
	//ѧ���ļ�����ʦ�ļ����
	vStu.clear();
	vStu.clear();

	//��ȡѧ���ļ���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);//in - ��
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);//����������
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();//�ر�

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;

	ifs.close();//�ر�
}


//����ظ�   ����id  ��������     true - �ظ�  false - δ�ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (1 == type)//ѧ��
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else if (2 == type)//��ʦ
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
#include<iostream>
#include<string>
#include<fstream>	    //�ļ� ������
#include"globalFile.h"	//ȫ���ļ�
#include"identity.h"	//��ݻ���
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;

//�����ʦ�Ӳ˵�����
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		//���ý�ʦ�Ӳ˵�
		teacher->operMenu();

		//������ָ��  תΪ����ָ�룬���������������Ľӿ�
		Teacher* tea = (Teacher*)teacher;

		int select = 0;//��¼����Աѡ��

		cin >> select;

		switch (select)
		{
		case 1://�鿴����ԤԼ
			tea->showAllOrder();
			break;
		case 2://���ԤԼ
			tea->validOrder();
			break;
		case 0://ע����¼
			delete teacher;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");//Ϊ�ù���Ա����  ��Ȼ�Ϸ���ʾ��Ϣ�ͻ�һ������
			system("cls");
			return;
			break;
		default://�������
			system("pause");//Ϊ��ѧ������  ��Ȼ�Ϸ���ʾ��Ϣ�ͻ�һ������
			system("cls");
			break;
		}
	}
}

//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		//������ָ��  תΪ����ָ�룬���������������Ľӿ�
		Student* stu = (Student*)student;

		int select = 0;//��¼����Աѡ��

		cin >> select;

		switch (select)
		{
		case 1://����ԤԼ
			stu->applyOrder();
			break;
		case 2://�鿴����ԤԼ
			stu->showMyOrder();
			break;
		case 3://�鿴����ԤԼ
			stu->showAllOrder();
				break;
		case 4://ȡ��ԤԼ
			stu->cancelOrder();
			break;
		case 0://ע����¼
			delete student;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");//Ϊ�ù���Ա����  ��Ȼ�Ϸ���ʾ��Ϣ�ͻ�һ������
			system("cls");
			return;
			break;
		default://�������
			system("pause");//Ϊ��ѧ������  ��Ȼ�Ϸ���ʾ��Ϣ�ͻ�һ������
			system("cls");
			break;
		}
	}
}

//�������Ա�Ӳ˵�
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ��  תΪ����ָ�룬���������������Ľӿ�
		Manager* man = (Manager*)manager;

		int select = 0;//��¼����Աѡ��

		cin >> select;

		switch (select)
		{
		case 1://����˺�
			//cout << "����˺�" << endl;
			man->addPerson();
			break;
		case 2://�鿴�˺�
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
			break;
		case 3://�鿴������Ϣ
			//cout << "�鿴������Ϣ" << endl;
			man->showComputer();
			break;
		case 4://���ԤԼ
			//cout << "���ԤԼ" << endl;
			man->clearFile();
			break;
		case 0:
			delete manager;//���ٶ�������
			cout << "ע���ɹ���" << endl;
			system("pause");//Ϊ�ù���Ա����  ��Ȼ�Ϸ���ʾ��Ϣ�ͻ�һ������
			system("cls");
			return;
			break;
		default://�������
			cout << "�����������������ԣ�" << endl;
			system("pause");//Ϊ�ù���Ա����  ��Ȼ�Ϸ���ʾ��Ϣ�ͻ�һ������
			system("cls");
			break;
		}
	}
}

//��¼����
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;//����ָ��  ����ָ����������

	ifstream ifs;
	ifs.open(fileName, ios::in);//in-��

	//�ļ������ڵ����
	if (!ifs.is_open())//ifs.is_open() - ���ڷ���true
	{
		cout << "�ļ�������" << endl;
		ifs.close();//�ر��ļ���
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (1 == type)//ѧ��
	{
		cout << "���������ѧ��:" << endl;
		cin >> id;
	}
	else if (2 == type)
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (1 == type)
	{
		//ѧ����¼��֤
		int fId;//���ļ��ж�ȡ ѧ�� ����  ����
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)//�Դ�ȡ������
		{
			if (id == fId && name == fName && pwd == fPwd)//�û�����ĶԱ��ļ������
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);

				return;
			}
		}
	}
	else if (2 == type)
	{
		//��ʦ��¼��֤
		int fId;//���ļ��ж�ȡ �̹��� ����  ����
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)//�Դ�ȡ������
		{
			if (id == fId && name == fName && pwd == fPwd)//�û�����ĶԱ��ļ������
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//�����ʦ��ݵ��Ӳ˵�
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (3 == type)
	{
		//����Ա��¼��֤
		string fName;//���ļ��ж�ȡ  ����  ����
		string fPwd;

		while (ifs >> fName && ifs >> fPwd)//�Դ�ȡ������
		{
			if (name == fName && pwd == fPwd)//�û�����ĶԱ��ļ������
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);
				return;
			}
		}

	}
	cout << "��¼��֤ʧ�ܣ�" << endl;

	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;//�����û���ѡ��  �ı���

	while (true)
	{
		cout << "==============��ӭ������Ϧ��������ϵͳ==============" << endl;
		cout << endl << "������������" << endl;
		cout << "\t\t  ---------------------- " << endl;
		cout << "\t\t |----------------------| " << endl;
		cout << "\t\t |-------1.ѧ������-----| " << endl;
		cout << "\t\t |----------------------| " << endl;
		cout << "\t\t |-------2.��    ʦ-----| " << endl;
		cout << "\t\t |----------------------| " << endl;
		cout << "\t\t |-------3.�� �� Ա-----| " << endl;
		cout << "\t\t |----------------------| " << endl;
		cout << "\t\t |-------0.��    ��-----| " << endl;
		cout << "\t\t |----------------------| " << endl;
		cout << "\t\t  ---------------------- " << endl;
		cout << "���������ѡ��" << endl;

		cin >> select;//�����û�ѡ��


		switch (select)
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ��һ��ʹ�ã��ټ���" << endl;
			system("pause");
			return 0;
			break;
		default://�������
			cout << "�����������������룡" << endl;
			system("pause");//Ϊ���û�����  ��Ȼ�Ϸ���ʾ��Ϣ�ͻ�һ������
			system("cls");
			break;
		}

	}

	

	system("pause");
	return 0;
}
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include"identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
using namespace std;

class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι��죨���������룩
	Manager(string name, string pwd);

	//�˵�����
	virtual void operMenu();//����Ĵ��麯�� �������ʵ����д����ʵ��������

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void clearFile();

	//��ʼ������
	void initVector();

	//����ظ�   ����id  ��������     true - �ظ�  false - δ�ظ�
	bool checkRepeat(int id, int type);

	//��ʼ��������Ϣ
	void initComputer();

	//��������
	vector<ComputerRoom> vCom;

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;
};
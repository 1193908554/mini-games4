#pragma once
#include<iostream>
#include<string> 
#include<vector>
#include<fstream>
#include"identity.h"
#include"globalFile.h"
#include "computerRoom.h"
#include"orderFile.h"
using namespace std;


//ѧ����  �̳г�����ࣨidentity��
class Student :public Identity
{
public:

	//Ĭ�Ϲ���
	Student();
	
	//�вι��죨ѧ�š����������룩
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();//����Ĵ��麯�� �������ʵ����д����ʵ��������

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//��ʼ��������Ϣ
	void initComputer();

public:

	//��ȸ��� ѧ������˸�ѧ��
	int m_Id;//ѧ��

	//��������
	vector<ComputerRoom> vCom;

};
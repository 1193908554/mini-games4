#pragma once
#include<iostream>
#include<vector>
#include"identity.h"
#include"orderFile.h"
using namespace std;

//��ʦ��   �̳г�����ࣨidentity��
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();//����Ĵ��麯�� �������ʵ����д����ʵ��������

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();


public:

	//��ȸ��� ��ʦ����˸���ʦ���
	int m_EmpId;//��ʦ���
};
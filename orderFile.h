#pragma once
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include"globalFile.h"
using namespace std;


class OrderFile
{
public:

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������  key-��¼�������ı��   value-�����¼�ļ�ֵ����Ϣ<���ԣ�ʵֵ>
	map<int, map<string, string>>m_orderDate;

	//ԤԼ��¼����
	int m_Size;
};
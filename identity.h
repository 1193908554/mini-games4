#pragma once//��ֹͷ�ļ��ظ�����  ���³����ٶȽ���
#include<iostream>
#include<string>
using namespace std;

//��ݳ����� - ����
class Identity  
{
public:

	//�����˵�
	//����ǰ�����virtual  �������  =0  �ͳ��˴��麯��  �����Ҳ�ͳ��˳�����
	//ÿ�������֤�ɹ��󣬶��������Ե��Ӳ˵�  ����ֱ����д����  --��̬����
	virtual void operMenu() = 0;

public:
	string m_Name;//����
	string m_Pwd;//����

};
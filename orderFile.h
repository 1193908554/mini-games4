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

	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录的容器  key-记录的条数的编号   value-具体记录的键值对信息<属性，实值>
	map<int, map<string, string>>m_orderDate;

	//预约记录条数
	int m_Size;
};
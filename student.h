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


//学生类  继承抽象基类（identity）
class Student :public Identity
{
public:

	//默认构造
	Student();
	
	//有参构造（学号、姓名、密码）
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void operMenu();//父类的纯虚函数 子类必须实现重写才能实例化对象

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//初始化机房信息
	void initComputer();

public:

	//相比父类 学生类多了个学号
	int m_Id;//学号

	//机房容器
	vector<ComputerRoom> vCom;

};
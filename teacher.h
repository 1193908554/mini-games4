#pragma once
#include<iostream>
#include<vector>
#include"identity.h"
#include"orderFile.h"
using namespace std;

//教师类   继承抽象基类（identity）
class Teacher :public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造
	Teacher(int empId, string name, string pwd);

	//菜单界面
	virtual void operMenu();//父类的纯虚函数 子类必须实现重写才能实例化对象

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();


public:

	//相比父类 教师类多了个教师编号
	int m_EmpId;//教师编号
};
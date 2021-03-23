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
	//默认构造
	Manager();

	//有参构造（姓名，密码）
	Manager(string name, string pwd);

	//菜单界面
	virtual void operMenu();//父类的纯虚函数 子类必须实现重写才能实例化对象

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void clearFile();

	//初始化容器
	void initVector();

	//检测重复   传入id  传入类型     true - 重复  false - 未重复
	bool checkRepeat(int id, int type);

	//初始化机房信息
	void initComputer();

	//机房容器
	vector<ComputerRoom> vCom;

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;
};
#pragma once//防止头文件重复包含  导致程序速度降低
#include<iostream>
#include<string>
using namespace std;

//身份抽象类 - 基类
class Identity  
{
public:

	//操作菜单
	//函数前面加上virtual  后面加上  =0  就成了纯虚函数  这个类也就成了抽象类
	//每个身份验证成功后，都会进入各自的子菜单  子类直接重写即可  --多态技术
	virtual void operMenu() = 0;

public:
	string m_Name;//姓名
	string m_Pwd;//密码

};
#include<iostream>
#include<string>
#include<fstream>	    //文件 流对象
#include"globalFile.h"	//全局文件
#include"identity.h"	//身份基类
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;

//进入教师子菜单界面
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用教师子菜单
		teacher->operMenu();

		//将父类指针  转为子类指针，调用子类里其他的接口
		Teacher* tea = (Teacher*)teacher;

		int select = 0;//记录管理员选择

		cin >> select;

		switch (select)
		{
		case 1://查看所有预约
			tea->showAllOrder();
			break;
		case 2://审核预约
			tea->validOrder();
			break;
		case 0://注销登录
			delete teacher;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");//为让管理员看清  不然上方提示信息就会一闪而过
			system("cls");
			return;
			break;
		default://其他情况
			system("pause");//为让学生看清  不然上方提示信息就会一闪而过
			system("cls");
			break;
		}
	}
}

//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();

		//将父类指针  转为子类指针，调用子类里其他的接口
		Student* stu = (Student*)student;

		int select = 0;//记录管理员选择

		cin >> select;

		switch (select)
		{
		case 1://申请预约
			stu->applyOrder();
			break;
		case 2://查看自身预约
			stu->showMyOrder();
			break;
		case 3://查看所有预约
			stu->showAllOrder();
				break;
		case 4://取消预约
			stu->cancelOrder();
			break;
		case 0://注销登录
			delete student;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");//为让管理员看清  不然上方提示信息就会一闪而过
			system("cls");
			return;
			break;
		default://其他情况
			system("pause");//为让学生看清  不然上方提示信息就会一闪而过
			system("cls");
			break;
		}
	}
}

//进入管理员子菜单
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();

		//将父类指针  转为子类指针，调用子类里其他的接口
		Manager* man = (Manager*)manager;

		int select = 0;//记录管理员选择

		cin >> select;

		switch (select)
		{
		case 1://添加账号
			//cout << "添加账号" << endl;
			man->addPerson();
			break;
		case 2://查看账号
			//cout << "查看账号" << endl;
			man->showPerson();
			break;
		case 3://查看机房信息
			//cout << "查看机房信息" << endl;
			man->showComputer();
			break;
		case 4://清空预约
			//cout << "清空预约" << endl;
			man->clearFile();
			break;
		case 0:
			delete manager;//销毁堆区对象
			cout << "注销成功！" << endl;
			system("pause");//为让管理员看清  不然上方提示信息就会一闪而过
			system("cls");
			return;
			break;
		default://其他情况
			cout << "输入有误，请重新再试！" << endl;
			system("pause");//为让管理员看清  不然上方提示信息就会一闪而过
			system("cls");
			break;
		}
	}
}

//登录功能
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;//父类指针  用于指向自子类象

	ifstream ifs;
	ifs.open(fileName, ios::in);//in-读

	//文件不存在的情况
	if (!ifs.is_open())//ifs.is_open() - 存在返回true
	{
		cout << "文件不存在" << endl;
		ifs.close();//关闭文件流
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (1 == type)//学生
	{
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (2 == type)
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (1 == type)
	{
		//学生登录验证
		int fId;//从文件中读取 学号 姓名  密码
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)//以此取出数据
		{
			if (id == fId && name == fName && pwd == fPwd)//用户输入的对比文件保存的
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//进入学生身份的子菜单
				studentMenu(person);

				return;
			}
		}
	}
	else if (2 == type)
	{
		//教师登录验证
		int fId;//从文件中读取 教工号 姓名  密码
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)//以此取出数据
		{
			if (id == fId && name == fName && pwd == fPwd)//用户输入的对比文件保存的
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进入教师身份的子菜单
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (3 == type)
	{
		//管理员登录验证
		string fName;//从文件中读取  姓名  密码
		string fPwd;

		while (ifs >> fName && ifs >> fPwd)//以此取出数据
		{
			if (name == fName && pwd == fPwd)//用户输入的对比文件保存的
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//进入管理员身份的子菜单
				managerMenu(person);
				return;
			}
		}

	}
	cout << "登录验证失败！" << endl;

	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;//接受用户的选择  的变量

	while (true)
	{
		cout << "==============欢迎来到林夕机房管理系统==============" << endl;
		cout << endl << "请输入你的身份" << endl;
		cout << "\t\t  ---------------------- " << endl;
		cout << "\t\t |----------------------| " << endl;
		cout << "\t\t |-------1.学生代表-----| " << endl;
		cout << "\t\t |----------------------| " << endl;
		cout << "\t\t |-------2.老    师-----| " << endl;
		cout << "\t\t |----------------------| " << endl;
		cout << "\t\t |-------3.管 理 员-----| " << endl;
		cout << "\t\t |----------------------| " << endl;
		cout << "\t\t |-------0.退    出-----| " << endl;
		cout << "\t\t |----------------------| " << endl;
		cout << "\t\t  ---------------------- " << endl;
		cout << "请输入你的选择：" << endl;

		cin >> select;//接受用户选择


		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://教师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下一次使用，再见！" << endl;
			system("pause");
			return 0;
			break;
		default://其他情况
			cout << "输入有误，请重新输入！" << endl;
			system("pause");//为让用户看清  不然上方提示信息就会一闪而过
			system("cls");
			break;
		}

	}

	

	system("pause");
	return 0;
}
#include"manager.h"

//默认构造
Manager::Manager()
{

}

//有参构造（姓名，密码）
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器
	this->initVector();	

	//获取机房信息
	initComputer();

}

//菜单界面
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.添加账号           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.查看账号           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        3.查看机房           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        4.清空预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.注销登录           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;

	cout << "请选择您的操作：" << endl;

}

//添加账号
void Manager::addPerson()
{
	string fileName;//文件名称
	string tip;//提示id号

	ofstream ofs;

	int select = 0;

	string errorTip;//重复提醒

	while (true)
	{
		cout << "请输入添加账号类型：" << endl;
		cout << "1、添加学生" << endl;
		cout << "2、添加老师" << endl;

		cin >> select;

		if (1 == select)
		{
			fileName = STUDENT_FILE;
			tip = "请输入学号：";
			errorTip = "学号重复，请重新输入";
			break;
		}
		else if (2 == select)
		{
			fileName = TEACHER_FILE;
			tip = "请输入职工号：";
			errorTip = "职工号重复，请重新输入";
			break;
		}
		else
		{
			cout << "输入错误，请重新输入!" << endl;
			system("pause");
			system("cls");
			operMenu();//再次显示子界面
		}
	} 

	ofs.open(fileName, ios::out | ios::app);//out - 写    app - 追加

	int id;//学号 或 职工号
	string name;//姓名
	string pwd;//密码


	while (true)
	{
		cout << tip << endl;
		cin >> id;

		bool ret = this->checkRepeat(id, select);

		if (ret)//重复
		{
			cout << errorTip << endl;
		}
		else//不重复  退出循环
		{
			break;
		}
	}

	cout << "请输入姓名:" << endl;
	cin >> name;

	cout << "请输入密码:" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << "\n";
	cout << "添加成功" << endl;

	

	system("pause");
	system("cls");

	ofs.close();//关闭文件输入流

	//刚添加的账号不会立刻更新到容器中  所以此刻需要在让容器做一次读取操作
	this->initVector();

}

//学生	
void PrintStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
 }

//查看账号
void Manager::showPerson()
{
	
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有教师" << endl;

	int select = 0;//记录用户的选择

	cin >> select;
	//以下使用了俩种遍历方法
	if (1 == select)//学生
	{
		cout << "=========所有学生信息如下=========" << endl;
		for_each(vStu.begin(), vStu.end(), PrintStudent);
	}
	else//教师
	{
		cout << "=========所有教师信息如下=========" << endl;
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			cout << "职工号：" << it->m_EmpId 
				<< "\t姓名：" << it->m_Name << "\t密码：" << it->m_Pwd << endl;
		}
	}

	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << "\t机房最大容量" << it->m_MaxNum << endl;
	}

	system("pause");
	system("cls");
}

//清空预约记录
void Manager::clearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);//文件存在就删除重写创建
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化机房信息
void Manager::initComputer()
{
	
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);//读文件

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	//cout << "当前机房数量为：" << vCom.size() << endl;

	ifs.close();//关闭
}

//初始化容器
void Manager::initVector()
{
	//学生文件和老师文件清空
	vStu.clear();
	vStu.clear();

	//读取学生文件信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);//in - 读
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);//放在容器中
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();//关闭

	//读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为：" << vTea.size() << endl;

	ifs.close();//关闭
}


//检测重复   传入id  传入类型     true - 重复  false - 未重复
bool Manager::checkRepeat(int id, int type)
{
	if (1 == type)//学生
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else if (2 == type)//老师
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
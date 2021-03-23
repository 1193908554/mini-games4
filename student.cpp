#include"student.h"

//默认构造
Student::Student()
{

}

//有参构造（学号、姓名、密码）
Student::Student(int id, string name, string pwd)
{
	//初始化属性
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化机房信息
	initComputer();
}

//菜单界面
void Student::operMenu()
{
	cout << "欢迎学生：" << this->m_Name << "登录" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.申请预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.查看我的预约       |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        3.查看全部预约       |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        4.取消预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.注销登录           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;

	cout << "请选择您的操作：" << endl;
}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一到周五！" << endl;
	cout << "请输入预约时间:" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int date = 0;//日期
	int interval = 0;// 时间段  上午还是下午
	int room = 0;//机房编号

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "输入有误！请重新输入!" << endl;
		}
	}

	cout << "请输入申请预约时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}
		else
		{
			cout << "输入有误！请重新输入!" << endl;
		}
	}

	cout << "请选择机房：" << endl;
	for (vector< ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << it->m_ComId << "号机房容量为：" << it->m_MaxNum << endl;
	}

	while (true)
	{
		cin >> room;
		if (room > 0 && room <= vCom.size())
		{
			break;
		}
		else
		{
			cout << "输入有误！请重新输入!" << endl;
		}
	}



	ofstream ofs;

	ofs.open(ORDER_FILE, ios::app);//追加

	if (!ofs.is_open())
	{
		cout << "文件打开失败！预约未成功，请重新尝试" << endl;
		ofs.close();
		return;
	}

	ofs << "date:" << date << " ";			   //预约时间
	ofs << "interval:" << interval << " ";     //预约时间段
	ofs << "stuId:" << this->m_Id << " ";	   //学生学号
	ofs << "stuName:" << this->m_Name << " ";  //学生姓名
	ofs << "roomId:" << room << " ";		   //机房编号
	ofs << "status:" << 1 << endl;             //预约状态

	ofs.close();

	cout << "预约成功！审核中" << endl;

	system("pause");
	system("cls");
}

//查看我的预约
void Student::showMyOrder()
{
	OrderFile of;
	if (0 == of.m_Size)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == this->m_Id)
		{   //本身字符串和数字不能对比  所以先转成c语言风格字符串c_str()   
			//然后再转换成整型  atoi()
			cout << "预约日期：周" << of.m_orderDate[i]["date"] << "\t";
			cout << "时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午")  << "\t";
			cout << "机房：" << of.m_orderDate[i]["roomId"] << "\t";
			string status = "状态：";//0 取消预约  1 审核中  2 以预约   -1 预约失败
			if ("1" == of.m_orderDate[i]["status"])
			{
				status += "审核中";
			}
			else if ("2" == of.m_orderDate[i]["status"])
			{
				status += "预约成功";
			}
			else if ("-1" == of.m_orderDate[i]["status"])
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
} 

//查看所有预约
void Student::showAllOrder()
{
	OrderFile of;
	if (0 == of.m_Size)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";

		cout << "预约日期：周" << of.m_orderDate[i]["date"] << " ";
		cout << "时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号：" << of.m_orderDate[i]["stuId"] << " ";
		cout << "姓名：" << of.m_orderDate[i]["stuName"] << " ";
		cout << "机房：" << of.m_orderDate[i]["roomId"] << " ";
		string status = "状态：";//0 取消预约  1 审核中  2 以预约   -1 预约失败
		if ("1" == of.m_orderDate[i]["status"])
		{
			status += "审核中";
		}
		else if ("2" == of.m_orderDate[i]["status"])
		{
			status += "预约成功";
		}
		else if ("-1" == of.m_orderDate[i]["status"])
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (0 == of.m_Size)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int>v;//存放最大容器中 属于他的下标编号
	int index = 1;//编号
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == this->m_Id)//判断是否是自身学号
		{
			if (atoi(of.m_orderDate[i]["status"].c_str()) == 1
				|| atoi(of.m_orderDate[i]["status"].c_str()) == 2)//针对预约成功或预约中
			{
				v.push_back(i);//保存属于他的信息 在 文件中的 的编号

				cout << index++ << endl;
				cout << "预约日期：周" << of.m_orderDate[i]["date"] << " ";
				cout << "时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "机房：" << of.m_orderDate[i]["roomId"] << " ";
				string status = "状态：";//0 取消预约  1 审核中  2 以预约   -1 预约失败
				if ("1" == of.m_orderDate[i]["status"])
				{
					status += "审核中";
				}
				else if ("2" == of.m_orderDate[i]["status"])
				{
					status += "预约成功";
				}
				else if ("-1" == of.m_orderDate[i]["status"])
				{
					status += "审核未通过，预约失败";
				}
				else
				{
					status += "预约已取消";
				}
				cout << status << endl;
			}
		}
	}

	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;//用来保存学生需要取消的预约申请
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 1)
			{
				break;
			}
			cout << "记录所在位置：" << v[select - 1] << endl;
			of.m_orderDate[v[select - 1]]["status"] = "0";
			of.updateOrder();//更新预约记录
			cout << "取消成功！" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}


//初始化机房信息
void Student::initComputer()
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
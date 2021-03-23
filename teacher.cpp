#include"teacher.h"

//默认构造
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
	//初始化属性
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.查看全部预约       |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.审核预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.注销登录           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;

	cout << "请选择您的操作：" << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (0 == of.m_Size)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "=========================预约记录如下============================" << endl;
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

//审核预约
void Teacher::validOrder()
{
	OrderFile of;

	if (0 == of.m_Size)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "该审核的预约记录如下：" << endl;

	vector<int>v;//存放最大容器中 属于他的下标编号
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderDate[i]["status"].c_str()) == 1)//判断是否是自身学号
		{
			v.push_back(i);//保存属于他的信息 在 文件中的 的编号

			cout << index++ << "、";
			cout << "预约日期：周" << of.m_orderDate[i]["date"] << " ";
			cout << "时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房：" << of.m_orderDate[i]["roomId"] << " ";
			string status = "状态：审核中";//0 取消预约  1 审核中  2 以预约   -1 预约失败
		    /*if ("1" == of.m_orderDate[i]["status"])
			{
				status += "审核中";
			}*/
			cout << status << endl;
		}
	}
	cout << "请输入审核的预约记录，0代表返回" << endl;

	int select = 0;//用来保存教师需要审核的编号
	int ret = 0;//保存审核的结果
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			cout << "请输入审核结果" << endl;
			cout << "1、通过" << endl;
			cout << "2、不通过" << endl;

			while (true)
			{
				cin >> ret;
				if (1 == ret)
				{
					of.m_orderDate[v[select - 1]]["status"] = "2";
					break;
				}
				else if (2 == ret)
				{
					of.m_orderDate[v[select - 1]]["status"] = "-1";
					break;
				}
				else
				{
					cout << "输入错误，请重新输入！" << endl;
				}
			}

			of.updateOrder();//更新预约记录
			cout << "审核完毕！" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
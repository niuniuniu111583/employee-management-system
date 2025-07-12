#include<iostream>////职工三类：普通员工、经理、老板
#include "workerManager.h"
#include "worker.h"
using namespace std;
int main()
{
	WorkerManager wm;

	
	int choice = 0;
	while (true)
	{
		wm.show_menu();
		cout << "请输入你的选项：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:		//退出
			wm.exitSystem();
			break;
		case 1:		//添加
			wm.addEp();
			break;
		case 2:		//显示
			wm.showEp();
			break;
		case 3:		//删除
			wm.deleteEp();
			break;
		case 4:		//修改
			wm.changeEp();
			break;
		case 5:		//查找
			wm.findEp();
			break;
		case 6:		//排序
			wm.sortEp();
			break;
		case 7:		//清空
			wm.clearEp();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");

	return 0;
}


//遇到的问题：
//覆盖掉原来文件数据了，但我不是用init_Ep将原数据存到数组里了吗
//写入newsapce时缓冲区溢出
//用ifs读文件时会跳过空白字符，而用cin，则会视为结束
//本来想直接让numEp等于num，但不能在构造函数中调用任何含未初始化的成员变量的成员函数
//调用初始化函数时一直显示无法访问，后来调试才知道文件名打错了（以后一定要判断是否正确打开is_open）
//如果添加两个及以上职工，排序只能排一次，用while（新增加数量），但如果未增加，出错
//开始用部门编号，但发现文件显示数字，而不是员工、经理、boss，就加了一个成员函数。
// //但第一次没有写出虚函数，子类未重写，然后数据输入文件时错误。
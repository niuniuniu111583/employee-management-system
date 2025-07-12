#pragma once//使头文件只被编译一次,防止头文件重复包含
#include<iostream>////职工三类：普通员工、经理、老板
#include<string>
#include<fstream>
#include "worker.h"
using namespace std;
class WorkerManager {
public:
	WorkerManager();//只声明，不实现
	int numEp;//原空间人数
	Worker** arrEp;//指针的数组，指向每个职工对象的地址
	void init_Ep();////初始化
	
	void show_menu();
	void exitSystem();

	//// 统计文件中人数
	int get_numEpFile();
	//将数据写入文件
	void SaveFile();
	//如果文件已经存在，且有数据//否则会覆盖掉上一次数据（内存释放，执行添加代码时数据早已丢失）
	
	
	//显示职工
	void showEp();
	//判断是否存在此职工
	void IsExist();

	//添加职工
	void addEp();
	//删除职工
	void deleteEp();
	//修改职工信息
	void changeEp();
	//查找职工信息
	void findEp();

	//排序职工信息
	void sortEp();
	//清空
	void clearEp();
	~WorkerManager() {
		if (arrEp != nullptr)
		{
			delete[] arrEp;
			arrEp = nullptr;
		}
	}
};


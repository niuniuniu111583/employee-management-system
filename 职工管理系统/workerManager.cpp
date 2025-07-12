#include "workerManager.h"
#include "worker.h"

WorkerManager::WorkerManager() {
	fstream ifs;
	ifs.open("testEp.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		this->numEp = 0;
		this->arrEp = nullptr;
		/*this->isFileEmpty = true;*/
		ifs.close();
		return ;
	}
	int num=get_numEpFile();//构造函数中可以调用自己的成员函数
	cout << num << endl;
	numEp = num;
	arrEp = new Worker *[num];
	init_Ep();//
	
}

void WorkerManager::show_menu() {
	cout << "*******************************************************" << endl;
	cout << "*****************欢迎您使用职工管理系统****************" << endl;
	cout << "*****************   0：退出管理系统    ****************" << endl;
	cout << "*****************   1：增加职工信息    ****************" << endl;
	cout << "*****************   2：显示职工信息    ****************" << endl;
	cout << "*****************   3：删除离职员工    ****************" << endl;
	cout << "*****************   4：修改职工信息    ****************" << endl;
	cout << "*****************   5：查找职工信息    ****************" << endl;
	cout << "*****************   6：按照编号排序    ****************" << endl;
	cout << "*****************   7：清空所有信息    ****************" << endl;
	cout << "*******************************************************" << endl;
	cout << endl;
}
void WorkerManager::exitSystem() {
	cout << "退出系统!" << endl;
	system("pause");
	exit(0);//退出系统
 }
void WorkerManager::addEp() {
	cout << "输入添加职工数量：" << endl;
	int numEpAdd = 0;
	cin >> numEpAdd;
	if (numEpAdd > 0) {
		int newSize = numEpAdd + numEp;//计算新空间的人数
		Worker** newSpace = new Worker * [newSize];//开辟一个新空间存放指针，指向指针的地址，所以二级指针////////二级指针worker**,因为本来数组类型为work*,加上new，就是worker**
		if (this->arrEp != nullptr) {
			for (int i = 0; i < this->numEp; i++)
			{
				newSpace[i] = arrEp[i];//已经用文件中数据初始化了，所以这里直接将原空间数据放入新空间
			}
		}
		//添加新数据
		for (int i = 0; i < numEpAdd; i++)
		{
			int Id;
			string name;
			int dep_Id;
			cout << "输入第" << i + 1 << "个职工编号：" << endl;
			cin >> Id;
			cout << "输入第" << i + 1 << "个职工名字：" << endl;
			cin >> name;
			cout << "选择该职工岗位：" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.boss" << endl;
			cin >> dep_Id;
			Worker* worker = NULL;//避免野指针
			switch (dep_Id)
			{
			case 1:
				worker = new Employee(Id, name, dep_Id);
				break;
			case 2:
				worker = new Manager(Id, name, dep_Id);
				break;
			case 3:
				worker = new Boss(Id, name, dep_Id);
				break;
			default:
				cout << "输入错误！！！" << endl;
				break;
			}
			newSpace[numEp + i ] = worker;
		}
		delete[] arrEp;//释放原空间
		arrEp = newSpace;//更新原空间
		numEp = newSize;//更新职工人数
		WorkerManager::SaveFile();
		cout << "成功添加：" << numEpAdd << "名职工" << endl;
	}
	else {
		cout << "输入错误，重新输入！" << endl;
	}
	//按任意健清屏
	system("pause");
	system("cls");
} 

void WorkerManager::SaveFile() {
	ofstream of;
	of.open("testEp.txt", ios::out);
	for (int i = 0; i < numEp; i++) {
		of << this->arrEp[i]->Id << "\t" <<
			this->arrEp[i]->name << "\t" <<
			this->arrEp[i]->dep_Id << endl;
	}
	of.close();
}

//统计文件中人数
int WorkerManager::get_numEpFile() {
	ifstream ifs;
	ifs.open("testEp.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		return 1;
	}
	int Id;
	string name;
	int dep_Id;
	int num = 0;//从文件读出的人数
	while (ifs >> Id && ifs >> name && ifs>> dep_Id ) {
		num++;
	}
	ifs.close();
	return num;//本来想直接让numEp等于num，但不能在构造函数中调用任何含未初始化的成员变量的成员函数
}

void WorkerManager::init_Ep() {
	ifstream ifs;
	ifs.open("testEp.txt", ios::in);
	if (!ifs.is_open()) {
		cout << ".." << endl;
	}
	int Id;
	string name;
	int dep_Id;
	int index = 0;
	while (ifs >> Id && ifs >> name && ifs >> dep_Id)
	{//读文件，创建一个抽象类指针，多态，读//将指针指向的数据放入数组时，注意区分不同子类指针
		Worker* worker = nullptr;
		switch (dep_Id)
		{
		case 1:
			worker = new Employee(Id, name, dep_Id);
			break;
		case 2:
			worker = new Manager(Id, name, dep_Id);
			break;
		case 3:
			worker = new Boss(Id, name, dep_Id);
			break;
		default:
			cout << "输入错误！！！" << endl;
			break;
		}
		arrEp[index] = worker;
		index++;
	}
	
	ifs.close();
}

void WorkerManager::showEp() {
	if (numEp==0) {
		cout << "文件为空！" << endl;
	}
	else {
		for (int i = 0; i < numEp; i++) {
			arrEp[i]->showInfo();
		}
	}
	system("pause");
}

void WorkerManager::IsExist() {
	int id;
	cout<<"输入职工编号（观察是否存在）：" << endl;
	cin >> id;
	int index = -1;
	for (int i = 0; i < numEp; i++) {
		if (arrEp[i]->Id == id) {
			index = i;
		}
	}
	if (index == -1) {
		cout << "职工不存在！" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout<< "职工存在！" << endl;	
	}
}
void WorkerManager::deleteEp() {
	IsExist();
	if (numEp==0) {
		cout << "文件为空！" << endl;
		system("pause");
		system("cls");
		return;	
	}
	else {
		int id;
		cout << "输入删除职工编号：" << endl;
		cin >> id;
		for (int i = 0; i < numEp; i++) {
			if (arrEp[i]->Id == id) {
				delete arrEp[i];
				arrEp[i] = nullptr;
				for (int j = i; j < numEp - 1; j++) {
					arrEp[j] = arrEp[j + 1];
				}arrEp[numEp - 1] = nullptr;
				numEp--;
				SaveFile();
				cout << "成功删除职工！" << endl;
				break;
			}
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::changeEp() {
	IsExist();
	if (numEp == 0) {
		cout<< "文件为空！" << endl;	
	}
	else {
		cout << "请输入修改职工编号：" << endl;
		int id;
		cin >> id;
		for (int i = 0; i < numEp; i++) {
			if (arrEp[i]->Id == id) {
				cout<< "输入修改职工编号：" << endl;
				cin >> arrEp[i]->Id;
				cout << "输入修改职工名字：" << endl;
				cin >> arrEp[i]->name;
				cout << "选择该职工岗位：" << endl;
				cout << "1.员工" << endl;
				cout << "2.经理" << endl;
				cout << "3.boss" << endl;
				cin>> arrEp[i]->dep_Id;
				SaveFile();
				cout << "修改成功！" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "职工不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
}

void WorkerManager::findEp() {
	IsExist();
	if (numEp == 0) {
		cout << "文件为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int findId;
		cout<< "输入查找职工编号(得到信息)：" << endl;
		cin >> findId;
		for (int i = 0; i < numEp; i++) {
			if (arrEp[i]->Id == findId) {
				arrEp[i]->showInfo();
				system("pause");
				system("cls");
				return;
			}
		}
	}
}

void WorkerManager::sortEp() {
	if (numEp == 0) {
		cout << "文件为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for (int i = 0; i < numEp - 1; i++) {
			for (int j = i; j < numEp - i - 1; j++) {
				if (arrEp[j]->Id > arrEp[j + 1]->Id) {
					Worker* temp = arrEp[j];
					arrEp[j] = arrEp[j + 1];
					arrEp[j + 1] = temp;
				}
			}
		}
		cout << "排序成功！" << endl;
		SaveFile();
		showEp();
	}
}

void WorkerManager::clearEp() {
	cout << "是否清空所有信息？" << endl;
	cout << "1.清空" << endl;
	cout << "2.返回" << endl;
	int ifClear = 0;
	cin >> ifClear;
	if (ifClear == 1) {
		if (arrEp != nullptr) {
			for (int i = 0; i < numEp; i++) {
				delete arrEp[i];
				arrEp[i] = nullptr;
			}
			numEp = 0;
			delete[] arrEp;
			arrEp = nullptr;
			SaveFile();
			cout << "清空成功！" << endl;
		}
		else {
			cout << "文件为空！" << endl;
		}
	}
	else if (ifClear == 2) {
		cout << "返回成功！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}
}
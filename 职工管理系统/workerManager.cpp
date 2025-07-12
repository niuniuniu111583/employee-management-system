#include "workerManager.h"
#include "worker.h"

WorkerManager::WorkerManager() {
	fstream ifs;
	ifs.open("testEp.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		this->numEp = 0;
		this->arrEp = nullptr;
		/*this->isFileEmpty = true;*/
		ifs.close();
		return ;
	}
	int num=get_numEpFile();//���캯���п��Ե����Լ��ĳ�Ա����
	cout << num << endl;
	numEp = num;
	arrEp = new Worker *[num];
	init_Ep();//
	
}

void WorkerManager::show_menu() {
	cout << "*******************************************************" << endl;
	cout << "*****************��ӭ��ʹ��ְ������ϵͳ****************" << endl;
	cout << "*****************   0���˳�����ϵͳ    ****************" << endl;
	cout << "*****************   1������ְ����Ϣ    ****************" << endl;
	cout << "*****************   2����ʾְ����Ϣ    ****************" << endl;
	cout << "*****************   3��ɾ����ְԱ��    ****************" << endl;
	cout << "*****************   4���޸�ְ����Ϣ    ****************" << endl;
	cout << "*****************   5������ְ����Ϣ    ****************" << endl;
	cout << "*****************   6�����ձ������    ****************" << endl;
	cout << "*****************   7�����������Ϣ    ****************" << endl;
	cout << "*******************************************************" << endl;
	cout << endl;
}
void WorkerManager::exitSystem() {
	cout << "�˳�ϵͳ!" << endl;
	system("pause");
	exit(0);//�˳�ϵͳ
 }
void WorkerManager::addEp() {
	cout << "�������ְ��������" << endl;
	int numEpAdd = 0;
	cin >> numEpAdd;
	if (numEpAdd > 0) {
		int newSize = numEpAdd + numEp;//�����¿ռ������
		Worker** newSpace = new Worker * [newSize];//����һ���¿ռ���ָ�룬ָ��ָ��ĵ�ַ�����Զ���ָ��////////����ָ��worker**,��Ϊ������������Ϊwork*,����new������worker**
		if (this->arrEp != nullptr) {
			for (int i = 0; i < this->numEp; i++)
			{
				newSpace[i] = arrEp[i];//�Ѿ����ļ������ݳ�ʼ���ˣ���������ֱ�ӽ�ԭ�ռ����ݷ����¿ռ�
			}
		}
		//���������
		for (int i = 0; i < numEpAdd; i++)
		{
			int Id;
			string name;
			int dep_Id;
			cout << "�����" << i + 1 << "��ְ����ţ�" << endl;
			cin >> Id;
			cout << "�����" << i + 1 << "��ְ�����֣�" << endl;
			cin >> name;
			cout << "ѡ���ְ����λ��" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.boss" << endl;
			cin >> dep_Id;
			Worker* worker = NULL;//����Ұָ��
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
				cout << "������󣡣���" << endl;
				break;
			}
			newSpace[numEp + i ] = worker;
		}
		delete[] arrEp;//�ͷ�ԭ�ռ�
		arrEp = newSpace;//����ԭ�ռ�
		numEp = newSize;//����ְ������
		WorkerManager::SaveFile();
		cout << "�ɹ���ӣ�" << numEpAdd << "��ְ��" << endl;
	}
	else {
		cout << "��������������룡" << endl;
	}
	//�����⽡����
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

//ͳ���ļ�������
int WorkerManager::get_numEpFile() {
	ifstream ifs;
	ifs.open("testEp.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		return 1;
	}
	int Id;
	string name;
	int dep_Id;
	int num = 0;//���ļ�����������
	while (ifs >> Id && ifs >> name && ifs>> dep_Id ) {
		num++;
	}
	ifs.close();
	return num;//������ֱ����numEp����num���������ڹ��캯���е����κκ�δ��ʼ���ĳ�Ա�����ĳ�Ա����
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
	{//���ļ�������һ��������ָ�룬��̬����//��ָ��ָ������ݷ�������ʱ��ע�����ֲ�ͬ����ָ��
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
			cout << "������󣡣���" << endl;
			break;
		}
		arrEp[index] = worker;
		index++;
	}
	
	ifs.close();
}

void WorkerManager::showEp() {
	if (numEp==0) {
		cout << "�ļ�Ϊ�գ�" << endl;
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
	cout<<"����ְ����ţ��۲��Ƿ���ڣ���" << endl;
	cin >> id;
	int index = -1;
	for (int i = 0; i < numEp; i++) {
		if (arrEp[i]->Id == id) {
			index = i;
		}
	}
	if (index == -1) {
		cout << "ְ�������ڣ�" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout<< "ְ�����ڣ�" << endl;	
	}
}
void WorkerManager::deleteEp() {
	IsExist();
	if (numEp==0) {
		cout << "�ļ�Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;	
	}
	else {
		int id;
		cout << "����ɾ��ְ����ţ�" << endl;
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
				cout << "�ɹ�ɾ��ְ����" << endl;
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
		cout<< "�ļ�Ϊ�գ�" << endl;	
	}
	else {
		cout << "�������޸�ְ����ţ�" << endl;
		int id;
		cin >> id;
		for (int i = 0; i < numEp; i++) {
			if (arrEp[i]->Id == id) {
				cout<< "�����޸�ְ����ţ�" << endl;
				cin >> arrEp[i]->Id;
				cout << "�����޸�ְ�����֣�" << endl;
				cin >> arrEp[i]->name;
				cout << "ѡ���ְ����λ��" << endl;
				cout << "1.Ա��" << endl;
				cout << "2.����" << endl;
				cout << "3.boss" << endl;
				cin>> arrEp[i]->dep_Id;
				SaveFile();
				cout << "�޸ĳɹ���" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "ְ�������ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
}

void WorkerManager::findEp() {
	IsExist();
	if (numEp == 0) {
		cout << "�ļ�Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int findId;
		cout<< "�������ְ�����(�õ���Ϣ)��" << endl;
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
		cout << "�ļ�Ϊ�գ�" << endl;
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
		cout << "����ɹ���" << endl;
		SaveFile();
		showEp();
	}
}

void WorkerManager::clearEp() {
	cout << "�Ƿ����������Ϣ��" << endl;
	cout << "1.���" << endl;
	cout << "2.����" << endl;
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
			cout << "��ճɹ���" << endl;
		}
		else {
			cout << "�ļ�Ϊ�գ�" << endl;
		}
	}
	else if (ifClear == 2) {
		cout << "���سɹ���" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}
}
#pragma once//ʹͷ�ļ�ֻ������һ��,��ֹͷ�ļ��ظ�����
#include<iostream>////ְ�����ࣺ��ͨԱ���������ϰ�
#include<string>
#include<fstream>
#include "worker.h"
using namespace std;
class WorkerManager {
public:
	WorkerManager();//ֻ��������ʵ��
	int numEp;//ԭ�ռ�����
	Worker** arrEp;//ָ������飬ָ��ÿ��ְ������ĵ�ַ
	void init_Ep();////��ʼ��
	
	void show_menu();
	void exitSystem();

	//// ͳ���ļ�������
	int get_numEpFile();
	//������д���ļ�
	void SaveFile();
	//����ļ��Ѿ����ڣ���������//����Ḳ�ǵ���һ�����ݣ��ڴ��ͷţ�ִ����Ӵ���ʱ�������Ѷ�ʧ��
	
	
	//��ʾְ��
	void showEp();
	//�ж��Ƿ���ڴ�ְ��
	void IsExist();

	//���ְ��
	void addEp();
	//ɾ��ְ��
	void deleteEp();
	//�޸�ְ����Ϣ
	void changeEp();
	//����ְ����Ϣ
	void findEp();

	//����ְ����Ϣ
	void sortEp();
	//���
	void clearEp();
	~WorkerManager() {
		if (arrEp != nullptr)
		{
			delete[] arrEp;
			arrEp = nullptr;
		}
	}
};


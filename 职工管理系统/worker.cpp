#include "worker.h"

Employee::Employee(int id, string na, int dep_id){
	this->Id = id;
	this->name = na;
	this->dep_Id = dep_id;
}
void Employee:: showInfo(){
	cout << "ְ����ţ�" << this->Id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << "Ա��" << "\tְ��:��ɾ�����������" << endl;
}
string Employee::dep_name() {
	return "Ա��";
}

Manager::Manager(int id, string na, int dep_id) {
	this->Id = id;
	this->name = na;
	this->dep_Id = dep_id;
}
void Manager::showInfo() {
	cout << "ְ����ţ�" << this->Id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << "����" << "\tְ��:����ϰ彻��������,������Ա����" << endl;
}
string Manager::dep_name() {
	return "����";
}

Boss::Boss(int id, string na, int dep_id) {
	this->Id = id;
	this->name = na;
	this->dep_Id = dep_id;
}
void Boss::showInfo() {
	cout << "ְ����ţ�" << this->Id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << "boss" << "\tְ��:����˾" << endl;
}
string Boss::dep_name() {
	return "�ϰ�";
}
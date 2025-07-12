#include "worker.h"

Employee::Employee(int id, string na, int dep_id){
	this->Id = id;
	this->name = na;
	this->dep_Id = dep_id;
}
void Employee:: showInfo(){
	cout << "职工编号：" << this->Id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << "员工" << "\t职务:完成经理交代的任务" << endl;
}
string Employee::dep_name() {
	return "员工";
}

Manager::Manager(int id, string na, int dep_id) {
	this->Id = id;
	this->name = na;
	this->dep_Id = dep_id;
}
void Manager::showInfo() {
	cout << "职工编号：" << this->Id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << "经理" << "\t职务:完成老板交代的任务,并管理员工。" << endl;
}
string Manager::dep_name() {
	return "经理";
}

Boss::Boss(int id, string na, int dep_id) {
	this->Id = id;
	this->name = na;
	this->dep_Id = dep_id;
}
void Boss::showInfo() {
	cout << "职工编号：" << this->Id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << "boss" << "\t职务:管理公司" << endl;
}
string Boss::dep_name() {
	return "老板";
}
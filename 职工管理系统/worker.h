#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker {	//≥ÈœÛ¿‡
public:
	int Id;
	string name;
	int dep_Id;
	virtual void showInfo()=0;
	virtual string dep_name()=0;
	virtual ~Worker(){}
};
class Employee :public Worker {
public:
	Employee(int id, string na, int dep_id);
	virtual void showInfo();
	virtual string dep_name();

};
class Manager :public Worker {
public:
	Manager(int id, string na, int dep_id);
	virtual void showInfo();
	virtual string dep_name();
};
class Boss :public Worker {
public:
	Boss(int id, string na, int dep_id);
	virtual void showInfo();
	virtual string dep_name();
};


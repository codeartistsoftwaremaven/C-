#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Work.h"

class Manager :public Worker {
public:
	Manager(int id, string name, int dId);
	//��ʾ������Ϣ                                                                                                                                                                                                                                                   
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};

#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Work.h"

class Boss :public Worker {
public:
	Boss(int id, string name, int dId);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};
#pragma once

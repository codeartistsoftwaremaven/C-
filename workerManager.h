#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include"Work.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager {
public:
	WorkerManager();
	~WorkerManager();
	void Show_Menu();
	void ExitSystem();
	int m_EmpNum;
	Worker** m_EmpArray;
	void Add_Emp();
	void save();
	bool m_FileIsEmpty;
	int get_EmpNum();
	void init_Emp();
	void Show_Emp();
	void Del_Emp();
	int IsExist(int id);
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();
	void Clean_File();
};
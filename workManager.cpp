#include"workerManager.h"


WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		return;
	}
	//文件存在且为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		return;
	}
	//文件存在且记录数据
	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	cout << "职工人数为: " << num << endl;
	//开辟空间
	this->m_EmpArray = new Worker * [num];
	this->init_Emp();
	//for (int i = 0; i < this->m_EmpNum; i++) {
	//	cout << "职工编号" << this->m_EmpArray[i]->m_Id ;
	//	cout << " 职工姓名" << this->m_EmpArray[i]->m_Name ;
	//	cout << " 部门编号" << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i] != NULL) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::Show_Menu() {
	cout << "**********************************************" << endl;
	cout << "**********   欢迎使用职工管理系统   **********" << endl;
	cout << "**************   0.退出管理系统   ************" << endl;
	cout << "**************   1.增加职工信息   ************" << endl;
	cout << "**************   2.显示职工信息   ************" << endl;
	cout << "**************   3.删除离职信息   ************" << endl;
	cout << "**************   4.修改职工信息   ************" << endl;
	cout << "**************   5.查找职工信息   ************" << endl;
	cout << "**************   6.按照编号排序   ************" << endl;
	cout << "**************   7.清空所有文档   ************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);						//退出
}


void WorkerManager::Add_Emp() {
	cout << "请输入添加的员工数量：" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0) {
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		for (int i = 0; i < this->m_EmpNum; i++) {
			newSpace[i] = this->m_EmpArray[i];
		}

		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;
		}
		delete this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "成功添加" << addNum << "名新职工" << endl;
		this->save();
	}
	else {
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	return num;
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else {
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::Show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或为空！" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		int id;
		cout << "请输入要删除的职工的编号" << endl;
		cin >> id;
		int index = IsExist(id);
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum-1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		int id;
		cout << "请输入修改职工的编号" << endl;;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			delete this->m_EmpArray[index];
			this->m_EmpArray[index] = NULL;
			int newid=0;
			string newname=" ";
			int dSelect=0;
			cout << "查到：" << id << "号职工，请输入新职工号" << endl;
			cin >> newid;
			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请输入岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect) {
				case 1:
					worker = new Employee(newid, newname, 1);
					break;
				case 2:
					worker = new Manager(newid, newname, 2);
					break;
				case 3:
					worker = new Boss(newid, newname, 3);
					break;
				default:
					break;
			}
			this->m_EmpArray[index] = worker;
			cout << "修改成功" << endl;
			this->save();
			}
		else {
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入查找的方式：" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id = 0;
			cout << "请输入查找的职工编号" << endl;
			cin >> id;
			int ret=this->IsExist(id);
			if (ret != -1) {
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败,查无此人" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "请输入查找的职工姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "查找成功！该职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "查找失败,查无此人" << endl;
			}
		}
		else {
			cout << "输入选项有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式" << endl;
		cout << "1.按职工号进行升序" << endl;
		cout << "2.按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++) {
			int MinOrMax = i;
			for (int j = i+1; j < this->m_EmpNum; j++) {
				if (select == 1) {
					if ((this->m_EmpArray[j]->m_Id < this->m_EmpArray[i]->m_Id)) {
						MinOrMax = j;
					}
				}
				else {
					if ((this->m_EmpArray[j]->m_Id > this->m_EmpArray[i]->m_Id)) {
						MinOrMax = j;
					}
				}
			}
			if (i != MinOrMax) {
				Worker* temp = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = this->m_EmpArray[i];
				this->m_EmpArray[i] = temp;
			}
		}
	}
	cout << "排序成功！排序后的结果为：" << endl;
	this->save();
	this->Show_Emp();
}

void WorkerManager::Clean_File() {
	cout << "确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1){
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

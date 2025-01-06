#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks {
	struct Person perosnArray[MAX];
	int m_Size;
};

void ShowMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}

void AddPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->perosnArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->perosnArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->perosnArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		abs->perosnArray[abs->m_Size].m_Phone = phone;
		//地址
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->perosnArray[abs->m_Size].m_Addr = address;
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void ShowPerson(Addressbooks* abs) {
	if (abs->m_Size == 0)
		cout << "当前记录为空" << endl;
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->perosnArray[i].m_Name << "\t";
			cout << "性别：" << (abs->perosnArray[i].m_Sex == 1?"男":"女") << "\t";
			cout << "年龄：" << abs->perosnArray[i].m_Age << "\t";
			cout << "电话：" << abs->perosnArray[i].m_Phone << "\t";
			cout << "地址：" << abs->perosnArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int IsExist(Addressbooks* abs,string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->perosnArray[i].m_Name == name)
			return i;
	}
	return -1;
}

void DeletePerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "通讯录目前没有人，无法删除" << endl;
	}
	else {
		cout << "请输入删除联系人姓名" << endl;
		string name;
		cin >> name;
		int ret = IsExist(abs, name);
		if (ret != -1) {
			for (int i = ret; i < abs->m_Size; i++) {
				abs->perosnArray[i] = abs->perosnArray[i + 1];
			}
			abs->m_Size--;
			cout << "删除成功" << endl;
		}
		else
			cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void FindPerson(Addressbooks* abs) {
	cout << "请输入您要查找的人" << endl;
	string name;
	cin >> name;
	int ret=IsExist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->perosnArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->perosnArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->perosnArray[ret].m_Age << "\t";
		cout << "电话：" << abs->perosnArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->perosnArray[ret].m_Addr << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");
	system("cls");
}

void ModifyPerson(Addressbooks* abs) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
	if (ret != -1) {
		//姓名
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->perosnArray[ret].m_Name = name;
		//性别
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->perosnArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->perosnArray[ret].m_Age = age;
		//电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		abs->perosnArray[ret].m_Phone = phone;
		//地址
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->perosnArray[ret].m_Addr = address;
		cout << "修改成功" << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");
	system("cls");
}

void CleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已空" << endl;
	system("pause");
	system("cls");
}

int main() {
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		ShowMenu();				//菜单
		cin >> select;
		switch (select) {
		case 1:                 //1.添加联系人
			AddPerson(&abs);
			break;
		case 2:					//2.删除联系人
			ShowPerson(&abs);
			break;
		case 3: {					//3.删除联系人
			DeletePerson(&abs);
			break;
		}
		case 4:					//4.查找联系人
			FindPerson(&abs);
			break;
		case 5:					//5.修改联系人
			ModifyPerson(&abs);
			break;
		case 6:					//6.清空联系人
			CleanPerson(&abs);
			break;
		case 0:					//0.退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	system( "pause" );
	return 0;
}
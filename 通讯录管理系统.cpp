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
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}

void AddPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->perosnArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->perosnArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->perosnArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->perosnArray[abs->m_Size].m_Phone = phone;
		//��ַ
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->perosnArray[abs->m_Size].m_Addr = address;
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

void ShowPerson(Addressbooks* abs) {
	if (abs->m_Size == 0)
		cout << "��ǰ��¼Ϊ��" << endl;
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->perosnArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->perosnArray[i].m_Sex == 1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->perosnArray[i].m_Age << "\t";
			cout << "�绰��" << abs->perosnArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->perosnArray[i].m_Addr << endl;
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
		cout << "ͨѶ¼Ŀǰû���ˣ��޷�ɾ��" << endl;
	}
	else {
		cout << "������ɾ����ϵ������" << endl;
		string name;
		cin >> name;
		int ret = IsExist(abs, name);
		if (ret != -1) {
			for (int i = ret; i < abs->m_Size; i++) {
				abs->perosnArray[i] = abs->perosnArray[i + 1];
			}
			abs->m_Size--;
			cout << "ɾ���ɹ�" << endl;
		}
		else
			cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void FindPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���" << endl;
	string name;
	cin >> name;
	int ret=IsExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->perosnArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->perosnArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->perosnArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->perosnArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->perosnArray[ret].m_Addr << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}

void ModifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
	if (ret != -1) {
		//����
		cout << "����������" << endl;
		cin >> name;
		abs->perosnArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->perosnArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->perosnArray[ret].m_Age = age;
		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->perosnArray[ret].m_Phone = phone;
		//��ַ
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->perosnArray[ret].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}

void CleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�ѿ�" << endl;
	system("pause");
	system("cls");
}

int main() {
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		ShowMenu();				//�˵�
		cin >> select;
		switch (select) {
		case 1:                 //1.�����ϵ��
			AddPerson(&abs);
			break;
		case 2:					//2.ɾ����ϵ��
			ShowPerson(&abs);
			break;
		case 3: {					//3.ɾ����ϵ��
			DeletePerson(&abs);
			break;
		}
		case 4:					//4.������ϵ��
			FindPerson(&abs);
			break;
		case 5:					//5.�޸���ϵ��
			ModifyPerson(&abs);
			break;
		case 6:					//6.�����ϵ��
			CleanPerson(&abs);
			break;
		case 0:					//0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	system( "pause" );
	return 0;
}
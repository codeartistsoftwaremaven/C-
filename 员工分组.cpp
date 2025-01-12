#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>
using namespace std;
#define thinker 0
#define artist  1
#define developer 2

class Worker {
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];
		worker.m_Salary = rand() % 10001 + 10000;
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		int deptId = rand() % 3;
		m.insert(pair<int, Worker>(deptId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m) {
	cout << "策划部门" << endl;
	multimap<int, Worker>::iterator pos = m.find(thinker);
	int count = m.count(thinker);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << " 员工姓名：" << pos->second.m_Name << " 员工工资：" << pos->second.m_Salary << endl;
	}
	cout << "-----------------------" << endl;
	cout << "美术部门" << endl;
	pos = m.find(artist);
	count = m.count(artist);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << " 员工姓名：" << pos->second.m_Name << " 员工工资：" << pos->second.m_Salary << endl;
	}
	cout << "-----------------------" << endl;
	cout << "研发部门" << endl;
	pos = m.find(developer);
	count = m.count(developer);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << " 员工姓名：" << pos->second.m_Name << " 员工工资：" << pos->second.m_Salary << endl;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	vector<Worker>vWorker;
	createWorker(vWorker);
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	showWorkerByGroup(mWorker);
	system("pause");
	return 0;
}
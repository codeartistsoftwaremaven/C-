#include"workerManager.h"
#include"Work.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"

int main() {
	WorkerManager wm;
	int choice = 0;   
	while (true) {
		wm.Show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //增加职工
			wm.Add_Emp();
			break;
		case 2: //显示职工
			wm.Show_Emp();
			break;
		case 3: //删除职工
			wm.Del_Emp();
			break;
		case 4: //修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.Find_Emp();
			break;
		case 6: //排序职工
			wm.Sort_Emp();
			break;
		case 7: //清空文档
			wm.Clean_File();
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}
	system("pause");
	return 0;
}
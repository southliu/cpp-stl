#include <iostream>;
using namespace std;
#include <vector>
#include <ctime>

class Worker {
public:
	string m_name;
	int m_age;
};

// 创建成员
void createWorker(vector<Worker>&v) {
	string personName = "ABCDEFGHJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_name = "员工";
		worker.m_name += personName[i];
		worker.m_age = rand() % 10000 + 10000;

		v.push_back(worker);
	}
}

void main() {
	// 随机种子
	srand((unsigned int)time(NULL));

	vector<Worker> vWorker;
	createWorker(vWorker);

	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << "姓名：" << it->m_name << " 年龄：" << (*it).m_age << endl;
	}
}
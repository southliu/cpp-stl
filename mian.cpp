#include <iostream>;
using namespace std;
#include <vector>
#include <map>
#include <ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker {
public:
	string m_name;
	int m_money;
};

// 创建成员
void createWorker(vector<Worker>&v) {
	string personName = "ABCDEFGHJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_name = "员工";
		worker.m_name += personName[i];
		worker.m_money = rand() % 10000 + 10000;

		v.push_back(worker);
	}
}

// 设置员工分组
void setGroup(vector<Worker>&v, multimap<int, Worker>&m) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		int id = rand() % 3;
		m.insert(make_pair(id, *it));
	}
}

// 显示员工
void showWoker(multimap<int, Worker>&m) {
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;

	cout << "策划部门："  << endl;
	for ( ; pos != m.end() && index < count; pos++, index++) {
		cout << "姓名：" << pos->second.m_name << " 工资：" << pos->second.m_money << endl;
	}

	cout << "-----------------" << endl;
	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << "姓名：" << pos->second.m_name << " 工资：" << pos->second.m_money << endl;
	}

	cout << "-----------------" << endl;
	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << "姓名：" << pos->second.m_name << " 工资：" << pos->second.m_money << endl;
	}
}

void main() {
	// 随机种子
	srand((unsigned int)time(NULL));

	vector<Worker> vWorker;
	createWorker(vWorker);

	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);

	showWoker(mWorker);
}
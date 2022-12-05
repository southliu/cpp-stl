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

// ������Ա
void createWorker(vector<Worker>&v) {
	string personName = "ABCDEFGHJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_name = "Ա��";
		worker.m_name += personName[i];
		worker.m_money = rand() % 10000 + 10000;

		v.push_back(worker);
	}
}

// ����Ա������
void setGroup(vector<Worker>&v, multimap<int, Worker>&m) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		int id = rand() % 3;
		m.insert(make_pair(id, *it));
	}
}

// ��ʾԱ��
void showWoker(multimap<int, Worker>&m) {
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;

	cout << "�߻����ţ�"  << endl;
	for ( ; pos != m.end() && index < count; pos++, index++) {
		cout << "������" << pos->second.m_name << " ���ʣ�" << pos->second.m_money << endl;
	}

	cout << "-----------------" << endl;
	cout << "�������ţ�" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << "������" << pos->second.m_name << " ���ʣ�" << pos->second.m_money << endl;
	}

	cout << "-----------------" << endl;
	cout << "�з����ţ�" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << "������" << pos->second.m_name << " ���ʣ�" << pos->second.m_money << endl;
	}
}

void main() {
	// �������
	srand((unsigned int)time(NULL));

	vector<Worker> vWorker;
	createWorker(vWorker);

	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);

	showWoker(mWorker);
}
#include <iostream>;
using namespace std;
#include <vector>
#include <ctime>

class Worker {
public:
	string m_name;
	int m_age;
};

// ������Ա
void createWorker(vector<Worker>&v) {
	string personName = "ABCDEFGHJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_name = "Ա��";
		worker.m_name += personName[i];
		worker.m_age = rand() % 10000 + 10000;

		v.push_back(worker);
	}
}

void main() {
	// �������
	srand((unsigned int)time(NULL));

	vector<Worker> vWorker;
	createWorker(vWorker);

	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << "������" << it->m_name << " ���䣺" << (*it).m_age << endl;
	}
}
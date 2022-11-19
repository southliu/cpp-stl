#include <iostream>;
using namespace std;
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

// ��Ա��
class Person {
public:
	Person(string name, int score) {
		this->m_name = name;
		this->m_score = score;
	}

	string m_name;
	int m_score;
};

// ������Ա
void createPersion(vector<Person>&v) {
	string personName = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "��Ա";
		name += personName[i];

		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

// ���ó�Ա�ɼ�
void setPersonScore(vector<Person>&v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		// ����ί��������deque������
		deque<int> d;

		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 40 + 60;
			d.push_back(score);
		}

		// �����ݽ�������
		sort(d.begin(), d.end());

		// ɾ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		// ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();

		it->m_score = avg;
	}
}

// ��ӡ��Ա����
void showPerson(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).m_name << ": " << (*it).m_score << endl;
	}
}

void main() {
	// �������
	srand((unsigned int)time(NULL));

	vector<Person> v;

	// ������Ա
	createPersion(v);

	// ��Ա���
	setPersonScore(v);

	// ��ӡ��Ա
	showPerson(v);
}
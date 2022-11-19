#include <iostream>;
using namespace std;
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

// 成员类
class Person {
public:
	Person(string name, int score) {
		this->m_name = name;
		this->m_score = score;
	}

	string m_name;
	int m_score;
};

// 创建成员
void createPersion(vector<Person>&v) {
	string personName = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "成员";
		name += personName[i];

		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

// 设置成员成绩
void setPersonScore(vector<Person>&v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		// 将评委分数放入deque容器中
		deque<int> d;

		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 40 + 60;
			d.push_back(score);
		}

		// 对数据进行排序
		sort(d.begin(), d.end());

		// 删除最高分和最低分
		d.pop_back();
		d.pop_front();

		// 取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();

		it->m_score = avg;
	}
}

// 打印成员数据
void showPerson(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).m_name << ": " << (*it).m_score << endl;
	}
}

void main() {
	// 随机种子
	srand((unsigned int)time(NULL));

	vector<Person> v;

	// 创建成员
	createPersion(v);

	// 成员打分
	setPersonScore(v);

	// 打印成员
	showPerson(v);
}
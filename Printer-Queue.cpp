#include <iostream>
#include <list>
#include <utility>
using namespace std;


int main() {
	int count;
	cin >> count;
	while (count --) {
		int jc, position;
		cin >> jc >> position;
		list<pair<int, int> > job;
		for (int i = 0; i < jc; ++i)
		{
			int priority;
			cin >> priority;
			job.push_back(pair<int, int>(i, priority));
		}
		int cc = 1;
		while (!job.empty()) {
			pair<int, int> jobToDo = job.front();
			job.pop_front();
			bool flag = false;
			for (list<pair<int, int> >::iterator it = job.begin(); it != job.end(); ++it) {
				if (jobToDo.second < it->second) {
					flag = true;
					job.push_back(jobToDo);
					break;
				}
			}
			if (flag)
				continue;
			else if (jobToDo.first == position) {
				cout << cc << endl;
				break;
			}
			cc++;
		}
	}
	return 0;
}

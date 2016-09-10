#include <iostream>
#include <map>
using namespace std;
int main() {
	int count;
	cin >> count;
	while (count --) {
		map<int, int> result;
		int c1, c2;
		cin >> c1;
		while (c1--) {
			int tp, tn;
			cin >> tp >> tn;
			map<int, int>::iterator it = result.find(tn);
			if (it == result.end()) {
				result.insert(pair<int, int>(tn, tp));
			} else {
				it->second += tp;
			}
		}
		cin >> c2;
		while (c2--) {
			int tp, tn;
			cin >> tp >> tn;
			map<int, int>::iterator it = result.find(tn);
			if (it == result.end()) {
				result.insert(pair<int, int>(tn, tp));
			} else {
				it->second += tp;
			}
		}
		for (map<int, int>::iterator it = result.begin(); it != result.end();++it) {
			if (it->second == 0) {
				result.erase(it);
			}
		}
		cout << result.size() << endl;
		for (map<int, int>::reverse_iterator it = result.rbegin(); it != result.rend();++it) {
			cout << it->second << " " << it->first << endl;
		}
	}
	return 0;
}

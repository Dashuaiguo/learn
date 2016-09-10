#include <iostream>
#include <list>
using namespace std;
#define MAX 10000


int main() {
	int count;
	cin >> count;
	while (count--) {
		int c1, c2;
		int a[MAX] = {};
		list<int> nl;
		cin >> c1;
		for (int i = 0; i < c1; ++i)
		{
			int p, n;
			cin >> p >> n;
			nl.push_back(n);
			a[n] += p;
		}
		cin >> c2;
		for (int i = 0; i < c2; ++i)
		{
			int p, n;
			cin >> p >> n;
			nl.push_back(n);
			a[n] += p;
		}
		nl.sort();
		nl.unique();
		auto If0 = [&] (int x) {
			if (a[x] == 0)
				return true;
			else
				return false;
		};
		nl.remove_if(If0);
		cout << nl.size() << endl;
		for (auto it = nl.rbegin(); it != nl.rend(); ++it) {
			cout << a[*it] << " " << *it << endl;
		}
	}
	return 0;
}

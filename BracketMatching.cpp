#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int count;
	cin >> count;
	while (count--) {
		string s;
		cin >> s;
		stack<char> f;
		bool flag = true;
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				f.push(s[i]);
			}
			if (s[i] == ')') {
				if (f.empty() || f.top() != '(') {
					flag = false;
					break;
				} else {
					f.pop();
				}
			}
			if (s[i] == ']') {
				if (f.empty() || f.top() != '[') {
					flag = false;
					break;
				} else {
					f.pop();
				}
			}
			if (s[i] == '}') {
				if (f.empty() || f.top() != '{') {
					flag = false;
					break;
				} else {
					f.pop();
				}
			}
		}
		if (flag && f.empty())
			cout <<	"Yes" << endl;
		else
			cout << "No" << endl;
	}
}

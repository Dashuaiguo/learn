#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string middle;
	cin >> middle;
	stack<char> s;
	for (int i = 0; i < middle.size(); ++i)
	{
		if ((middle[i] <= 'Z' && middle[i] >= 'A') || (middle[i] <= 'z' && middle[i] >= 'a')) {
			cout << middle[i];
		} else {
			if (s.empty() || s.top() == '(')
				s.push(middle[i]);
			else if (middle[i] == '(') {
				s.push(middle[i]);
			} else if (middle[i] == ')') {
				while (s.top() != '('){
					cout << s.top();
					s.pop();
				}
				s.pop();
			} else if (middle[i] == '*' || middle[i] == '/' || middle[i] == '%') {
				s.push(middle[i]);
			} else if (s.top() == '*' || s.top() == '/' || middle[i] == '%') {
				cout << s.top();
				s.pop();
				if (middle[i] == '*' || middle[i] == '/' || middle[i] == '%' || s.empty())
					s.push(middle[i]);
				else {
					while(!s.empty() && s.top() != '(') {
						cout << s.top();
						s.pop();
					}
					s.push(middle[i]);
				}
			} else {
				while(!s.empty() && s.top() != '(') {
						cout << s.top();
						s.pop();
					}
					s.push(middle[i]);
			}
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}

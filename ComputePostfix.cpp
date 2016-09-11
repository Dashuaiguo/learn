#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
using namespace std;

double getNumber(char c) {
	return (double)(c-'a'+1);
}

double calculate(double front, double back, char sign) {
	switch (sign) {
		case '+': return front + back;
			break;
		case '-': return front - back;
			break;
		case '*': return front * back;
			break;
		case '/': return front / back;
			break;
		default : return 0;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		stack<double> tstack;
		cin >> s;
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (s[i] >= 'a' && s[i] <= 'z') {
				tstack.push(getNumber(s[i]));
			} else {
				double front, back;
				back = tstack.top();
				tstack.pop();
				front = tstack.top();
				tstack.pop();
				tstack.push(calculate(front, back, s[i]));
			}
		}
		cout << setiosflags(ios::fixed) <<setprecision(2);
		cout << tstack.top() << endl;
		tstack.pop();
	}
	return 0;
}

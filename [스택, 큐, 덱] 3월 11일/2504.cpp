#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

bool isBalanced(string& s) {
	stack<char> st;
	map<char, char> m;
	//괄호 짝 미리 저장
	m[']'] = '[';
	m[')'] = '(';

	for (int i = 0; i < s.length(); i++) {
		switch (s[i])
		{
		case'(': case'[': //여는 괄호
			st.push(s[i]);
			break;
		case')': case']':
			if (st.empty() || st.top() != m[s[i]]) { //스택 비었거나, 종류 안맞음
				return false;
			}
			st.pop();
			break;
		}
	}
	return st.empty(); //스택에 원소가 비어있어야 균형 0
}

void Calculation(string& s) {
	stack<char> st;
	int res = 0, cal = 1;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') { 
			st.push(s[i]);
			cal *= 2;
		}  			
		else if (s[i] == '[') {
			st.push(s[i]);
			cal *= 3;
		}			
		else if (s[i] == ')') {
			if (s[i - 1] == '(') {
				res += cal;
			}
			cal /= 2;
			st.pop();
		}	
		else if (s[i] == ']') {
			if (s[i - 1] == '[') {
				res += cal;
			}
			cal /= 3;
			st.pop();
		}
	}
	cout << res << '\n';
}

int main() {
	string str;
	cin >> str;
	if (!isBalanced(str)) {
		cout << "0\n";
	}
	else {
		Calculation(str);
	}	
	return 0;
}
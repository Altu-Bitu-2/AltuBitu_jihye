#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

bool isBalanced(string& s) {
	stack<char> st;
	map<char, char> m;
	//��ȣ ¦ �̸� ����
	m[']'] = '[';
	m[')'] = '(';

	for (int i = 0; i < s.length(); i++) {
		switch (s[i])
		{
		case'(': case'[': //���� ��ȣ
			st.push(s[i]);
			break;
		case')': case']':
			if (st.empty() || st.top() != m[s[i]]) { //���� ����ų�, ���� �ȸ���
				return false;
			}
			st.pop();
			break;
		}
	}
	return st.empty(); //���ÿ� ���Ұ� ����־�� ���� 0
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
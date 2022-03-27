#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isGroup(string s) {
	vector<bool> ch(26, 0);
	if (s.size() == 1) return true;
	for (int i = 0; i < s.size(); i++) {
		if (ch[s[i] - 97]) {
			return false;
		}
		if (s[i] == s[i+1]) {
			continue;
		}
		else {
			ch[s[i] - 97] = true;
		}
	}
	return true;
}

int main() {
	int n, cnt=0;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		if (isGroup(str)) cnt++;
	}
	cout << cnt;
	return 0;
}
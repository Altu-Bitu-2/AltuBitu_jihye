#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	int idx;
	string S = "";
	string str = "";
	set<string> set;
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		for (int j = i; j < S.length(); j++) {
			str += S[j];
			set.insert(str);
		}
		str = "";
	}
	cout << set.size() << '\n';
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int val = -1;
	long long num;
	string str;
	cin >> str;
	sort(str.begin(), str.end(), cmp); //내림차순 정렬
	do{
		num = stoll(str);
		if (num % 30 == 0) {
			cout << str << '\n';
			val = 1;
			break;
		}
	} while (prev_permutation(str.begin(), str.end()));	
	if (val == -1) {
		cout << -1 << '\n';
	}
	return 0;
}
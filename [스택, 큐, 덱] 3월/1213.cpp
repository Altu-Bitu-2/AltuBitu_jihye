#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> alpa(26, 0);
	string str, palin;
	char mid = ' ';
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		alpa[str[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {	//�켱 �Ӹ������ ���� �� �ִ� �� �˻�
		if (alpa[i] % 2 != 0) {
			mid = i + 'A';
			for (int j = (i + 1); j < 26; j++) {
				if (alpa[j] % 2 != 0) {
					cout << "I'm Sorry Hansoo\n";
					return 0;
				}
			}
		}
		alpa[i] /= 2;
	}	
	for (int i = 0; i < 26; i++) {
		while (alpa[i]--) {
			palin += (i + 'A');
		}		
	}
	cout << palin;
	if (mid != ' ') {
		cout << mid;
	}
	reverse(palin.begin(), palin.end());
	cout << palin << '\n';
	return 0;
}
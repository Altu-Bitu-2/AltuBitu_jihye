#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	bool flag = false;
	string str;
	cin >> str;
	sort(str.begin(), str.end(), greater<>()); // �������� ����

	int sum = 0;
	for (int i = 0; i < str.size(); i++) { // �� �ڸ��� ��
		if (str[i] == '0') flag = true;
		sum += (str[i] - '0');
	}
	if (sum % 3 != 0 || !flag) { // �� �ڸ��� ���� 3���� �ȳ������ų� 0�� �ϳ��� ���ٸ� -1 ��ȯ
		cout << -1 << '\n';
	}

	else {
		do {
			if(str[str.size() - 1] == '0') {
				cout << str << '\n';
				break;
			}
		} while (prev_permutation(str.begin(), str.end()));
	}

	return 0;
}
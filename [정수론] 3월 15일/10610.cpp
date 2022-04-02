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
	sort(str.begin(), str.end(), greater<>()); // 내림차순 정렬

	int sum = 0;
	for (int i = 0; i < str.size(); i++) { // 각 자리수 합
		if (str[i] == '0') flag = true;
		sum += (str[i] - '0');
	}
	if (sum % 3 != 0 || !flag) { // 각 자리수 합이 3으로 안나눠지거나 0이 하나도 없다면 -1 반환
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
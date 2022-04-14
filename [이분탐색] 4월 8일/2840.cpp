#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k, s;
	char ch;

	// 입력
	cin >> n >> k;
	vector<char> arr(n, '?');

	int idx = 0;
	bool flag = true;

	for (int i = 0; i < k; i++) {
		cin >> s >> ch;
		idx = (idx + s) % n;
		if (arr[idx] != '?') { // 문자가 들어있고
			if (arr[idx] == ch) { // 같은 문자라면 문제없음 반복 계속
				continue;
			}
			flag = false;	// 다른 문자라면 그런 바퀴는 없으므로 flag false로
		}
		else {
			arr[idx] = ch;
		}
	}

	for (int i = 0; i < n; i++) {	// 중복 체크
		if (arr[i] == '?') continue;
		for (int j = i + 1; j < n; j++) {	// i번째 있는 글자와
			if (arr[i] == arr[j]) {	// 그 뒤로 같은 게 있으면
				flag = false;		// flag false
				break;
			}
		}
	}

	if (flag) { // flag true 라면 출력
		for (int i = 0; i < n; i++) {
			cout << arr[idx];
			idx--;
			if (idx < 0) idx += n;
		}
	}
	else {	// 아니라면 ! 출력
		cout << '!';
	}
	return 0;
}
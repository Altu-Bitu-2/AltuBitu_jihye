#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k, s;
	char ch;

	// �Է�
	cin >> n >> k;
	vector<char> arr(n, '?');

	int idx = 0;
	bool flag = true;

	for (int i = 0; i < k; i++) {
		cin >> s >> ch;
		idx = (idx + s) % n;
		if (arr[idx] != '?') { // ���ڰ� ����ְ�
			if (arr[idx] == ch) { // ���� ���ڶ�� �������� �ݺ� ���
				continue;
			}
			flag = false;	// �ٸ� ���ڶ�� �׷� ������ �����Ƿ� flag false��
		}
		else {
			arr[idx] = ch;
		}
	}

	for (int i = 0; i < n; i++) {	// �ߺ� üũ
		if (arr[i] == '?') continue;
		for (int j = i + 1; j < n; j++) {	// i��° �ִ� ���ڿ�
			if (arr[i] == arr[j]) {	// �� �ڷ� ���� �� ������
				flag = false;		// flag false
				break;
			}
		}
	}

	if (flag) { // flag true ��� ���
		for (int i = 0; i < n; i++) {
			cout << arr[idx];
			idx--;
			if (idx < 0) idx += n;
		}
	}
	else {	// �ƴ϶�� ! ���
		cout << '!';
	}
	return 0;
}
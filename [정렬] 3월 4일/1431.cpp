#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;


int numTotal(const string& a) {	//���ڿ����� ���ڸ� ���ϴ� �Լ�
	char ch[100];
	strcpy(ch, a.c_str());
	int sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (ch[i] >= 48 && ch[i] < 58)
			sum += (ch[i] - 48);
	}
	return sum;
}

bool cmp(const string& a, const string& b) {
	if (a.length() != b.length())	// a�� b ���̰� �ٸ���
		return a.length() < b.length();//ª�� ���� ������
	if(numTotal(a) != numTotal(b)) //(a�� b ���̰� ���ٸ�) ���� �� ��
		return numTotal(a) < numTotal(b);
	return a < b;	//�� �������� ���� �� ���ٸ� ������ ��
}

int main() {
	int N;
	cin >> N;
	vector<string> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
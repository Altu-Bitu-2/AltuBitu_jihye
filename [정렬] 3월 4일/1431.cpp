#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;


int numTotal(const string& a) {	//문자열에서 숫자만 더하는 함수
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
	if (a.length() != b.length())	// a와 b 길이가 다르면
		return a.length() < b.length();//짧은 쪽이 앞으로
	if(numTotal(a) != numTotal(b)) //(a와 b 길이가 같다면) 숫자 합 비교
		return numTotal(a) < numTotal(b);
	return a < b;	//위 조건으로 비교할 수 없다면 사전순 비교
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
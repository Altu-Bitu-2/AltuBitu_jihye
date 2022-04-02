#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, taesu, p;
	cin >> n >> taesu >> p;
	vector<int> v(p);
	int grade = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n == p && v[n - 1] >= taesu) {
		grade = -1; // 리스트가 다 찼고 태수 점수보다 크거나 같으면
	}				// 등수안에 못 듦
	else {
		for (int i = 0; i < n; i++) {
			if (v[i] > taesu) // 태수보다 점수가 높을 경우
				grade++;	  // 등수 증가
		}
	}
	cout << grade;

	return 0;
}
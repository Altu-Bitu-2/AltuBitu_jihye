#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coor {	//좌표 구조체
	int x, y;
};

bool cmp(const coor &a, const coor &b) {	
	if (a.y != b.y) { //y좌표 먼저 비교
		return a.y < b.y;	//작은 쪽이 앞 쪽에 오게 함
	}
	if (a.x != b.x) {	//x좌표 비교
		return a.x < b.x;	//작은 쪽이 앞 쪽에 오게 함
	}	
}

int main() {
	int N;
	cin >> N;
	vector<coor> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}
	return 0;
}
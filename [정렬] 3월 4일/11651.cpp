#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coor {	//��ǥ ����ü
	int x, y;
};

bool cmp(const coor &a, const coor &b) {	
	if (a.y != b.y) { //y��ǥ ���� ��
		return a.y < b.y;	//���� ���� �� �ʿ� ���� ��
	}
	if (a.x != b.x) {	//x��ǥ ��
		return a.x < b.x;	//���� ���� �� �ʿ� ���� ��
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
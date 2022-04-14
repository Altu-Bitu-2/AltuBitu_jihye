#include <iostream>
#include <vector>

using namespace std;

typedef pair<string, int> ci;

// 칭호의 idx 를 반환하는 함수
int searchTitle(int stat, int left, int right, vector<ci>& arr) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (stat <= arr[mid].second) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}	
	return right + 1;
}

int main() {
	// 입출력 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	// 입력
	cin >> n >> m;
	vector<ci> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	// 출력
	int stat, idx;
	for (int i = 0; i < m; i++) {
		cin >> stat;
		idx = searchTitle(stat, 0, n - 1, arr);
		cout << arr[idx].first << '\n';
	}
	return 0;
}
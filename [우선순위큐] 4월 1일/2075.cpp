#include <iostream>
#include <queue>

using namespace std;

int main() {
	// 입출력 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.push(num);
			if (pq.size() > n) {
				pq.pop();
			}
		}
		
	}
	cout << pq.top();
	return 0;
}
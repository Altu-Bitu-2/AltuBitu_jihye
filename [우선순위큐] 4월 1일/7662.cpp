#include <iostream>
#include <set>

using namespace std;

int main() {
	// 입출력 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, k, n;
	char ch;
	cin >> t;
	while (t--) {
		cin >> k;
		multiset<int> pq;
		for (int i = 0; i < k; i++) {
			cin >> ch >> n;
			if (ch == 'I') {
				pq.insert(n);
			}
			else if (ch == 'D') {
				if (!pq.empty()) {
					if (n == 1) { // 최대값 제거
						auto iter = pq.end();
						iter--;
						pq.erase(iter);
					}
					else if (n == -1) { // 최솟값 제거
						pq.erase(pq.begin());
					}
				}
			}
		}
		if (pq.empty()) {
			cout << "EMPTY\n";
		}
		else {
			auto iter = pq.end();
			iter--;
			cout << *iter << ' ' << *pq.begin() << '\n';
		}
	}
	return 0;
}
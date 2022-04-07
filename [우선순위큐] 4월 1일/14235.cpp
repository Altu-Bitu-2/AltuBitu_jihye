#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, a, num;
	priority_queue<int> pq;
	cin >> n;
	while (n--) {
		cin >> a;
		if (a == 0) { // 출력
			if (pq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else { // 선물 입력받기
			while (a--) {
				cin >> num;
				pq.push(num);
			}
		}
	}
	return 0;
}
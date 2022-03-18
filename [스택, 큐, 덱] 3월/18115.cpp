#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	int N, n;
	cin >> N;
	vector<int> input;
	deque<int> dq;
	for (int i = 0; i < N; i++) {
		cin >> n;
		input.push_back(n);
	}
	int num = 1, tmp;
	for (int i = N - 1; i >= 0; i--) {
		if (input[i] == 1) {
			dq.push_front(num);
		}
		else if (input[i] == 2) {
			tmp = dq[0];
			dq.pop_front();
			dq.push_front(num);
			dq.push_front(tmp);
		}
		else if (input[i] == 3) {
			dq.push_back(num);
		}		
		num++;
	}
	while (!dq.empty()) {
		cout << dq.front() << ' ';
		dq.pop_front();
	}
	cout << '\n';
	return 0;
}
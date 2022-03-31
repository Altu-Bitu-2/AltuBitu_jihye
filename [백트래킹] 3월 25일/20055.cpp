#include <iostream>
#include <deque>

using namespace std;

struct element { // Ä­ ±¸Á¶Ã¼
	bool robot;
	int durability;
};

int n, k;
deque<element> convey;

void move() {
	convey.push_front(convey.back());
	convey.pop_back();
	convey[n - 1].robot = false;
}

void robotMove() {
	for (int i = n - 2; i >= 0; i--) {
		if (!convey[i + 1].robot && (convey[i + 1].durability > 0) && convey[i].robot) {
			convey[i].robot = false;
			convey[i + 1].robot = true;
			convey[i + 1].durability--;
		}
		convey[n - 1].robot = false;
	}
}

void robotPut() {
	if (!convey[0].robot && convey[0].durability > 0) {
		convey[0].robot = true;
		convey[0].durability--;
	}
}

int check() {
	int count = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (convey[i].durability == 0) {
			count++;
		}
	}
	return count;
}

int main() {	
	int cnt = 1;
	element item;
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++) {
		cin >> item.durability;
		item.robot = false;
		convey.push_back(item);
	}
	while (true) {
		move();
		robotMove();
		robotPut();
		int flag = check();
		if (flag >= k) {
			cout << cnt;
			return 0;
		}
		cnt++;
	}
	return 0;
}
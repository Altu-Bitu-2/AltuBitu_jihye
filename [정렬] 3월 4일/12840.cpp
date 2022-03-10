#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_SECOND 24*60*60

using namespace std;


void printTime(int second) {	//시간출력
	printf("%d ", second / 60 / 60 % 60);
	printf("%d ", second / 60 % 60);
	printf("%d\n", second % 60);
}

int main() {
	int h, m, s, q, T, c, totalSecond;
	int maxSecond = 24 * 60 * 60;

	scanf("%d %d %d", &h, &m, &s);

	totalSecond = h * 60 * 60 + m * 60 + s;

	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		scanf("%d", &T);
		if (T == 1) {
			scanf("%d", &c);
			totalSecond += c;
		}
		if (T == 2) {
			scanf("%d", &c);
			totalSecond -= c;
		}
		if (T == 3) {
			while (totalSecond < 0) {
				totalSecond += MAX_SECOND;
			}
			while (totalSecond > MAX_SECOND) {
				totalSecond -= MAX_SECOND;
			}
			printTime(totalSecond);
		}
	}
	return 0;
}
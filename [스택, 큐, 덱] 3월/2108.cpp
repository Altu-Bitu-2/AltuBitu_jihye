#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
	int N, num, total = 0;
	vector<int> v;
	vector<int> cnt(8001);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		total += num;
		v.push_back(num);
		cnt[(num+4000)]++;
	}
	sort(v.begin(), v.end());

	int max = 0, idx;
	for (int i = 0; i < 8001; i++) { //최빈값 찾기
		if (cnt[i] > max) {
			max = cnt[i];
			idx = i;
		}
	}
	for (int i = idx + 1; i < 8001; i++) { //빈도가 같은 수가 있다면 그 다음 index부터
		if (cnt[i] == max) {		   //두번째로 작은 수 찾기
			idx = i;
			break;
		}
	}

	cout << (int)round(double(total) / N) << '\n'; //산술평균 출력
	cout << v[N / 2] << '\n';  //중앙값 출력
	cout << idx - 4000 << '\n'; //최빈값 출력
	cout << v[N - 1] - v[0] << '\n'; //범위 출력

	return 0;
}
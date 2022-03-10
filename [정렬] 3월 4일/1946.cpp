#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct score {	//점수 구조체
	int t1, t2;
};

bool cmp(const score& a, const score& b) {
	return a.t1 < b.t1;
}

int main() {
	int T, N, max;
	cin >> T;
	vector<int> pass(T, 1); //최종합격자 수 저장 배열 선언 및 초기화
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<score> scr(N);	//지원자의 성적 배열
		for (int j = 0; j < N; j++) {
			cin >> scr[j].t1 >> scr[j].t2;	//성적 입력
		}
		sort(scr.begin(), scr.end(), cmp);	//t1을 기준으로 정렬
		max = scr[0].t2;	//max값 초기화
		for (int j = 0; j < N; j++) {	//정렬된 배열에서 t2값 비교
			if (max > scr[j].t2) { //현재의 max값보다 t2값이 작을 경우(순위가 더 높을 경우)
				max = scr[j].t2; //max값 변경 및
				pass[i]++; //최종합격자 수 증가
			}
		}
	}
	for (int i = 0; i < T; i++) {
		cout << pass[i] << '\n';
	}
	return 0;
}
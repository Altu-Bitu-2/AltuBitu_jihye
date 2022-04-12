#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 입력 (입력값의 범위가 크므로 long long 사용) 
	long long n;
	cin >> n;
	vector<long long> oilprice(n+1, 0);
	vector<long long> distance(n+1, 0);	
	for (int i = 1; i < n; i++) {
		cin >> distance[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> oilprice[i];
	}
	
	long long ans = 0, now = oilprice[0]; // now에 현재 도시의 기름값 저장 
	ans += now * distance[1]; // 처음 도시 -> 두번째 도시로 갈 때는 무조건 충전 
	
	for (int i = 1; i < n; i++) {	// 다음 반복 
		if (now < oilprice[i]) {	// 만약 현재 기름값이 다음 주유소보다 싸다면 
			ans += now * distance[i + 1]; // 지금 충전 
		}
		else {	// 다음 주유소가 싸다면 
			now = oilprice[i];	// 다음 주유소의 기름값을 now 에 저장 
			ans += now * distance[i + 1];	// 총 기름값을 ans에 더함 
		}
	}	
	cout << ans;
	return 0;
}

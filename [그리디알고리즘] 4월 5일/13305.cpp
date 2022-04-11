#include <iostream>
#include <vector>

using namespace std;

int minPrice(int n, vector<int>& oilprice, vector<int>& distance) {
	int ans = 0, idx = 0;
	ans += oilprice[idx] * distance[1];
	for (int i = 1; i < n; i++) {
		if (oilprice[idx] < oilprice[i]) {
			ans += oilprice[idx] * distance[i + 1];
		}
		else {
			idx++;
			ans += oilprice[idx] * oilprice[i + 1];
		}
	}
	return ans;
}

int main() {
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
	long long ans = 0, now = oilprice[0];
	ans += now * distance[1];
	for (int i = 1; i < n; i++) {
		if (now < oilprice[i]) {
			ans += now * distance[i + 1];
		}
		else {
			now = oilprice[i];
			ans += now * distance[i + 1];
		}
	}
	cout << ans;
	return 0;
}
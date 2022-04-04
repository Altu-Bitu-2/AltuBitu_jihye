#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest(vector<int> &v) {
	int size = v.size();
	vector<int> dp(size, 1);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]){
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	sort(dp.begin(), dp.end());
	int ans = dp[dp.size() - 1];

	return ans;
}

int main() {
	int n, ans;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	ans = longest(num);
	cout << ans;
	return 0;
}
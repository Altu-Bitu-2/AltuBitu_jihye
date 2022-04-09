#include <iostream>
#include <vector>

using namespace std;

int lcs(string s1, string s2) {
	vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i-1] == s2[j-1]) {	// 문자열이 같은 곳이 있다면
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else { // 다르다면
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int ans = dp[s1.size()][s2.size()];
	return ans;
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int ans = lcs(str1, str2);
	cout << ans;
	return 0;
}
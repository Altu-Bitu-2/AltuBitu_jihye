#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int t, a, b, num;	
	cin >> t;
	while (t--) {
		cin >> a >> b;
		vector<int> v;
		v.push_back(1);
		for (int i = 1; i < 5; i++) {
			num = (int)pow(a, i) % 10;
			if (num == 0) {
				num = 10;
			}
			v.push_back(num);
		}
		if (b == 0) {
			cout << "1\n";
		}
		else {
			cout << v[b % 4] << '\n';
		}
	}
	return 0;
 }
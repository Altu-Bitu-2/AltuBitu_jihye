#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int t, a, b, num;	
	cin >> t;
	while (t--) {
		cin >> a >> b;
		b %= 4;
		if (b == 0) b = 4;
		num = (int)pow(a, b) % 10;
		if (num == 0) cout << "10\n";
		else {
			cout << num << '\n';
		}
	}
	return 0;
 }
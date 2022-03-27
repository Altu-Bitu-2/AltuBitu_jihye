#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, x;
	string str;
	vector<bool> v(20, 0);
	cin >> m;
	while (m--) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			v[x - 1] = true;
		}
		if (str == "remove") {
			cin >> x;
			v[x - 1] = false;
		}
		if (str == "check") {
			cin >> x;
			cout << v[x - 1] << '\n';
		}
		if (str == "toggle") {
			cin >> x;
			if (v[x - 1]) {
				v[x - 1] = false;
			}
			else {
				v[x - 1] = true;
			}
		}
		if (str == "all") {
			for (int i = 0; i < 20; i++) {
				v[i] = true;
			}
		}
		if (str == "empty") {
			for (int i = 0; i < 20; i++) {
				v[i] = false;
			}
		}
	}
	return 0;
}
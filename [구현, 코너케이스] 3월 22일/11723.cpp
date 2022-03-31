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
	vector<bool> v(21, 0);
	cin >> m;
	while (m--) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			v[x] = true;
		}
		if (str == "remove") {
			cin >> x;
			v[x] = false;
		}
		if (str == "check") {
			cin >> x;
			cout << v[x] << '\n';
		}
		if (str == "toggle") {
			cin >> x;
			v[x] = !v[x];
		}
		if (str == "all") {
			for (int i = 1; i < 21; i++) {
				v[i] = true;
			}
		}
		if (str == "empty") {
			for (int i = 1; i < 21; i++) {
				v[i] = false;
			}
		}
	}
	return 0;
}
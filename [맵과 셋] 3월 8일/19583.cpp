#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	string S, E, Q;
	set<string> attend;
	set<string> accept;

	cin >> S >> E >> Q;	
	while (true) {
		string time, name;
		cin >> time >> name;
		if (time == "" && name == "") break;
		if (time <= S) {
			attend.insert(name);
			continue;
		}
		if (time >= E && time <= Q) {
			if (attend.find(name) != attend.end()) {
				accept.insert(name);
				continue;
			}
		}
	}
	cout << accept.size() << '\n';
	return 0;
}
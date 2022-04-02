#include <iostream>
#include <string>

using namespace std;

int gcdRecursion(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcdRecursion(b, a % b);
}

int main() {
	string str;
	cin >> str;
	int pos = str.find(':');
	int a = stoi(str.substr(0, pos));
	int b = stoi(str.substr(pos+1));
	int l = gcdRecursion(a, b);
	cout << a/l << ':' << b/l << '\n';
	return 0;
}
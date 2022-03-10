#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int a, b;
	vector<int> arr;

	for (int i = 1; i < 21; i++) {
		arr.push_back(i);
	}

	for(int i=0; i<10; i++){
		 cin >> a;
		 cin >> b;
		 reverse(arr.begin() + (--a), arr.begin() + b);
	}

	for (int i = 0; i < 20; i++) {
		cout << arr[i] << ' ';
	}

	cout << endl;

	return 0;
}
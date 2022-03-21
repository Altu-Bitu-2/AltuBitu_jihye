#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
vector<bool> arr(MAX+1, true);

void primeVector() {    // 소수 배열 생성
    int cnt = 0;
    arr[0] = arr[1] = false;
    for (int i = 2; i <= MAX; i++) {
        if (!arr[i]) continue;
        for (int j = i+i; j <= MAX; j += i) {
            if (!arr[j]) continue;
            arr[j] = false;
        }
    }
}

void findOddPrimeSum(int n) {
    int val = false;
    for (int i = 3; i < n; i += 2) { // 홀수인 소수 탐색
        if (arr[i] && arr[n - i]) {
            cout << n << " = " << i << " + " << n - i << '\n';
            val = true;
            return;
        }
    }
    if (!val) {
        cout << "Goldbach's conjecture is wrong.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    primeVector(); 

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        findOddPrimeSum(n);        
    }

	return 0;
}
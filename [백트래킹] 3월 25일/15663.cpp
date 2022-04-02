#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 8; //배열 크기

// 다음 변수들 전역으로 선언 : 입력받을 n, m
// 숫자 저장할 벡터/ 출력할 벡터/ 중복 체크 벡터 
int n, m;
vector<int> num(SIZE);
vector<int> ans(SIZE);
vector<bool> check(SIZE);

void backtracking(int cnt) {
    if (cnt == m) { //길이 m 이라면 (기저조건)
        for (int i = 0; i < m; i++) { // m 개씩
            cout << ans[i] << ' ';	  // ans 배열에 저장된 값 출력 
        }
        cout << '\n';
        return; // 함수 종료 
    }
    int prev = 0; //이전에 선택한 값
    for (int i = 0; i < n; i++) {
        if (!check[i] && prev != num[i]) { //수 위치 중복 체크 && 이전에 탐색한 값이 아니라면
            prev = num[i];  	// 현재 값 저장 
            ans[cnt] = num[i];  // 출력할 벡터에 현재값 저장 
            check[i] = true;	// 중복 체크를 true
            backtracking(cnt + 1); // 함수 재귀호출 
            check[i] = false;	   // 함수 return 되면 중복 체크 false 
        }
    }
}

/**
 * 1. 우선 수열을 사전 순으로 증가하는 순서로 출력해야 하므로 주어진 수열을 오름차순 정렬
 * 2. 이 상태에서 우선, 같은 위치의 수를 또 선택하지 않도록 중복제거 (check 배열 사용)를 해줌
 * 3. 그 후, 중복되는 "수열"을 거르는 방법은 이전에 선택한 값을 변수에 저장해서, 수열을 만들다 다시 루트 노드로 돌아왔을 때
 *    이전에 선택한 값과 같은 값이면 넘어가면 됨! -> 어차피 같은 수이므로 같은 과정 반복해서 똑같은 수열이 나올 것
  */

int main() {
    //입력
    cin >> n >> m; // n과 m 입력받기 
    for (int i = 0; i < n; i++) { // n 만큼 수 입력받기 
        cin >> num[i];
    }

    //연산
    sort(num.begin(), num.begin() + n);  // 수열 정렬 

    //백트래킹 & 출력
    backtracking(0);
    return 0;
}

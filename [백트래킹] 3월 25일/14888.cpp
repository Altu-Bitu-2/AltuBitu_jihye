#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;	// 상수 입력값의 최대값 선언 
const int SIZE = 11;		// 입력받을 수 있는 수의 최대 개수 상수로 선언

int n;		// 전역변수로  필요한 변수들 선언 
vector<int> num(SIZE + 1); // 입력받을 수 벡터 선언 
vector<int> expression(4); //0: +, 1: -, 2: *, 3: / // 연산자의 개수를 입력받을 벡터선언 
int max_value = -INF_MAX, min_value = INF_MAX;

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum);  // 최대값 저장 
        min_value = min(min_value, sum);  // 최솟값 저장 
        return; // 함수 반환 
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) { // 해당 인덱스의 연산자가 남아있다면 
            expression[i]--; // 사용할 것이므로 -1 
            int new_sum = 0; // 계산할 값 저장할 정수 변수 선언 
            switch (i) { //연산자 종류에 따라
                case 0:
                    new_sum = sum + num[cnt + 1]; // 덧셈이면 기존 저장 sum에 다음 수를 더함 
                    break;
                case 1:
                    new_sum = sum - num[cnt + 1]; // 뺄셈이면  기존 저장 sum에 다음 수를 뺌 
                    break;
                case 2:
                    new_sum = sum * num[cnt + 1]; // 곱셈도
                    break;
                case 3:
                    new_sum = sum / num[cnt + 1]; // 나눗셈도 마찬가지 
                    break;
            }
            backtracking(cnt + 1, new_sum); // 다음 인덱스와 새롭게 계산된 new sum을 인수로 하고  재귀호출  
            expression[i]++; // 다시 연산자수 +1 
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n;	// 수 개수 n 입력받기 
    for (int i = 0; i < n; i++) {
        cin >> num[i];	// 수 개수 만큼 벡터에 수 입력받기 
    }
    for (int i = 0; i < 4; i++) { // 연산자의 개수 입력받기 
        cin >> expression[i];
    }

    //연산
    backtracking(0, num[0]); // 함수 호출 

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}

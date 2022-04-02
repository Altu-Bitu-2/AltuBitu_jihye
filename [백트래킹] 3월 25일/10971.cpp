#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

/**
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 	cnt : 현재까지 순회한 도시 개수 count
	cur_city : 현재 방문중인 도시 
	cost : 지금까지의 비용 
 */
void backtracking(int cnt, int cur_city, int cost) {
    if (cost >= ans) { //생각해보기 : 이 조건문이 없으면 어떻게 될까요?
        return;		   // ㄴanswer : 이미 최소값보다 큰 값이라면 계산할 필요가 없으니까 불필요하게 연산 하지 않을까요...? 
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) {	// 현재 도시에서 첫번째 도시로 돌아갈 비용이 0이 아니면 
            ans = min(ans, cost + matrix[cur_city][0]); // 최종값 ans에 cost와 현재까지의 최소값 ans에 
        }												// 현재도시-첫번째 도시 비용을 더한 값 비교 후 작은 값 저장 
        return;											// 함수 종료 
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true;	 // 방문할 것이므로 i 도시 방문했다고 표시 
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]); // 함수 재귀호출 : 방문한 도시 수+1, i 도시방문, cost+(현재도시에서 i도시 방문할때 비용)  
            visited[i] = false;  // 최소값이 나오지 않았다면 다시 돌아옴 (i 도시 방문 x)
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {
    //입력
    cin >> n;
    visited.assign(n, false); // 배열 초기화 
    matrix.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) { // 비용 입력받기 
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    //연산
    visited[0] = true; // 첫 번째 도시는 이미 순회한 상태이므로 true 
    backtracking(1, 0, 0);

    //출력
    cout << ans;
    return 0;
}

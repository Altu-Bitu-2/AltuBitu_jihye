#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int> &tree) {	// 나무 자르는 함수
    ll sum = 0;						// 자른 나무 합 저장할 sum 변수 선언
    for (int i = 0; i < tree.size(); i++) {
        if (height >= tree[i]) {	// 만약 자르려는 높이가 나무 높이보다 크다면
            return sum;				// sum 리턴
        }
        sum += (tree[i] - height);	// 아니라면 자른 길이 sum에 더함
    }
    return sum;	// 반복문 다 돌았으면 sum 리턴
}

int upperSearch(int left, int right, int target, vector<int> &tree) {	// 잘라야할 나무 길이 이진탐색하는 함수
    while (left <= right) {				 // left가 right보다 작을동안 반복
        int mid = (left + right) / 2;	 // mid 값 선언
        ll tree_cnt = cntTree(mid, tree);// 우선은 mid 만큼 자른 길이를 tree_cnt 변수에 저장

        if (tree_cnt >= target) {		 // 만약 tree_cnt가 target 길이보다 크다면 더 자른 것이므로
            left = mid + 1;				 // -> 나무 길이 up : left 포인터 오른쪽으로
        } else {						 // 반대의 경우라면 덜 자른 것이므로
            right = mid - 1;			 // -> 나무 길이 down : right 포인터 왼쪽으로
        }
    }
    return left - 1;					 // 반복문 다 돌았으면 (right가 left보다 왼쪽에 있으면) left-1 반환
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> tree(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end(), greater<>()); // 내림차순 정렬

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);
    return 0;
}
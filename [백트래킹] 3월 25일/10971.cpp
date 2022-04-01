#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //�湮 �˻� �迭
vector<vector<int>> matrix; //��� ���
int n, ans = INF; //�ּ� ��� ���� ���� �̸� �ִ����� �ʱ�ȭ

/**
 * !�����غ���! �Լ��� �� ���ڴ� ���� � ������ �ϰ� �ֳ���?
 	cnt : ������� ��ȸ�� ���� ���� count
	cur_city : ���� �湮���� ���� 
	cost : ���ݱ����� ��� 
 */
void backtracking(int cnt, int cur_city, int cost) {
    if (cost >= ans) { //�����غ��� : �� ���ǹ��� ������ ��� �ɱ��?
        return;		   // ��answer : �̹� �ּҰ����� ū ���̶�� ����� �ʿ䰡 �����ϱ� ���ʿ��ϰ� ���� ���� �������...? 
    }
    if (cnt == n) { //���� ���� : n���� ���ø� ��ȸ����
        //��� ����(0)�� �ٽ� ���ƿ� �� �ִ��� Ȯ��
        if (matrix[cur_city][0] != 0) {	// ���� ���ÿ��� ù��° ���÷� ���ư� ����� 0�� �ƴϸ� 
            ans = min(ans, cost + matrix[cur_city][0]); // ������ ans�� cost�� ��������� �ּҰ� ans�� 
        }												// ���絵��-ù��° ���� ����� ���� �� �� �� ���� �� ���� 
        return;											// �Լ� ���� 
    }
    for (int i = 0; i < n; i++) { //cur_city���� ���� i�� �̵�
        if (matrix[cur_city][i] && !visited[i]) { //���� �ְ�, ���� �湮���� ���� ����
            visited[i] = true;	 // �湮�� ���̹Ƿ� i ���� �湮�ߴٰ� ǥ�� 
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]); // �Լ� ���ȣ�� : �湮�� ���� ��+1, i ���ù湮, cost+(���絵�ÿ��� i���� �湮�Ҷ� ���)  
            visited[i] = false;  // �ּҰ��� ������ �ʾҴٸ� �ٽ� ���ƿ� (i ���� �湮 x)
        }
    }
}

/**
 * ��Ʈ��ŷ Ǯ�� (4ms)
 *
 * �� ����Ŭ�� �����, ��� ���ÿ��� �����ϵ� ���� �����Ƿ� 0�� ���ú��� �����ϴ� ��츸 �˻��ϸ� �ȴ�.
 */

int main() {
    //�Է�
    cin >> n;
    visited.assign(n, false); // �迭 �ʱ�ȭ 
    matrix.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) { // ��� �Է¹ޱ� 
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    //����
    visited[0] = true; // ù ��° ���ô� �̹� ��ȸ�� �����̹Ƿ� true 
    backtracking(1, 0, 0);

    //���
    cout << ans;
    return 0;
}

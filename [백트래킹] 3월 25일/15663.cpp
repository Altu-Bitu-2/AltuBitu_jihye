#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 8; //�迭 ũ��

// ���� ������ �������� ���� : �Է¹��� n, m
// ���� ������ ����/ ����� ����/ �ߺ� üũ ���� 
int n, m;
vector<int> num(SIZE);
vector<int> ans(SIZE);
vector<bool> check(SIZE);

void backtracking(int cnt) {
    if (cnt == m) { //���� m �̶�� (��������)
        for (int i = 0; i < m; i++) { // m ����
            cout << ans[i] << ' ';	  // ans �迭�� ����� �� ��� 
        }
        cout << '\n';
        return; // �Լ� ���� 
    }
    int prev = 0; //������ ������ ��
    for (int i = 0; i < n; i++) {
        if (!check[i] && prev != num[i]) { //�� ��ġ �ߺ� üũ && ������ Ž���� ���� �ƴ϶��
            prev = num[i];  	// ���� �� ���� 
            ans[cnt] = num[i];  // ����� ���Ϳ� ���簪 ���� 
            check[i] = true;	// �ߺ� üũ�� true
            backtracking(cnt + 1); // �Լ� ���ȣ�� 
            check[i] = false;	   // �Լ� return �Ǹ� �ߺ� üũ false 
        }
    }
}

/**
 * 1. �켱 ������ ���� ������ �����ϴ� ������ ����ؾ� �ϹǷ� �־��� ������ �������� ����
 * 2. �� ���¿��� �켱, ���� ��ġ�� ���� �� �������� �ʵ��� �ߺ����� (check �迭 ���)�� ����
 * 3. �� ��, �ߺ��Ǵ� "����"�� �Ÿ��� ����� ������ ������ ���� ������ �����ؼ�, ������ ����� �ٽ� ��Ʈ ���� ���ƿ��� ��
 *    ������ ������ ���� ���� ���̸� �Ѿ�� ��! -> ������ ���� ���̹Ƿ� ���� ���� �ݺ��ؼ� �Ȱ��� ������ ���� ��
  */

int main() {
    //�Է�
    cin >> n >> m; // n�� m �Է¹ޱ� 
    for (int i = 0; i < n; i++) { // n ��ŭ �� �Է¹ޱ� 
        cin >> num[i];
    }

    //����
    sort(num.begin(), num.begin() + n);  // ���� ���� 

    //��Ʈ��ŷ & ���
    backtracking(0);
    return 0;
}

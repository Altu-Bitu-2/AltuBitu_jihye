#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;	// ��� �Է°��� �ִ밪 ���� 
const int SIZE = 11;		// �Է¹��� �� �ִ� ���� �ִ� ���� ����� ����

int n;		// ����������  �ʿ��� ������ ���� 
vector<int> num(SIZE + 1); // �Է¹��� �� ���� ���� 
vector<int> expression(4); //0: +, 1: -, 2: *, 3: / // �������� ������ �Է¹��� ���ͼ��� 
int max_value = -INF_MAX, min_value = INF_MAX;

void backtracking(int cnt, int sum) { //cnt: �� �ε���, sum: ���� ���
    if (cnt == n - 1) { //���� ��� �Ϸ��ߴٸ� (��������)
        max_value = max(max_value, sum);  // �ִ밪 ���� 
        min_value = min(min_value, sum);  // �ּڰ� ���� 
        return; // �Լ� ��ȯ 
    }
    for (int i = 0; i < 4; i++) { //������ �˻�
        if (expression[i]) { // �ش� �ε����� �����ڰ� �����ִٸ� 
            expression[i]--; // ����� ���̹Ƿ� -1 
            int new_sum = 0; // ����� �� ������ ���� ���� ���� 
            switch (i) { //������ ������ ����
                case 0:
                    new_sum = sum + num[cnt + 1]; // �����̸� ���� ���� sum�� ���� ���� ���� 
                    break;
                case 1:
                    new_sum = sum - num[cnt + 1]; // �����̸�  ���� ���� sum�� ���� ���� �� 
                    break;
                case 2:
                    new_sum = sum * num[cnt + 1]; // ������
                    break;
                case 3:
                    new_sum = sum / num[cnt + 1]; // �������� �������� 
                    break;
            }
            backtracking(cnt + 1, new_sum); // ���� �ε����� ���Ӱ� ���� new sum�� �μ��� �ϰ�  ���ȣ��  
            expression[i]++; // �ٽ� �����ڼ� +1 
        }
    }
}

/**
 * ������ ��� �������鼭 ��ġ�� ��, �� �����ڿ� ���� �� ���
 */

int main() {
    //�Է�
    cin >> n;	// �� ���� n �Է¹ޱ� 
    for (int i = 0; i < n; i++) {
        cin >> num[i];	// �� ���� ��ŭ ���Ϳ� �� �Է¹ޱ� 
    }
    for (int i = 0; i < 4; i++) { // �������� ���� �Է¹ޱ� 
        cin >> expression[i];
    }

    //����
    backtracking(0, num[0]); // �Լ� ȣ�� 

    //���
    cout << max_value << '\n' << min_value;
    return 0;
}

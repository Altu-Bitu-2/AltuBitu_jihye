#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//���� ���ϸ����� ���Ե�� ������� ����
int maxClass(int m, priority_queue<int, vector<int>, greater<>> &pq) {
    int result = 0;
    while (!pq.empty() && pq.top() <= m) { //���̻� ���� ������ ���ų�, ���ϸ����� ���ڸ��� �ݺ��� Ż��
        m -= pq.top();	// ��ü ���ϸ������� �ּ��� pq�� root������ �� 
        pq.pop();		// pq pop 
        result++;		// ���� �� ���� 
    }
    return result;	// ����� ���� 
}

/**
 * [Yonsei TOTO]
 *
 * ���� �ο��� �̴��� �� �ʿ��� ���ϸ����� 0�� �ƴ϶� 1
 * 1. �� ������ ��� ���� �ʿ��� �ּ� ���ϸ����� ��� (����)
 * 2. ���� ���ϸ����� ���� ��� ������� ���� ��û (�켱���� ť or ����)
 */
int main() {
    int n, m, p, l;
    priority_queue<int, vector<int>, greater<>> pq; //�ּ� ��

    cin >> n >> m;
    while (n--) {
        //�Է�
        cin >> p >> l;
        vector<int> arr(p);
        for (int i = 0; i < p; i++) {
            cin >> arr[i];	// �ش� ���� �л����� ���� ���ϸ����� insert 
        }

        //����
        if (p < l) { //�����ο��� �̴��̶�� ���ϸ����� 1�� �־ ��
            pq.push(1);
            continue;
        }
        sort(arr.begin(), arr.end(), greater<>()); //�������� ����
        pq.push(arr[l - 1]); //l��°�� ���ϸ����� ���� ���� ����� ���� ���� ���ϸ����� �־�� ���� ����
    }

    //���
    cout << maxClass(m, pq);
}

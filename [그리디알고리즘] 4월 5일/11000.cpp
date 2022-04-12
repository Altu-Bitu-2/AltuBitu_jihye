#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; // int, int �� pair ����ü ci ���� 

//�ʿ� ���ǽ� ���� ���ϴ� �Լ�
int arrayRoom(int n, vector<ci> lec) {
    priority_queue<int, vector<int>, greater<>> pq; //���� �ð��� �����ϴ� �켱���� ť - ������������ ���� 

    pq.push(-1); //ó�� �ε��� ������ ���ϱ� ���� ���� �� ����. (ù��° ���� �� ���ŵ� ��)

    for (int i = 0; i < n; i++) {
        if (lec[i].first >= pq.top()) { //����ð��� ���� ���� �������� ���۽ð��� ���ų� �����ٸ� -> ���� ���ǽ�
            pq.pop();	// i���� ���� �ð��� ����ð��� ������� �������� ���ų� �ʴٸ� pop() 
        }
        pq.push(lec[i].second); //���� ���ǽ� ���� ���� or ���ο� ���ǽ� ���� ���� // ������ �ð� push 
    }
    return pq.size(); // pq ������ ��ȯ 
}

/**
 * [���ǽ� ����]
 *
 * ���ǽ� ���� �ּҷ� �ϱ� ���ؼ�, ���� ����ϴ� ���ǽ� �� ���� ���� ������ ���ǽǿ� ���� ���� �����ϴ� ���ǽ��� ��ġ�ؾ� �Ѵ�.
 * �� ������ ��� ���Ǹ� �� �����ؾ� �ϹǷ�, ȸ�ǽ� ���� �����ʹ� �ٸ���! ���� �����ϴ� ������ ������ ��.
 * ���� ���� ���� ������ �ð��� ���ϱ� ���� �ּ� ��(�켱���� ť) ���
 */

int main() {
    int n;

    //�Է�
    cin >> n;
    vector<ci> lec(n, ci(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> lec[i].first >> lec[i].second; //first: ���۽ð�, second: ����ð�
    }

    //����
    sort(lec.begin(), lec.end());	// ���۽ð� �������� ����


    //���
    cout << arrayRoom(n, lec) << '\n';
    return 0;
}

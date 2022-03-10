#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct score {	//���� ����ü
	int t1, t2;
};

bool cmp(const score& a, const score& b) {
	return a.t1 < b.t1;
}

int main() {
	int T, N, max;
	cin >> T;
	vector<int> pass(T, 1); //�����հ��� �� ���� �迭 ���� �� �ʱ�ȭ
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<score> scr(N);	//�������� ���� �迭
		for (int j = 0; j < N; j++) {
			cin >> scr[j].t1 >> scr[j].t2;	//���� �Է�
		}
		sort(scr.begin(), scr.end(), cmp);	//t1�� �������� ����
		max = scr[0].t2;	//max�� �ʱ�ȭ
		for (int j = 0; j < N; j++) {	//���ĵ� �迭���� t2�� ��
			if (max > scr[j].t2) { //������ max������ t2���� ���� ���(������ �� ���� ���)
				max = scr[j].t2; //max�� ���� ��
				pass[i]++; //�����հ��� �� ����
			}
		}
	}
	for (int i = 0; i < T; i++) {
		cout << pass[i] << '\n';
	}
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, taesu, p;
	cin >> n >> taesu >> p;
	vector<int> v(p);
	int grade = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n == p && v[n - 1] >= taesu) {
		grade = -1; // ����Ʈ�� �� á�� �¼� �������� ũ�ų� ������
	}				// ����ȿ� �� ��
	else {
		for (int i = 0; i < n; i++) {
			if (v[i] > taesu) // �¼����� ������ ���� ���
				grade++;	  // ��� ����
		}
	}
	cout << grade;

	return 0;
}
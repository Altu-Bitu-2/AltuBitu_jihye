#include <iostream>
#include <vector>

using namespace std;

int main() {
	// �Է� (�Է°��� ������ ũ�Ƿ� long long ���) 
	long long n;
	cin >> n;
	vector<long long> oilprice(n+1, 0);
	vector<long long> distance(n+1, 0);	
	for (int i = 1; i < n; i++) {
		cin >> distance[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> oilprice[i];
	}
	
	long long ans = 0, now = oilprice[0]; // now�� ���� ������ �⸧�� ���� 
	ans += now * distance[1]; // ó�� ���� -> �ι�° ���÷� �� ���� ������ ���� 
	
	for (int i = 1; i < n; i++) {	// ���� �ݺ� 
		if (now < oilprice[i]) {	// ���� ���� �⸧���� ���� �����Һ��� �δٸ� 
			ans += now * distance[i + 1]; // ���� ���� 
		}
		else {	// ���� �����Ұ� �δٸ� 
			now = oilprice[i];	// ���� �������� �⸧���� now �� ���� 
			ans += now * distance[i + 1];	// �� �⸧���� ans�� ���� 
		}
	}	
	cout << ans;
	return 0;
}

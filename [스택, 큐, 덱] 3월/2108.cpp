#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
	int N, num, total = 0;
	vector<int> v;
	vector<int> cnt(8001);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		total += num;
		v.push_back(num);
		cnt[(num+4000)]++;
	}
	sort(v.begin(), v.end());

	int max = 0, idx;
	for (int i = 0; i < 8001; i++) { //�ֺ� ã��
		if (cnt[i] > max) {
			max = cnt[i];
			idx = i;
		}
	}
	for (int i = idx + 1; i < 8001; i++) { //�󵵰� ���� ���� �ִٸ� �� ���� index����
		if (cnt[i] == max) {		   //�ι�°�� ���� �� ã��
			idx = i;
			break;
		}
	}

	cout << (int)round(double(total) / N) << '\n'; //������ ���
	cout << v[N / 2] << '\n';  //�߾Ӱ� ���
	cout << idx - 4000 << '\n'; //�ֺ� ���
	cout << v[N - 1] - v[0] << '\n'; //���� ���

	return 0;
}
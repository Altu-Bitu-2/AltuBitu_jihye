#include <iostream>
#include <unordered_set>

using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M, num;	
	cin >> T;
	while(T--){
		cin >> N;
		unordered_set<int> s1;
		for (int i = 0; i < N; i++) {
			cin >> num;
			s1.insert(num);
		}
		cin >> M;
		auto itr = s1.find(0); //iterator √ ±‚»≠
		for (int i = 0; i < M; i++) {
			cin >> num;
			printf("%d\n", s1.count(num));
		}
	}
	return 0;
}
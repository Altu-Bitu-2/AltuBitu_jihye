#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

int main(){
	int T, N, M, num;	
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		set<int> s1;
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			s1.insert(num);
		}
		scanf("%d", &M);
		auto itr = s1.find(0); //iterator ÃÊ±âÈ­
		for (int i = 0; i < M; i++) {
			scanf("%d", &num);
			printf("%d\n", s1.count(num));
		}
	}
	return 0;
}
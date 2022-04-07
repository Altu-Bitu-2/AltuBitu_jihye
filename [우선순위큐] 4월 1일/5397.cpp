//#include <iostream>
//#include <list>
//
//using namespace std;
//
//int main() {
//	// 입출력 향상
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int t;
//	cin >> t;
//	string pw;
//	list<char> ans;
//	list<char>::iterator iter;
//
//	while (t--) {
//		cin >> pw;
//		ans.clear();
//		iter = ans.begin();
//		for (int i = 0; i < pw.length(); i++) {
//			if (pw[i] == '<' && iter != ans.begin()){ 
//				iter--;
//			}
//			else if (pw[i] == '>' && iter != ans.end()) {
//				iter++;
//			}
//			else if (pw[i] == '-' && iter != ans.begin()) {
//				iter = ans.erase(--iter);
//			}
//			else if(pw[i] != '<' && pw[i] != '>' && pw[i] != '-'){ // 그 외의 문자가 올 경우
//				ans.insert(iter, pw[i]);
//			}
//		}
//		for (iter = ans.begin(); iter != ans.end(); iter++) { // 출력
//			cout << *iter;
//		}
//		cout << '\n';
//	}
//	return 0;
//}
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int A['z' - 'a' + 1]; 

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	string S; 

	int cnt = 0; 
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> S; 
		memset(A, 0, sizeof(A)); 
		bool isgw = true; 
		for (int j = 0; j < S.size(); ++j) {
			auto c = S[j]; 
			if (A[c - 'a']) {
				if (S[j - 1] != c) {
					isgw = false; 
					continue; 
				}
			
			}
			A[c - 'a']++;
		}
		if (isgw)
			cnt++;
	}

	cout << cnt; 

	return 0;
}

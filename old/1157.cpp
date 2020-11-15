#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string S;
	cin >> S;
	int M = 0;
	char C = '?';

	transform(S.begin(), S.end(), S.begin(), ::toupper);

	for (char c = 'A'; c <= 'Z'; ++c) {
		int cnt = count(S.begin(), S.end(), c);
		if (cnt > M) {
			C = c;
		}
		else if (cnt == M) {
			C = '?'; 
		}
	}

	cout << C; 


	return 0;
}
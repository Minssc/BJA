#include<iostream>
using namespace std;
int D[11];

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	
	D[1] = 1; 
	D[2] = 2;
	D[3] = 4; 
	
	for(int i=4; i<11; ++i)
		for(int j=i-3; j<i; ++j)
			D[i] += D[j]; 	
	
	for(int t=1; t<=T; ++t){
		int N;
		cin>>N; 
		cout << D[N] << '\n';	
	}
			
	return 0;
}

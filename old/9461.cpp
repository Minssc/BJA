#include<iostream>
using namespace std;
long long C[101]; 

long long rec(int n){
	if(n==1) return 1;
	if(n==2) return 1;
	if(n==3) return 1;	
	if(C[n]) return C[n];
	return C[n] = rec(n-3)+rec(n-2); 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T, N; 
	cin>>T; 
	
	for(int t=0; t<T; ++t){
		cin>>N; 
		cout << rec(N) << '\n';
	}
	
	return 0;
}

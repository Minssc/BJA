#include<iostream>
using namespace std;
int C[1000001]; 

int re(int n){
	if(n==1) return 1;
	if(n==2) return 2; 
	if(C[n]) return C[n];
	return C[n] = (re(n-1) + re(n-2))%15746; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 	
	int N;
	cin>>N; 
	cout << re(N);
	
	return 0;
}

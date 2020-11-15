#include<iostream>
using namespace std;
int A[11]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,K;
	cin>>N>>K; 
	for(int i=1; i<=N; ++i)
		cin>>A[i]; 
		
	//int cur = K; 
	int coins = 0; 
	for(int i=N; i>=1; --i){
		if(K-A[i]<0) continue; 
		coins += K/A[i]; 
		K%=A[i]; 
	}
	
	cout<<coins; 
	
	return 0;
}

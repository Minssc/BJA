#include<iostream>

using namespace std;
int N,K; 
int D[201][201]; 

int solve(){
	for(int i=0; i<=N; ++i) D[i][1]=1; 
	for(int i=2; i<=K; ++i)
		for(int j=0; j<=N; ++j)
			for(int k=0; k<=j; ++k)
				D[j][i]+=D[j-k][i-1],D[j][i]%=1000000000;
	return D[N][K]; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>K; 
	
	cout<<solve(); 
	return 0;
}


#include<iostream>
#include<algorithm> 

using namespace std;
int K;
int D[501]; 
int DP[501][501]; 
int S[501]; 

void solve(){
	cin>>K; 
	for(int i=1; i<=K; ++i){
		cin>>D[i]; 
		S[i]=S[i-1]+D[i]; 
	}
	
	
	for(int i=1; i<K; ++i){
		for(int j=1; j+i<=K; ++j){
			int k=i+j; 
			DP[j][k]=1234567890; 
			for(int m=j; m<k; ++m) DP[j][k]=min(DP[j][k], DP[j][m]+DP[m+1][k]+S[k]-S[j-1]); 	
		}
	}
	cout<<DP[1][K]<<'\n'; 
}	

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int tc; cin>>tc;

	for(int t=0; t<tc; ++t)
		solve(); 
	
	return 0;
}


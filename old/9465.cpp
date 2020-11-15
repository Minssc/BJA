#include<iostream>
#include<cstring>
using namespace std;

int D[2][100001];
int DP[2][100001];

void solve(int tc){
	int N; cin>>N;
	memset(DP,0,sizeof(DP));	
	for(int i=0; i<2; ++i) for(int j=1; j<=N; ++j)
		cin>>D[i][j];
		
	DP[0][0] = DP[1][0] = 0;
	DP[0][1] = D[0][1]; DP[1][1] = D[1][1];
	for(int i=2; i<=N; ++i){
		DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + D[0][i];
		DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + D[1][i];
	}
	
	cout<<max(DP[0][N],DP[1][N])<<'\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int T; cin>>T; 
	for(int t=1; t<=T; ++t)
		solve(t); 
	
	return 0;	
}


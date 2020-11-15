#include<iostream>
using namespace std;
int N,M; 
int D[301][301]; 
int DP[301][301]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin>>D[i][j];
	
	for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j) DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + D[i-1][j-1]; 
		
	int k; cin>>k; 
	for(int i=0; i<k; ++i){
		int a,b,c,d; cin>>a>>b>>c>>d; 
		cout<<DP[c][d]+DP[a-1][b-1]-DP[a-1][d]-DP[c][b-1]<<'\n'; ;
	}
}

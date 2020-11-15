#include<iostream>

using namespace std;
int N,M;
int D[1026][1026]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M;
	for(int i=1; i<=N; ++i) for(int j=1; j<=N; ++j){
		int v; cin>>v; 
		D[i][j] = D[i-1][j]+D[i][j-1]-D[i-1][j-1]+v; 
	}
	
	for(int i=0; i<M; ++i){
		int a,b,c,d;cin>>a>>b>>c>>d;
		cout<<D[c][d]-D[a-1][d]-D[c][b-1]+D[a-1][b-1]<<'\n'; 
	}
	
	return 0;
}


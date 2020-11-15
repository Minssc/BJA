#include<iostream>
using namespace std;
int N,M;
int D[1001][1001];

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j){
		cin>>D[i][j]; 
		D[i][j] += max(D[i-1][j],D[i][j-1]); 
	}
	
	cout<<D[N][M];
	return 0;	
}

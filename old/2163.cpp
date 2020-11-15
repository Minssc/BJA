#include<iostream>
using namespace std;
int D[301][301]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,M;
	cin>>N>>M; 
	for(int i=2; i<=M; ++i)
		D[1][i] = D[1][i-1]+1; 
	
	for(int i=2; i<=N; ++i)
		for(int j=1; j<=M; ++j)
			D[i][j] = D[i-1][j] + D[1][j] + 1; 
			
	
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j){
			cout<<D[i][j]<<' ';		
		}
		cout<<endl;
	}
	cout<<D[N][M];
	
	
	return 0;	
}

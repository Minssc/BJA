#include<iostream>
using namespace std;

int D[101][100001];
int W[101];
short V[101]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N, K;
	cin>>N>>K; 
	for(int i=1; i<=N; ++i)
		cin>>W[i]>>V[i]; 
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=K; ++j){
			D[i][j] = D[i-1][j];
			if(j-W[i] >= 0){
				D[i][j] = max(D[i][j], D[i-1][j-W[i]]+V[i]);
			}
		}			
	}
	
	cout<<D[N][K];
	
	return 0;
}

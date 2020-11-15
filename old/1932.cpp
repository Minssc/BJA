#include<iostream>
using namespace std;

short T[501][501];
int D[501][501];

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 	
	int N; 
	cin>>N;
	 
	for(int i=1; i<=N; ++i)
		for(int j=0; j<i; ++j)
			cin >> T[i][j]; 
		
	D[1][0] = T[1][0]; 
	
	for(int i=2; i<=N; ++i){
		for(int k=0; k<i; ++k){
			if(k==0)
				D[i][k] = D[i-1][k] + T[i][k]; 
			else if(k==i-1)
				D[i][k] = D[i-1][k-1] + T[i][k]; 
			else 
				D[i][k] = max(D[i-1][k-1] + T[i][k], D[i-1][k] + T[i][k]); 	
		}
	}
	
	int max = 0; 
	for(int i=0; i<N; ++i){
		if(D[N][i] > max)
			max = D[N][i]; 
	}
	
	cout << max; 
	
	return 0;
}

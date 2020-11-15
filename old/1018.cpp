#include<iostream>
using namespace std;
char B[51][51]; //0:B 1:W 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,M;
	cin>>N>>M; 
	
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j){
		char c;
		cin>>c; 
		if(c=='W')
			B[i][j] = 1; 
	}
	
	int min = 1234567890; 
	
	for(int i=0; i<=N-8; ++i){
		for(int j=0; j<=M-8; ++j){
			int cnt = 0; 
			int BC = B[i][j]; 
			
			for(int k=i; k<i+8; ++k){
				for(int l=j; l<j+8; ++l){
					auto &AI = B[k][l]; 
					if(AI != BC)
						cnt++; 
					BC = !BC; 
				}
				BC = !BC; 
			}
			
			if(cnt<min)
				min = cnt; 
			if((64 - cnt) < min)
				min = 64 - cnt; 
		}
	}
	
	cout<<min; 
		
	
	return 0;
}

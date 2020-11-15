#include<iostream>
using namespace std;
int C[30][30]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int T;cin>>T;
	
	for(int i=1; i<30; ++i) C[1][i] = i; 
	
	for(int i=1; i<30; ++i)
		for(int j=1; j<30; ++j)
			for(int k=1; k<j; ++k)
				C[i][j] += C[i-1][j-k];
			
	for(int i=1; i<=T; ++i){
		int N,M;cin>>N>>M;
		cout<<C[N][M]<<'\n'; 
	}
		
	return 0; 	
}

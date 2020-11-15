#include<iostream>
#include<queue>
int N; 
using namespace std;
int D[501][501]; 
int C[501][501]; 
int MLIFE = 1;

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 

int dfs(int r, int c){
	if(C[r][c]) return C[r][c];
	C[r][c] = 1; 
	
	for(int i=0; i<4; ++i){
		int nr=r+DIR[i][0],nc=c+DIR[i][1];
		if(nr<0 || nc < 0 || nr>=N || nc>=N) continue; 
		if(D[r][c] >= D[nr][nc]) continue;
		C[r][c] = max(dfs(nr,nc)+1, C[r][c]);	
	}
	
	return C[r][c]; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
		cin>>D[i][j]; 
	
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			MLIFE = max(MLIFE,dfs(i,j)); 
			
	cout<<MLIFE<<'\n'; 
	
	return 0;
}

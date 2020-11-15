#include<iostream>
using namespace std;
int N;
int D[15][15]; 

bool check(int r, int c){
	for(int i=0; i<r; ++i){
		if(D[i][c] || D[r][i]) return false; 
		if(c-r+i>=0 && D[i][c-r+i]) return false; 
		if(c+r-i<N && D[i][c+r-i]) return false;  
	}
	return true; 	
}

int dfs(int r, int c, int q){
	if(r>=N) return 0; 
	if(q==N) return 1; 	
	
	int res = 0; 
	int i=r+1; 
	for(int j=0; j<N; ++j){
		if(c==j) continue; 
		if(!check(i,j)) continue; 
		D[i][j] = 1; 
		res += dfs(i,j,q+1);
		D[i][j] = 0; 
	}
	return res; 
}

int main(){
	cin>>N;
	int CNT = 0; 
	for(int i=0; i<N; ++i){
		D[0][i] = 1; 
		CNT+=dfs(0,i,1);
		D[0][i] = 0; 
	}
	
	cout<<CNT<<'\n'; 
	return 0;
}

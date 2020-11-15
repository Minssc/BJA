#include<iostream>
#include<cstring>
using namespace std;
int N;
int D[101][101];
int C[101][101]; 
int H=1; 
int col = 1; 

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
void dfs(int a,int b){
	C[a][b] = col; 
	
	for(int i=0; i<4; ++i){
		int na = a+DIR[i][0], nb = b+DIR[i][1]; 
		if(na<0 || nb<0 || na>=N || nb>=N) continue; 
		if(C[na][nb]) continue; 
		if(D[na][nb]<=H) continue; 
		C[na][nb] = col; 
		dfs(na,nb); 
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	int MAXH = 0;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
		cin>>D[i][j]; 
		if(D[i][j]>MAXH)
			MAXH=D[i][j];
	}
	
	int MAX = 0; 
	for(H=0; H<MAXH; ++H){
		memset(C,0,sizeof(C));
		col = 1; 
		for(int i=0; i<N; ++i) 
			for(int j=0; j<N; ++j)
				if(D[i][j] > H && !C[i][j]){
					dfs(i,j); 
					col++; 
				}
				//cout<<col-1<<endl;
		MAX = max(MAX,col-1); 
	}
	cout<<MAX; 
	
	return 0;
}

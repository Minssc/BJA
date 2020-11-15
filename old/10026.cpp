#include<iostream>
#include<cstring>
using namespace std;
int N;
int D[101][101]; 
int C[101][101]; 
int COL = 1; 

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
void dfs(int r, int c){
	for(int i=0; i<4; ++i){
		int nr = r+DIR[i][0], nc = c+DIR[i][1]; 
		if(nr<0 || nc<0 || nr>=N || nc>=N) continue; 
		if(C[nr][nc]) continue; 
		if(D[nr][nc] != D[r][c]) continue; 
		C[nr][nc] = COL;	
		dfs(nr,nc); 
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N; 
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
		char ch; cin>>ch; 
		D[i][j] = ch; 	
	}
	
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
		if(!C[i][j]){
			C[i][j] = COL; 
			dfs(i,j);
			COL++;
		}
//	
//	for(int i=0; i<N; ++i){ 
//		for(int j=0; j<N; ++j){
//			cout << C[i][j] << ' ';
//		}
//		cout<<endl;
//	}
	int NR = COL-1; 
	
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
		if(D[i][j] == 'G')
			D[i][j] = 'R'; 
	memset(C,0,sizeof(C)); 
	COL = 1; 

	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
		if(!C[i][j]){
			C[i][j] = COL; 
			dfs(i,j);
			COL++;
		}
	
	cout<< NR << ' ' << COL-1; 		
	
	return 0;
}
	

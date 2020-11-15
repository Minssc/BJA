#include<iostream>

using namespace std;
int N,M,H; 
int D[31][11]; 
int minv = 1234567890; 

int playLine(int lineno){
	for(int h=1; h<=H; ++h){
		if(D[h][lineno]) lineno++; 
		else if(lineno - 1 > 0 && D[h][lineno-1]) lineno--; 
	}
	
	return lineno; 
}

bool playGame(){
	for(int i=1; i<=N; ++i)
		if(playLine(i) != i) return false; 
	return true; 
}

void dfs(int depth, int lineno, int picks){
	if(picks == 4 || picks>=minv) return; 
//	cout<<depth<<','<<lineno<<','<<picks<<'\n'; 
	if(playGame()){
		minv = picks; 
		return; 	
	}
		
	for(int i=1; i<=H; ++i){
		if(i<depth) continue; 
		for(int j=1; j<N; ++j){
			if(i==depth && j<=lineno) continue; 
//			cout<<depth<<','<<lineno<<':'<<i<<','<<j<<'\n'; 
			if(D[i][j] || D[i][j+1] || D[i][j-1]) continue; 
			D[i][j] = 1; 
			dfs(i,j,picks+1); 
			D[i][j] = 0; 
//			dfs(i,j,picks); 
		}
	}
		
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M>>H; 
	for(int i=0; i<M; ++i){
		int a,b; cin>>a>>b; 
		D[a][b] = 1; 
	}
	
	dfs(1,0,0); 
	
	cout<<(minv==1234567890?-1:minv); 
//	for(int i=1; i<=N; ++i){
//		cout<<playLine(i)<<'\n'; 	
//	}
	
	return 0;
}


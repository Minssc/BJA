#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int T;
int M,N,K;
int COL;
int D[51][51]; 
bool C[51][51]; 

int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; 
void bfs(int a,int b){
	queue<pair<int, int>> Q; 
	Q.push(make_pair(a,b)); 
	C[a][b] = 1; 
	D[a][b] = COL; 
	
	while(!Q.empty()){
		auto p = Q.front(); Q.pop(); 
		
		for(int i=0; i<4; ++i){
			auto np = make_pair(p.first+DIR[i][0],p.second+DIR[i][1]); 	
			if(np.first<0 || np.second<0 || np.first>=N || np.second>= M) continue; //oob 
			if(!D[np.first][np.second]) continue; 
			if(C[np.first][np.second]) continue; 
			C[np.first][np.second] = 1; 
			D[np.first][np.second] = COL; 
			Q.push(np); 
		}
	}
	
	COL++; 
}

void solve(){
	cin>>M>>N>>K; 
	memset(D,0,sizeof(D)); 
	memset(C,0,sizeof(C)); 
	COL = 1; 
	for(int i=0; i<K; ++i){
		int X,Y; 	
		cin>>X>>Y; 
		D[Y][X] = 1; 
	}
	
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
		if(D[i][j] && !C[i][j])
			bfs(i,j); 
			
	cout << COL-1 << '\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>T;
	
	for(int t=1; t<=T; ++t)
		solve(); 
	
	return 0;
}

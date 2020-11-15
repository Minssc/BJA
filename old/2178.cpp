#include<iostream>
#include<queue>
using namespace std;
int N,M;
int D[101][101];
int C[101][101]; 

int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; 
void bfs(){
	queue<pair<int, int>> Q; 
	Q.push(make_pair(0,0)); 
	C[0][0] = 1; 
	
	while(!Q.empty()){
		auto &p = Q.front(); Q.pop(); 
		
		for(int i=0; i<4; ++i){
			auto np = make_pair(p.first+DIR[i][0],p.second+DIR[i][1]); 
			if(np.first<0 || np.second<0 || np.first>=N || np.second>=M) continue; //oob 
			if(!D[np.first][np.second]) continue; // cant go there. 
			if(C[np.first][np.second]) continue; // already visited 
			C[np.first][np.second] = C[p.first][p.second]+1; // mark path len
			if(np.first == N-1 && np.second == M-1) return; // reached end 
			Q.push(np);
		}	
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M;
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j){
		char c;
		cin>>c;
		D[i][j] = c-'0';	
	}
	bfs();
	cout<<C[N-1][M-1];
	
	return 0;
}

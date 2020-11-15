#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N,M,G,R;
int D[51][51]; 
int T[51][51]; 
int MCNT;

struct point{
	int r,c,t;
	bool OOB(){
		return this->r<0 || this->c<0 || this->r>=N || this->c>= M; 
	}
	int MD(){
		return D[this->r][this->c]; 	
	}
};
vector<point> Plantable; 

void draw(int D[51][51]){
	cout<<'\n'; 
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			cout<<D[i][j]<<' ';	
		}
		cout<<'\n'; 
	}
	cout<<'\n'; 
}

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
void bfs(){
	int B[51][51]; 
	memcpy(B,D,sizeof(B)); 
	queue<point> Q; 
	for(auto &p:Plantable)
		if(p.MD() != 2){
			Q.push(p); 
			T[p.r][p.c] = 1; 
		}
	
	int count = 0; 
	while(!Q.empty()){
		auto p = Q.front(); Q.pop(); 
		if(p.MD()==7) continue; 
		for(int i=0; i<4; ++i){
			point np = {p.r+DIR[i][0], p.c+DIR[i][1], p.t+1}; 	
			if(np.OOB() || !np.MD() || np.MD() == 7) continue; 
			if(T[np.r][np.c] && T[np.r][np.c]<=p.t) continue; 
			if(np.MD() == p.MD()) continue; 
			if(D[np.r][np.c]+p.MD() == 7){ // don't reproduce flowers 
				D[np.r][np.c] = 7; 
				count++; 
			}else{
				D[np.r][np.c] = p.MD(); 
				Q.push(np); 
			}
			
			T[np.r][np.c] = np.t; 
		}
	}
		
	MCNT = max(MCNT,count); 
	memset(T,0,sizeof(T)); 
	memcpy(D,B,sizeof(B)); 
}

void dfs(int rc, int gc, int idx){
	
	if(rc>R || gc>G) return; 
	if(rc==R&&gc==G){
		bfs(); 
	}else{
		if(idx>=Plantable.size()) return;
		int &r = Plantable[idx].r, &c = Plantable[idx].c; 
		//3 is green 4 is red 5 is flower 
		D[r][c] = 3; 
		dfs(rc,gc+1,idx+1); 
		D[r][c] = 4; 
		dfs(rc+1,gc,idx+1);
		D[r][c] = 2; 
		dfs(rc,gc,idx+1);
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M>>G>>R; 
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j){
		cin>>D[i][j]; 
		if(D[i][j] == 2)
			Plantable.push_back({i,j,1}); 
	}
	
	dfs(0,0,0); 
	
	cout<<MCNT<<'\n'; 
	return 0;
}

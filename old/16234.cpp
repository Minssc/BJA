#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int N,L,R;
int D[51][51]; 
bool V[51][51]; 

struct point{
	int r,c;
};

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
bool bfs(int r, int c){
	queue<point> Q; 
	Q.push({r,c}); 
	V[r][c] = 1; 
	bool ret = false; 
	vector<point> pv;
	pv.push_back({r,c});  
	int sum = D[r][c]; 
	
	while(!Q.empty()){
		auto p = Q.front(); Q.pop(); 
		for(int i=0; i<4; ++i){
			point np = {p.r+DIR[i][0], p.c+DIR[i][1]}; 
			if(np.r<0 || np.r>=N || np.c<0 || np.c>=N) continue; 
			if(V[np.r][np.c]) continue; 
			int v = abs(D[np.r][np.c]-D[p.r][p.c]); 
			if(L<=v && v<=R){
				V[np.r][np.c] = 1; 
				Q.push(np); 
				pv.push_back(np); 
				sum += D[np.r][np.c]; 
			}
		}
	}
	
	int avg = sum/pv.size(); 
	for(auto &p:pv) D[p.r][p.c] = avg; 	
	
	return pv.size()>1; 
}

bool move(){
	bool moved = false; 
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
		if(!V[i][j]) 
			moved |= bfs(i,j); 
	return moved; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>L>>R; 
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin>>D[i][j]; 	
	
	int cnt = 0; 
	while(true){
		if(!move()) break; 
		cnt++; 
		memset(V,0,sizeof(V)); 
	}
	cout<<cnt; 
	return 0;	
}

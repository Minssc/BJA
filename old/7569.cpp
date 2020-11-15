#include<iostream>
#include<queue>
using namespace std;
int M,N,H; //C R H 
int D[101][101][101];//H R C 
int V[101][101][101]; 
int MTIME = 1;

struct point{
	int h,r,c; 	
};

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
void bfs(){
	queue<point> Q;
	for(int i=0; i<H; ++i) for(int j=0; j<N; ++j) for(int k=0; k<M; ++k)
		if(D[i][j][k] == 1){
			Q.push({i,j,k});
			V[i][j][k] = 1; 	
		}
	
	while(!Q.empty()){	
		auto p = Q.front(); Q.pop(); 
		for(int i=0; i<4; ++i){
			point np = {p.h, p.r+DIR[i][0], p.c+DIR[i][1]}; 
			if(np.r<0 || np.c<0 || np.r>=N || np.c>=M) continue; // oob 
			if(D[np.h][np.r][np.c] || V[np.h][np.r][np.c]) continue;
			D[np.h][np.r][np.c] = 1; 
			V[np.h][np.r][np.c] = V[p.h][p.r][p.c]+1;
			MTIME = max(MTIME, V[np.h][np.r][np.c]); 
			Q.push(np); 
		}
		for(auto &i:{-1,1}){
			point np = {p.h+i, p.r, p.c}; 
			if(np.h<0 || np.h>=H) continue; // oob 
			if(D[np.h][np.r][np.c] || V[np.h][np.r][np.c]) continue;
			D[np.h][np.r][np.c] = 1; 
			V[np.h][np.r][np.c] = V[p.h][p.r][p.c]+1;
			MTIME = max(MTIME, V[np.h][np.r][np.c]); 
			Q.push(np); 
		}
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>M>>N>>H;
	for(int i=0; i<H; ++i) for(int j=0; j<N; ++j) for(int k=0; k<M; ++k)
		cin>>D[i][j][k];
	
	bfs(); 
	
	for(int i=0; i<H; ++i) for(int j=0; j<N; ++j) for(int k=0; k<M; ++k)
		if(!D[i][j][k]){
			cout<<-1; 
			return 0; 	
		}

	cout<<MTIME-1;
	return 0;
}

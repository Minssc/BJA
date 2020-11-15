#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int D[51][51]; 
int V[51][51]; 

int H,W; 
struct point{
	int r,c;
};

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
int shortestPath(point a){
	queue<point> Q;
	Q.push(a); 
	V[a.r][a.c] = 1; 
	int mdist = 0; 
	
	while(!Q.empty()){
		auto p = Q.front(); Q.pop(); 
		for(int i=0; i<4; ++i){
			point np = {p.r+DIR[i][0], p.c+DIR[i][1]};
			if(np.r<0 || np.c<0 || np.r>=H || np.c>=W) continue; 
			if(V[np.r][np.c]) continue; 	
			if(D[np.r][np.c] == 'W') continue; 
			V[np.r][np.c] = V[p.r][p.c]+1; 
			mdist = V[np.r][np.c]; 
			Q.push(np); 
		}
	}
	
	return mdist; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>H>>W; 
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j){
		char c; cin>>c;
		D[i][j] = c; 
	}
	int mdist = 0; 
		
	for(int i=0; i<H; ++i){
		for(int j=0; j<W; ++j){
			if(D[i][j] == 'L'){
				mdist = max(mdist,shortestPath({i,j})); 
				memset(V,0,sizeof(V)); 
			}
		}
	}
	
	cout<<mdist-1<<'\n'; 
		
	return 0;
}

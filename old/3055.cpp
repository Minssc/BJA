#include<iostream>
#include<queue>

using namespace std;
int R,C; 
int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
int D[51][51]; 
int V[51][51]; 
int W[51][51]; 

struct point{
	int r,c;
}; 
point DP,SP; 

void runWater(int r, int c){
	queue<point> Q; 
	W[r][c] = 1; 
	Q.push({r,c}); 
	
	while(!Q.empty()){
		auto p=Q.front(); Q.pop(); 
		for(int i=0; i<4; ++i){
			point np={p.r+DIR[i][0],p.c+DIR[i][1]}; 
			if(np.r<0||np.c<0||np.r>=R||np.c>=C) continue; 
			if(W[np.r][np.c]&&W[np.r][np.c]<=W[p.r][p.c]+1) continue; 
			if(D[np.r][np.c]=='X'||D[np.r][np.c]=='D') continue; 
			W[np.r][np.c]=W[p.r][p.c]+1; 
			Q.push(np); 	
		}
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>R>>C; 
	for(int i=0; i<R; ++i) for(int j=0; j<C; ++j){
		char c; cin>>c; 
		D[i][j]=c; 
		if(c=='D') DP={i,j}; 
		else if(c=='S') SP={i,j}; 
	}
	
	for(int i=0; i<R; ++i) for(int j=0; j<C; ++j)
		if(D[i][j]=='*') runWater(i,j); 
		
	queue<point> Q; 
	Q.push(SP); 
	V[SP.r][SP.c]=1; 
	
	while(!Q.empty()){
		auto p=Q.front(); Q.pop(); 
		for(int i=0; i<4; ++i){
			point np={p.r+DIR[i][0],p.c+DIR[i][1]}; 
			if(np.r<0||np.c<0||np.r>=R||np.c>=C) continue; 
			if(V[np.r][np.c]||D[np.r][np.c]=='*'||D[np.r][np.c]=='X') continue;
			if(W[np.r][np.c]&&W[np.r][np.c]<=V[p.r][p.c]+1) continue; 
			V[np.r][np.c]=V[p.r][p.c]+1; 
			if(D[np.r][np.c]=='D'){
				cout<<V[p.r][p.c]<<'\n'; 
				return 0; 
			}
			Q.push(np); 
		}
	}
	
	cout<<"KAKTUS"<<'\n'; 
	return 0;
}

/*
5 6
XXX*.X
XXXX.X
XXXX.X
XXXX.X
S....D
XXXXXX


*/


#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
int N,M;
int D[301][301]; 
bool V[301][301]; 

struct pnt{
	int r,c;
};

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
void bfs(int r, int c){
	queue<pnt> Q;
	Q.push({r,c}); 
	V[r][c] = 1; 
	
	while(!Q.empty()){		
		auto p = Q.front(); Q.pop(); 
		int mval = 0; 
		
		for(int i=0; i<4; ++i){
			pnt np = {p.r+DIR[i][0], p.c+DIR[i][1]}; 
			if(np.r<0 || np.c<0 || np.r>=N || np.c>=M) continue; // oob 
			if(!D[np.r][np.c]){
				if(!V[np.r][np.c]) mval++;
				continue; 	
			}
			if(V[np.r][np.c]) continue; 
			V[np.r][np.c] = 1; 
			Q.push(np); 
			
		}
		D[p.r][p.c] -= min(mval, D[p.r][p.c]); // melt the place 
	}
}

int simulate(){
	memset(V,0,sizeof(V)); 
	int cnt = 0; 
	
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
		if(D[i][j] && !V[i][j]){
			bfs(i,j); 
			cnt++; 
		}
//	cout<<"WAT "<<cnt<<'\n'; 
//	for(int i=0; i<N; ++i){
//		for(int j=0; j<M; ++j){		
//			cout<<D[i][j]<<' ';
//		}
//		cout<<'\n'; 
//	}
//	cout<<'\n'; 
			
	
	if(cnt>1) return 0; 
	else if(cnt==0) return -1;
	else return 1; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin>>D[i][j]; 
	
	int ans = 0; 
	while(true){
		int r = simulate(); 
		if(!r) break; 
		else if(r == -1){
			cout<<0;
			return 0; 
		}
		ans++; 
	}
	cout<<ans; 
	return 0;
}


#include<iostream>
#include<queue>
using namespace std;
int N,M;
int D[1001][1001];
int C[1001][1001][2]; 

struct point{
	int r,c,b; 	
};

int DIR[4][2] = {{0,1},{1,0},{-1,0},{0,-1}}; 
void bfs(){
	queue<point> Q;
	Q.push(point({1,1,0})); 
	C[1][1][0] = 1; 
	
	while(!Q.empty()){
		auto p = Q.front(); Q.pop(); 
		
		for(int i=0; i<4; ++i){
			point np = {p.r+DIR[i][0],p.c+DIR[i][1],p.b}; 
			if(np.r<1 || np.c<1 || np.r>N || np.c>M) continue; //oob 
			if(D[np.r][np.c]){ // skip if wall && no power 
				if(!np.b)
					np.b = 1; 
				else
					continue;
			}
			if(C[np.r][np.c][np.b]) continue; 
			
			C[np.r][np.c][np.b] = C[p.r][p.c][p.b]+1; 
			if(np.r==N && np.c ==M){
				cout << C[np.r][np.c][np.b];
				return;	
			}
			Q.push(np); 
		}
		
	}
	cout<<-1;
	return;
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j){
		char c; cin>>c; 
		D[i][j] = c-'0'; 
	}

	bfs(); 
	
//	int ans = (C[N][M][0] && C[N][M][1] ? min(C[N][M][0],C[N][M][1]) : max(C[N][M][0],C[N][M][1]));
//	
//	if(ans) cout<<ans;
//	else	cout<<-1;
	
	return 0;
}

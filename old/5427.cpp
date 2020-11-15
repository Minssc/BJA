#include<iostream>
#include<cstring> 
#include<queue>

struct dat{
	int val, t;	
};
struct pnt{
	int r,c,t; 	
};

using namespace std;
int T,W,H;
dat D[1001][1001]; 
bool V[1001][1001]; 
pnt START; 

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
void fire(){
	queue<pnt> Q; 
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j)
		if(D[i][j].val == '*'){
			Q.push({i,j,0}); 
			V[i][j] = 1; 
		}
	
	while(!Q.empty()){
		auto p = Q.front(); Q.pop(); 
		for(int i=0; i<4; ++i){ 
			pnt np = {p.r+DIR[i][0], p.c+DIR[i][1], p.t+1}; 
			if(np.r<0 || np.c<0 || np.r>=H || np.c>=W) continue; // oob 
			if(V[np.r][np.c] || D[np.r][np.c].val != '.') continue; 
			V[np.r][np.c] = 1; 
			D[np.r][np.c].val = '*'; 
			D[np.r][np.c].t = D[p.r][p.c].t+1; 
			Q.push(np); 
		}
	}
}

void escape(){
	queue<pnt> Q; 
	Q.push({START.r, START.c, 0}); 
	V[START.r][START.c] = 1; 
	
	while(!Q.empty()){
		auto p = Q.front(); Q.pop(); 
		for(int i=0; i<4; ++i){
			pnt np = {p.r+DIR[i][0], p.c+DIR[i][1], p.t+1}; 
			if(np.r<0 || np.c<0 || np.r>=H || np.c>=W) continue; 
			if(V[np.r][np.c]) continue;
			if(D[np.r][np.c].val == '#') continue; 
			else if(D[np.r][np.c].val == '*' && D[np.r][np.c].t <= np.t)continue; 
			
			V[np.r][np.c] = 1; 
			if(np.r == 0 || np.c == 0 || np.r == H-1 || np.c == W-1){
				cout<<np.t+1<<'\n'; 
				return; 	
			}
			Q.push(np); 
		}
	}
	
	cout<<"IMPOSSIBLE"<<'\n'; 
}

void solve(int tc = 0){
	memset(D,0,sizeof(D)); 
	memset(V,0,sizeof(V)); 
	cin>>W>>H; 
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j){
		char c;
		cin>>c; 
		D[i][j].val = c;
		if(D[i][j].val == '@'){
			START = {i,j,0}; 
			D[i][j].val = '.'; 	
		}
	}; 
	
	if(START.r == 0 || START.c == 0 || START.r == H-1 || START.c == W-1){
		cout<<1<<'\n';
		return; 	
	}
	
	fire(); 
	memset(V,0,sizeof(V)); 
	escape(); 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>T;
	for(int t=1; t<=T; ++t)
		solve(); 
	
	return 0;
}


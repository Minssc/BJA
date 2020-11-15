#include<iostream>
#include<vector>
using namespace std;
int N,M; 
struct point{
	int r,c;
	int dist(const point &p){
		return abs(this->r-p.r)+abs(this->c-p.c);	
	}
};

vector<point> H;
vector<point> C; 
int D[14]; 
int MINCD = 1234567890; 

void dfs(int idx, int picks){
	if(picks==M){
		int CDS = 0;
		for(auto &hp:H){
			int CD = 1234567890; 
			for(int i=0; i<M; ++i) CD = min(CD, hp.dist(C[D[i]])); 
				
			CDS += CD; 
		}
		MINCD = min(MINCD,CDS); 
		return;
	}
	if(idx>=C.size()) return;
	D[picks] = idx; 
	dfs(idx+1,picks+1);
	dfs(idx+1,picks); 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 	
	cin>>N>>M;
	for(int i=1; i<=N; ++i) for(int j=1; j<=N; ++j){
		int v; cin>>v; 
		if(v==1) H.push_back({i,j});
		else if(v==2) C.push_back({i,j});	
	}
	
	dfs(0,0);
	
	cout<<MINCD;	
	return 0;
}

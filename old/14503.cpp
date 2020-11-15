#include<iostream>

using namespace std;
int N,M;
int DIR[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; 
bool V[51][51];
int D[51][51];

struct bot{
	int r,c,d;
};


bot BP;
int CNT; 

bool simulate(){
	D[BP.r][BP.c] = 0; 
	if(!V[BP.r][BP.c]) CNT++; 
	V[BP.r][BP.c] = 1; 
	
	bool result = false; 
	for(int i=0; i<4; ++i){ // scan 4 dirs 
		int nd = (BP.d+3)%4; 
		BP.d = nd; 
		int nr = BP.r+DIR[nd][0], nc = BP.c+DIR[nd][1]; 
		if(V[nr][nc] || D[nr][nc]) continue;
		result = true;
		BP.r = nr, BP.c = nc; 
		break; 
	}
	
	if(!result){
		int nd = (BP.d+2)%4; 
		int nr = BP.r+DIR[nd][0], nc = BP.c+DIR[nd][1]; 
		if(!D[nr][nc]){
			result = true; 
			BP.r = nr, BP.c = nc; 
		}
	}
	
	return result; 	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	cin>>BP.r>>BP.c>>BP.d;
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin>>D[i][j]; 
	
	while(simulate());
	
	cout<<CNT; 
	return 0;
}


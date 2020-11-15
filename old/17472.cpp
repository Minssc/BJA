#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N,M,COL;
int D[11][11]; 
bool V[11][11]; 
int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
vector<vector<int>> I; 

void tag(int sr, int sc){
	queue<int> Q;
	Q.push(sr*1000+sc); 
	V[sr][sc]=1; 
	vector<int> island;
	island.push_back(sr*1000+sc); 
	
	while(!Q.empty()){
		int	r=Q.front()/1000,c=Q.front()%1000; Q.pop(); 
		
		for(int i=0; i<4; ++i){
			int nr=r+DIR[i][0], nc=c+DIR[i][1]; 
			if(nr<0||nc<0||nr>=N||nc>=N) continue; 
			if(V[nr][nc]||!D[nr][nc]) continue; 
			V[nr][nc]=1;
			island.push_back(nr*1000+nc); 
			Q.push(nr*1000+nc); 
		}
	}
	
	I.push_back(island); 
}

int main(){
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin>>N>>M;
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin>>D[i][j]; 

	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
		if(D[i][j]&&!V[i][j]) tag(i,j); 	

	int ans=1234567890; 		
	for(int i=0; i<I.size(); ++i){
		int minsum=0; 
		for(int j=i+1; j<I.size(); ++j){
			int mdist=1234567890; 
			for(auto &d:I[i])	
				for(auto &dd:I[j])
					mdist=min(mdist,abs(d/1000-dd/1000)+abs(d%1000-dd%1000)-1);	
			minsum+=min(minsum,mdist);  
		}
		ans=min(ans,minsum); 
	}
	
	cout<<ans; 
	return 0;
}

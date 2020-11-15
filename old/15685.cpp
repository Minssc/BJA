#include<iostream>
#include<vector>

using namespace std;
int N;
vector<int> D[21];
bool V[101][101];  
int DIR[4][2] = {{0,1},{-1,0},{0,-1},{1,0}}; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N; 
	
	for(int i=0; i<N; ++i){
		int x,y,d,g; cin>>x>>y>>d>>g; 
		D[i].push_back(d); 
		V[y][x] = 1; 
		
		for(int j=0; j<g; ++j) 
			for(int k=D[i].size()-1; k>=0; --k) D[i].push_back((D[i][k]+1)%4); 	
			
		for(auto &d:D[i]){
			int ny = y+DIR[d][0], nx = x+DIR[d][1]; 
			if(nx<=100 && ny<=100 && nx>=0 && ny >= 0) V[ny][nx] = 1; 	
			y = ny, x = nx; 
		}
	}
	
	int cnt = 0; 
	for(int i=0; i<100; ++i)
		for(int j=0; j<100; ++j)
			if(V[i][j] && V[i+1][j] && V[i][j+1] && V[i+1][j+1]) cnt++; 
		
	
	cout<<cnt; 
	
	return 0;
}


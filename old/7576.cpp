#include<iostream>
#include<queue>
using namespace std;

int N,M;
int D[1001][1001];
bool C[1001][1001]; 
queue<pair<int,int>> Q; 

int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; 
void sim(){
	while(!Q.empty()){
		auto p = Q.front();Q.pop();
		
		for(int i=0; i<4; ++i){
			auto np = make_pair(p.first+DIR[i][0], p.second+DIR[i][1]); 	
			if(np.first<0 || np.second<0 || np.first>=N || np.second>=M) continue; // oob 
			if(D[np.first][np.second] != 0) continue; //not there
			if(C[np.first][np.second]) continue; // already visit. 
			D[np.first][np.second] = D[p.first][p.second]+1; 
			C[np.first][np.second] = 1; 
			Q.push(np); 
		}
	}
	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>M>>N;
	
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j){
		cin>>D[i][j]; 
		if(D[i][j] == 1){
			Q.push(make_pair(i,j)); 
			C[i][j] = 1; 
		}
	}

	sim(); 
	
	int MAX = -1;
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			if(!D[i][j]){
				cout << -1; 
				return 0; 
			}else{
				MAX = max(MAX, D[i][j]); 
			}
		}
	}
	cout<<MAX-1;
	
	return 0;
}

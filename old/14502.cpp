#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N,M;
int D[9][9];
int MAX;

void draw(int D[][9]){
	cout<<endl;
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			cout << D[i][j] << ' ';	
		}
		cout<<endl; 
	}
}

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void spread(){
	int B[9][9];
	memcpy(B,D,sizeof(D));
	queue<pair<int, int>> Q;
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
		if(D[i][j]==2) Q.push(make_pair(i,j));
		
	int V[9][9];
	memset(V,0,sizeof(V)); 
	while(!Q.empty()){
		auto p = Q.front(); Q.pop();	
		if(!V[p.first][p.second]){
			V[p.first][p.second] = 1; 
			for(int i=0; i<4; ++i){
				auto np = make_pair(p.first+DIR[i][0],p.second+DIR[i][1]); 
				if(np.first >= 0 && np.second >= 0 && np.first < N && np.second < M && D[np.first][np.second] == 0){
					D[np.first][np.second] = 2; 
					Q.push(np); 	
				}
			}
		}
		
	}
	
	int cnt = 0; 
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
		if(!D[i][j]) cnt++; 
		
	if(cnt>MAX)
		MAX = cnt; 
	
	
	memcpy(D,B,sizeof(D)); 
}

void setWall(int a, int b,int c){
	D[a][b] = 1; 
	if(c == 3)
		spread(); 
	else{
		for(int i=0; i<N; ++i){
			for(int j=0; j<M; ++j){
				if(i<a&&j<b) i=a, j=b;
				if(!D[i][j])
					setWall(i,j,c+1); 	
			}
		}
	}
	
	D[a][b] = 0; 
}

int main(){
	//freopen("input/14502.txt","r",stdin); 
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
		cin>>D[i][j];
	
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			if(!D[i][j])
				setWall(i,j,1); 
				
	cout<<MAX<<endl; 
	
	return 0;
}

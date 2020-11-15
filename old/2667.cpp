#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring> 
using namespace std;

int D[26][26];
int C[26][26];
int N;
int COL = 1;

int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; 

void draw(){
	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j){
			cout << D[i][j] << ' '; 	
		}
		cout << '\n'; 
	}
	cout<<endl;
}

void search(int a, int b){
	queue<pair<int, int>> Q; 
	Q.push(make_pair(a,b)); 
	D[a][b] = COL; 
	C[a][b] = 1; 
	
	while(!Q.empty()){
		auto &p = Q.front(); Q.pop(); 
		
		for(int i=0; i<4; ++i){
			auto np = make_pair(p.first+DIR[i][0], p.second+DIR[i][1]);
			if(np.first<0 || np.second<0 || np.first>=N || np.second>=N) continue; // oob; 	
			if(!D[np.first][np.second]) continue; // not coloreable area 
			if(C[np.first][np.second]) continue; // already visited. 
			D[np.first][np.second] = COL; //color the area 
			C[np.first][np.second] = 1; //color the area 
			Q.push(np); 
		}
	}	
	COL++; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
		char c;
		cin>>c; 
		D[i][j] = c-'0'; 
	}
	
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			if(D[i][j] && !C[i][j])
				search(i,j); 		
		
	cout<<--COL<<'\n';
	
	int *COLS = new int[COL]; 
	memset(COLS,0,sizeof(int)*COL); 
	
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
		if(!D[i][j]) continue; 
		COLS[D[i][j]-1]++; 
	}
	
	sort(COLS,COLS+COL); 
	for(int i=0; i<COL; ++i)
		cout << COLS[i] << '\n'; 
	
	delete[] COLS; 
	return 0;
}

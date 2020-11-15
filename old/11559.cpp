#include<iostream>
#include<queue> 
#include<cstring> 
#include<vector>

using namespace std;
char D[13][7];
bool V[13][7];
int CHAIN,TAG;
int DIR[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; 

void pull(){
	for(int i=10; i>=0; --i){
		for(int j=0; j<6; ++j){
			if(D[i][j]=='.') continue; 
			int to=i; 
			while(to+1<12&&D[to+1][j]=='.') to++; 
			if(to==i) continue; 
			D[to][j]=D[i][j]; 
			D[i][j]='.'; 
		}
	}
}

bool pop(int r, int c){
	queue<int> Q; 
	Q.push(r*100+c); 
	V[r][c]=1; 
	vector<int> points;
	points.push_back(r*100+c); 
	
	while(!Q.empty()){
		auto p=Q.front(); Q.pop(); 
		int y=p/100,x=p%100; 
		for(int i=0; i<4; ++i){
			int ny=y+DIR[i][0],nx=x+DIR[i][1]; 
			if(nx<0||ny<0||nx>=6||ny>=12) continue; 
			if(V[ny][nx]||D[y][x]!=D[ny][nx]) continue; 
			V[ny][nx]=1; 
			points.push_back(ny*100+nx); 
			
			Q.push(ny*100+nx); 
		}
	}
	TAG++; 
	
	if(points.size()>=4){
		for(auto &i:points) D[i/100][i%100]='.'; 	
		return true; 
	}
	
	return false; 
}

bool simulate(){
	memset(V,0,sizeof(V));
	pull();
	TAG=1; 
	bool ret=0; 
	
	for(int i=0; i<12; ++i) for(int j=0; j<6; ++j)
		if(D[i][j]!='.'&&!V[i][j]) 
			ret|=pop(i,j); 
			
	return ret; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	for(int i=0; i<12; ++i) for(int j=0; j<6; ++j){
		char ch; cin>>ch; 
		D[i][j]=ch; 	
	}
	
	while(simulate()) CHAIN++; 
	cout<<CHAIN; 
	
	return 0;
}


#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
int N,M; 
int D[9][9]; 
int B[9][9]; 
int DIR[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; 
int minv = 1234567890;

struct cam{
	int r,c,d,t;
	
	void drawLine(int d){
//		cout<<"DRAWLINE "<<this->r<<','<<this->c<<','<<d<<endl; 
		int r = this->r, c = this->c; 
		while(true){
			int nr = r+DIR[d][0], nc = c+DIR[d][1]; 
			if(nr<0 || nc<0 || nr>=N || nc>=M) break; 
			if(D[nr][nc] == 6) break; 
			D[nr][nc] = 7; 	
			r = nr, c = nc; 
		}
	}
	
	void doLine(){
//		cout<<"DOLINE "<<this->r<<','<<this->c<<','<<this->d<<','<<this->t<<endl; 
		switch(this->t){
			case 1:
				for(auto &i:{0}) drawLine((this->d+i)%4); break;
			case 2:
				for(auto &i:{0,2}) drawLine((this->d+i)%4); break;
			case 3:
				for(auto &i:{0,3}) drawLine((this->d+i)%4); break;
			case 4:
				for(auto &i:{0,2,3}) drawLine((this->d+i)%4); break;
			case 5:
				for(auto &i:{0,1,2,3}) drawLine((this->d+i)%4); break;
		}
		
	}
};
vector<cam> CP; 

int getzeros(){
	int sum = 0; 
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
		if(!D[i][j]) sum++; 
		
	return sum; 	
}

void dfs(int cn){
	if(cn==CP.size()){
		for(auto &c:CP) c.doLine(); 
		
//		for(int i=0; i<N; ++i){
//			for(int j=0; j<M; ++j){
//				cout<<D[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
//		cout<<endl; 
		minv = min(minv, getzeros()); 
		memcpy(D,B,sizeof(D)); 
	}else{
		for(int i=0; i<4; ++i){
			CP[cn].d = i;
			dfs(cn+1); 
		}	
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M;
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j){
		cin>>D[i][j]; 
		if(D[i][j] && D[i][j] != 6) CP.push_back({i,j,0,D[i][j]}); 
	}
	memcpy(B,D,sizeof(D)); 
	dfs(0);     
	cout<<minv; 
		
	return 0;
}


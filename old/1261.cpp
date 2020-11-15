#include<iostream>
#include<queue>

#define pip pair<int,point> 
using namespace std;
int N,M; 
int D[101][101]; 
bool V[101][101]; 
struct data{
	int b,r,c;
	bool operator<(const data &targ) const{
		return this->b>targ.b; 	
	}
};
int DIR[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>M>>N; 
	for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j){
		char c; cin>>c; 
		D[i][j]=c; 
	} 

	priority_queue<data> Q;
	Q.push({0,1,1}); 
	V[1][1]=1; 
	
	while(!Q.empty()){
		auto d=Q.top();Q.pop();
		if(d.r==N&&d.c==M){
			cout<<d.b<<'\n'; 
			break; 	
		}
		
		for(int i=0; i<4; ++i){
			data nd={d.b,d.r+DIR[i][0],d.c+DIR[i][1]}; 
			if(nd.r<=0||nd.c<=0||nd.r>N||nd.c>M) continue; 
			if(V[nd.r][nd.c]) continue;
			V[nd.r][nd.c]=1; 
			if(D[nd.r][nd.c]=='1') nd.b++;  
			
			Q.push(nd); 
		}
	}
	
	return 0;
}


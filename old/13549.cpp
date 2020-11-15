#include<iostream>
#include<queue>
using namespace std;
int N,K; 
int V[100001]; 

void bfs(){
	queue<int> Q; 
	Q.push(N); 
	V[N] = 1;
	
	while(!Q.empty()){
		int x = Q.front(); Q.pop(); 
		if(x==K) return; 
		for(auto &i:{x,1,-1}){
			int nx = x+i; 
			if(nx<0 || nx>100000) continue;
			if(V[nx] && V[nx]<=V[x]+(i==x?0:1)) continue; 
			
			V[nx] = V[x]+(i==x?0:1); 
			Q.push(nx);  
		}	
	}
}

int main(){
	cin>>N>>K; 
	bfs(); 	
	cout<<V[K]-1; 
	return 0;
}

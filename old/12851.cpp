#include<iostream>
#include<queue>
using namespace std;
int N,K,CNT; 
int V[100001]; 

void bfs(){
	queue<int> Q; 
	Q.push(N); 
	V[N] = 1;
	
	while(!Q.empty()){
		int x = Q.front(); Q.pop(); 
		if(x==K) CNT++;
		
		for(auto &i:{-1,1,x}){
			int nx = x+i; 
			if(nx<0 || nx>100000) continue;
			if(V[nx] && V[nx]<V[x]+1) continue; 
			V[nx] = V[x]+1; 
			if(!V[K]||V[nx]<=V[K]) Q.push(nx);  
		}	
	}
}

int main(){
	cin>>N>>K; 
	bfs(); 	
	cout<<V[K]-1<<'\n'; 
	cout<<CNT<<'\n'; 
	return 0;
}

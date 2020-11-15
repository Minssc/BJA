#include<iostream>
using namespace std;
int N,M; 
int D[9]; 
int C[9]; 

void dfs(int idx){
	if(idx==M){
		for(int i=0; i<M; ++i)
			cout << D[i] << ' ';
		cout<<'\n'; 
		return; 	
	}
	
	for(int i=1; i<=N; ++i){
		if(C[i]) continue; 
		D[idx] = i;
		C[i] = 1; 
		dfs(idx+1);
		C[i] = 0;  	
	}
	
}

int main(){
	cout.tie(0),ios_base::sync_with_stdio(0); 
	cin>>N>>M; 
	dfs(0); 	
	return 0;
}

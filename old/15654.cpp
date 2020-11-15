#include<iostream>
#include<algorithm>

using namespace std;
int N,M; 
int D[9];
int PD[9]; 

void dfs(int m){
	if(m==M){
		for(int i=0; i<M; ++i)
			cout<<PD[i]<<' ';
		cout<<'\n'; 
	}else{
		for(int i=0; i<N; ++i){
			if(count(PD,PD+M,D[i])) continue; 
			PD[m] = D[i]; 
			dfs(m+1); 
			PD[m] = 0; 
		}
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=0; i<N; ++i) cin>>D[i]; 
	sort(D,D+N); 
	dfs(0); 
	
	return 0;
}


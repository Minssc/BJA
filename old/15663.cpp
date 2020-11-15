#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;
int N,M; 
int D[9];
int P[9]; 
int PD[9];
int C[10001]; 
unordered_set<string> SET; 

void dfs(int m){
	if(m==M){
		string key = ""; 
		for(int i=0; i<M; ++i)
			key+=to_string(PD[i])+' '; 
			
		if(SET.find(key)==SET.end()){
			cout<<key<<'\n';
			SET.insert(key); 
		}
	}else{
		for(int i=0; i<N; ++i){
			if(P[i]) continue; 
			PD[m] = D[i], P[i] = 1; 
			dfs(m+1); 
			PD[m] = 0, P[i] = 0;  
		}
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=0; i<N; ++i){
		cin>>D[i]; 
		C[D[i]]++; 
	}
	sort(D,D+N); 
	dfs(0); 
	return 0;
}


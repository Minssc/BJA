#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int> D[20001];
int C[20001]; 
int V,E; 
bool isBipartitian = true; 

void dfs(int s){
	C[s] = 1; 
	for(auto it=D[s].begin(); it!=D[s].end(); ++it){
		if(C[*it] && C[*it] == C[s]){
			isBipartitian = false;
			return; 
		}else
			C[*it] = 2; 
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T; cin>>T; 
	for(int t=1; t<=T; ++t){
		cin>>V>>E; 
		for(int i=0; i<E; ++i){
			int A,B; cin>>A>>B;
			D[A].push_back(B);
			D[B].push_back(A); 
		}
		
		for(int i=0; i<V; ++i){
			if(C[i] && C[i] != 1) isBipartitian = false;
			else if(!C[i]) dfs(i); 	
			if(!isBipartitian) break;
		}
		
		if(isBipartitian)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n'; 
		memset(C,0,sizeof(C)); 
	}
	
	return 0;
}

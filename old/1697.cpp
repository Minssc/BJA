#include<iostream>
#include<queue>
using namespace std;
int N,K;
int C[200001]; 

void bfs(){
	queue<int> Q; 
	Q.push(N);
	C[N] = 1; 
	int np; 
	
	while(!Q.empty()){
		auto p = Q.front(); Q.pop(); 
		
		np = p*2; 
		if(np<200001){
			if(!C[np] || C[np] > C[p]+1){
				C[np] = C[p]+1; 
				Q.push(np);	
			}
		}
		
		np = p+1; 
		if(np<200001){
			if(!C[np] || C[np] > C[p]+1){
				C[np] = C[p]+1; 
				Q.push(np);	
			}
		}
		
		np = p-1; 
		if(np<200001 && np >= 0){
			if(!C[np] || C[np] > C[p]+1){
				C[np] = C[p]+1; 
				Q.push(np);	
			}
		}
	}
	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	cin>>N>>K; 
	
	bfs(); 	
	
	cout<<C[K]-1; 
	return 0; 	
}

#include<iostream>
using namespace std;

int D[1001][1001];
int V[1001];  
int N,M;
int CNT; 

void dfs(int a){
	V[a] = 1; 
	
	for(int i=1; i<=N; ++i)
		if(D[a][i] && !V[i])
			dfs(i); 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	cin>>N>>M;
	
	for(int i=0; i<M; ++i){
		int A,B;
		cin>>A>>B; 
		D[A][B] = 1;
		D[B][A] = 1; 
	}
	
	for(int i=1; i<=N; ++i)
		if(!V[i]){
			dfs(i); 	
			CNT++;
		}
	cout<<CNT;
	return 0;
}

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N,M,V;
bool D[1001][1001];
bool VN[1001]; 

void dfs(int v){
	cout << v << ' ';
	
	for(int i=1; i<=N; ++i){
		if(D[v][i] && !VN[i]){
			VN[i] = 1;
			dfs(i);	
		}
	}
}

void bfs(int v){
	queue<int> Q;
	Q.push(v);
	
	while(!Q.empty()){
		int C = Q.front(); Q.pop(); 
		cout << C << ' ';	
		
		for(int i=1; i<=N; ++i){
			if(D[C][i] && !VN[i]){
				VN[i] = 1; 
				Q.push(i); 	
			}
		}
	}
	
	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M>>V;
	for(int i=0; i<M; ++i){
		int A,B;
		cin>>A>>B;
		D[A][B] = 1;
		D[B][A] = 1;
	}
	
	VN[V] = 1;
	dfs(V);
	cout<<endl;
	memset(VN,0,sizeof(VN));
	VN[V] = 1;
	bfs(V);
	
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
int M,N,K; 
int D[101][101];
int V[101][101];
int COL = 2; 

int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; 
void dfs(int a, int b){
	V[a][b] = COL; 
	
	for(int i=0; i<4; ++i){
		int na = a+DIR[i][0], nb = b+DIR[i][1];
		if(na<0 || nb<0 || na>=M || nb>=N) continue; 
		if(D[na][nb]) continue;
		if(V[na][nb]) continue; 
		V[na][nb] = COL; 
		dfs(na,nb); 	
	}
	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>M>>N>>K; 
	for(int i=0; i<K; ++i){
		int a1,a2,b1,b2;
		cin>>a1>>a2>>b1>>b2;
		for(int j=a1; j<b1; ++j){
			for(int k=a2; k<b2; ++k){
				D[k][j] = 1; 	
			}
		}
	}

	for(int i=0; i<M; ++i) for(int j=0; j<N; ++j)
		if(!D[i][j] && !V[i][j]){
			dfs(i,j); 
			COL++;
		}
	
	cout << COL-2 << '\n';
	int *p = new int[COL];
	for(int i=0; i<COL; ++i)
		p[i] = 0; 
		 
	for(int i=0; i<M; ++i) for(int j=0; j<N; ++j)	
		if(V[i][j])
			p[V[i][j]]++;
			
	sort(p+2,p+COL);
	for(int i=2; i<COL; ++i)
		cout << p[i] << ' ';
	cout<<'\n';
	
	return 0;
}

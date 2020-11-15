#include<iostream>
using namespace std;

int D[101][101]; 
int C[101]; 
int CNT; 

void dfs(int c){
	for(int i=1; i<=100; ++i){
		if(D[c][i] && !C[i]){
			C[i] = 1; CNT++;
			dfs(i); 	
		}
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int NC,V;
	cin>>NC>>V;
	for(int i=0; i<V; ++i){
		int A,B;
		cin>>A>>B; 
		D[A][B] = 1;
		D[B][A] = 1; 	
	}
	
	C[1] = 1; CNT++; 
	dfs(1);
	
	cout<<CNT-1<<'\n'; 
	
	return 0;
}

#include<iostream>
#define OS 10000000
using namespace std;
int D[2*OS+1];

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,M;
	cin>>N;
	for(int i=0; i<N; ++i){
		int A; cin>>A;
		D[A+OS] = 1; 	
	}
	cin>>M;
	for(int j=0; j<M; ++j){
		int A; cin>>A; 
		if(D[A+OS]) cout << 1; 
		else cout << 0;		
		cout<<' ';
	}
	
	return 0;
}

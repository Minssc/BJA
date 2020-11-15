#include<iostream>
#include<map>
using namespace std;
int D[20000001]; 
#define OS 10000000

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,M;	
	cin>>N;
	for(int i=0; i<N; ++i){
		int A; cin>>A;
		D[A+OS]++; 
	}
	
	cin>>M;
	for(int i=0; i<M; ++i){
		int A;cin>>A; 
		cout<<D[A+OS]<<' '; 
	}
	return 0;
}

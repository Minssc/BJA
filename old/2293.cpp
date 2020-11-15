#include<iostream>
using namespace std;
int N,K;
int D[101]; 
int C[10001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>K;
	for(int i=0; i<N; ++i) cin>>D[i];
	
	C[0] = 1; 
	for(int i=0; i<N; ++i)
		for(int j=D[i]; j<=K; ++j)
			C[j] += C[j-D[i]]; 
		
	cout<<C[K]; 
	
	return 0;
}

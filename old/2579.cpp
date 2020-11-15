#include<iostream>
using namespace std;

int C[301]; 
int D[301]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 
	
	for(int i=0; i<N; ++i)
		cin>>C[i]; 
	
	D[0] = C[0]; 
	D[1] = C[0] + C[1];
	D[2] = max(C[0]+C[2], C[1]+C[2]); 
	
	for(int i=3; i<N; ++i)
		D[i] = max(D[i-2]+C[i], D[i-3]+C[i-1]+C[i]); 	
		
	cout<<D[N-1];
	
	return 0;
}

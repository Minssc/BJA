#include<iostream>
using namespace std;

short C[10001]; 
int D[10001]; 

int main(){
	int N;
	cin>>N; 	
	
	for(int i=1; i<=N; ++i)
		cin>>C[i]; 
		
	D[1] = C[1];
	D[2] = C[1]+C[2];
		
	for(int i=3; i<=N; ++i){
		D[i] = max(D[i-2]+C[i], D[i-3] + C[i-1] + C[i]);
		D[i] = max(D[i], D[i-1]); 
	}
	
	cout<<D[N];
	
	return 0;
}

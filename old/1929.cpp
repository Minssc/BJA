#include<iostream>
#include<cstring>
using namespace std;
bool A[1000001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int M,N;
	cin>>M>>N;
	
	memset(A, 1, sizeof(A)); 
	
	for(int i=2; i<=N; ++i){
		int j=2;
		while(i*j<=N){
			A[i*j] = 0; 
			j++; 
		}
	}
	
	A[0] = 0;
	A[1] = 0; 
	
	for(int i=M; i<=N; ++i)
		if(A[i])
			cout << i << '\n';
	
	return 0;
}
	

#include<iostream>
using namespace std;

bool isPrime(int &A){
	if(A == 1) return false; 
	for(int j=2; j<A; ++j)
		if(A%j==0)
			return false;
	return true;
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N, A, C=0; 
	cin>>N;
	
	for(int i=0; i<N; ++i){
		cin>>A;
		if(isPrime(A))
			C++;
	}
	
	cout<<C;
	
	
	return 0;
}

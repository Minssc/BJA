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
	int M, N, sum = 0, P; 
	cin>>M>>N;
	
	for(int i=N; i>=M; --i){
		if(isPrime(i)){
			sum += i; 
			P = i; 
		}
	}
	
	if(sum)
		cout<<sum<<'\n'<<P;
	else
		cout<<-1; 
	
	
	return 0;
}

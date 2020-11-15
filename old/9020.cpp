#include<iostream>
using namespace std;

bool isPrime(int v){
	if(v==2) return true; 
	for(int i=2; i<v; ++i)
		if(v%i==0) return false;	
	return true; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T;cin>>T;
	for(int t=1; t<=T; ++t){
		int N;cin>>N;
		for(int i=N/2; i<N; ++i){
			if(isPrime(i) && isPrime(N-i)){
				cout<<N-i<<' '<<i<<'\n'; 
				break;
			}
		}
	}
	return 0;
}

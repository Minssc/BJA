#include<iostream>
#include<cstring>
using namespace std;
bool isPrime[123456*2+1];

int main(){
	memset(isPrime,1,sizeof(isPrime)); 
	isPrime[1] = 0; 
	isPrime[2] = 1; 
	for(int i=2; i<=123456*2; ++i){
		if(!isPrime[i]) continue; 
		for(int j=2; ; ++j){
			if(i*j>123456*2)
				break;	
			isPrime[i*j] = 0; 
		}
	}
	
	while(true){
		int N; cin>>N; 
		if(!N) break; 
		int sum = 0;
		for(int i=N+1; i<=2*N; ++i)
			if(isPrime[i]) sum++;
		
		cout<<sum<<'\n'; 
	}
	return 0; 
}

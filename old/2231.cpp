#include<iostream>
using namespace std;

int ssum(int n){
	int sum = n;
	while(n>0){
		sum+=n%10;
		n/=10; 
	}
	return sum; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int N;
	cin>>N;
	
	int n=N, d = 0;
	while(n>0){
		d++; 
		n/=10; 	
	}
		
	for(int i=0; i<N; ++i){
		if(ssum(i) == N){
			cout << i; 
			return 0;
		}
	}
	
	cout<<0; 
	
	return 0;
}

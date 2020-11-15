#include<iostream>

using namespace std;
int N,M;
bool B[11];

bool checkN(int n){
	do{
		if(B[(n%10)]) return false;
		n/=10;
	}while(n>0); 
	return true; 
}

int digits(int n){
	if(n<10) return 1;
	else if(n<100) return 2;
	else if(n<1000) return 3;
	else if(n<10000) return 4;
	else if(n<100000) return 5; 
	else if(n<1000000) return 6; 	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=0; i<M; ++i){
		int v; cin>>v; 
		B[v]=1; 
	}
	
	int mind=abs(N-100); 
	for(int i=0; i<1000000; ++i)
		if(mind&&checkN(i))
			mind=min(mind,abs(N-i)+digits(i)); 			
		
	cout<<mind;
	return 0;
}


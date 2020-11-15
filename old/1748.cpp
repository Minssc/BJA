#include<iostream>

using namespace std;

int digits(int &n){
	if(n<10) return 1; 
	if(n<100) return 2;
	if(n<1000) return 3; 
	if(n<10000) return 4; 
	if(n<100000) return 5; 
	if(n<1000000) return 6;
	if(n<10000000) return 7; 
	if(n<100000000) return 8; 
	else return 9; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n; cin>>n; 
	unsigned long long sum=0; 
	for(int i=1; i<=n; ++i) sum+=digits(i); 
	
	cout<<sum;
	return 0;
}


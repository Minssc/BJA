#include<iostream>
using namespace std;
int D[50001]; 

int main(){
	int n; cin>>n; 
	for(int i=1; i*i<50001; ++i) D[i] = 1; 
	
	for(int i=2; i<=n; ++i){
		int minc = 1234567890; 
		for(int j=1; j*j<=i; ++j) minc = min(minc,D[i-j*j]); 
		D[i] = minc+1; 
	}
	
	cout<<D[n];
	return 0;
}

#include<iostream>
using namespace std;
int D[100001];

int main(){
	int N; cin>>N; 
//		
//	for(int i=1; i<=100; ++i){
//		int p = i*i; 
//		for(int j=1; j<=10000; ++j){
//			if(p*j>=10000) break; 
//			D[p*j] = j; 	
//		}
//	}
	for(int i=1; i*i<=N; ++i) D[i*i] = 1; 
	D[1] = 1; 
	for(int i=2; i<=N; ++i){
		if(D[i]) continue; 
		int m = 1234567890; 
		for(int j=1; j*j<=i/2; ++j) m = min(m,D[j*j]+D[i-j*j]); 
		D[i] = m; 
	}
	
	cout<<D[N]; 
	return 0;
}
/*
1 4 9 16 25 
13 4 9  
12 1
11 2
10 3
9 4 
*/

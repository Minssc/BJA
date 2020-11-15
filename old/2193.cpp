#include<iostream>
using namespace std;

long long D[91];

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 
	
	D[1] = 1;
	D[2] = 1;
	D[3] = 2; 
	
	for(int i=3; i<=N; ++i)
		D[i] = D[i-1] + D[i-2]; 	
		
	cout<<D[N];
	
	return 0;
}

/*
	1
	1
	
	2
	10
	
	3
	100
	101
	
	4
	1000
	1001
	1010
	
	5
	10000
	10001
	10010
	10100
	10101
	
	6
	100000
	100001
	100010
	100100
	100101
	101000
	101001
	101010




*/

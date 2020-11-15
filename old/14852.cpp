#include<iostream>
using namespace std;
long long CACHE[1000001][2]; 

long long re(int n){
	CACHE[1][0] = 2;
	CACHE[2][0] = 7;
	CACHE[2][1] = 1; 
	
	for(int i=3; i<=n; ++i){
		CACHE[i][1] = (CACHE[i-1][1] + CACHE[i-3][0])%1000000007;
		CACHE[i][0] = (3*CACHE[i-2][0] + 2*CACHE[i-1][0] + 2*CACHE[i][1])%1000000007;
		
	}
	return CACHE[n][0];
	/*
	if(n == 0) return 1; 
	if(n == 1) return 2; 
	if(n == 2) return 7;
	if(CACHE[n]) return CACHE[n];
	int r = 3*re(n-2) + re(n-1)*2; 
	int i = 3; 
	while(n-i>=0){
		r+=(2*re(n-i))%1000000007;
		i++; 
	}
	return CACHE[n] = r%1000000007; 
	*/
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 
	
	cout<<re(N);//%10007;
	
	return 0;
}

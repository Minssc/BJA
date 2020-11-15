#include<iostream>
using namespace std;
int C[101][11]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int N;
	cin>>N;
	
	for(int i=1; i<=9; ++i)
		C[1][i] = 1; 
	
	for(int i=2; i<=N; ++i){
		C[i][0] = C[i-1][1]; 
		for(int j=1; j<=9; ++j) C[i][j] = (C[i-1][j-1] + C[i-1][j+1]) % 1000000000; 
	}
	
	long long sum = 0;
	for(int i=0; i<=9; ++i)
		sum += C[N][i]; 
		
	cout<< sum%1000000000; 
	
	return 0;
}
	

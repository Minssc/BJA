#include<iostream>
using namespace std;
int C[41][2]; 

void fib(int n){
	C[0][0] = 1;
	C[0][1] = 0; 
	C[1][0] = 0;
	C[1][1] = 1; 
	
	for(int i=2; i<=n; ++i){
		C[i][0] = C[i-1][0] + C[i-2][0];
		C[i][1] = C[i-1][1] + C[i-2][1];
	}	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int N, A;
	cin>>N;
	
	fib(40);
	
	for(int i=0; i<N; ++i){
		cin>>A;
		cout << C[A][0] << ' ' << C[A][1] << '\n'; 
	}
	
	return 0;
}

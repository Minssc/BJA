#include<iostream>
using namespace std;
#define R 0
#define G 1
#define B 2 
short C[1001][3];
int D[1001][3]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N; 
	cin>>N; 
	for(int i=1; i<=N; ++i)
		cin>>C[i][R]>>C[i][G]>>C[i][B]; 	
	
	D[0][R] = D[0][G] = D[0][B] = 0; 
	
	for(int i=1; i<=N; ++i){
		D[i][R] = min(D[i-1][G], D[i-1][B]) + C[i][R];
		D[i][G] = min(D[i-1][R], D[i-1][B]) + C[i][G];
		D[i][B] = min(D[i-1][R], D[i-1][G]) + C[i][B];
	}
	
	cout<< min(min(D[N][R],D[N][B]), D[N][G]) << '\n'; 
	
	return 0;
}

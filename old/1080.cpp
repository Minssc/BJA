#include<iostream>
using namespace std;

bool A[51][51];
bool B[51][51]; 
bool C[51][51]; 
int N,M;
int cnt;

void flip(int x, int y){
	for(int i=x-1; i<=x+1; ++i)
		for(int j=y-1; j<=y+1; ++j)
			C[i][j] = !C[i][j];	
	cnt++; 
}

void draw(bool b[][51]){
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			cout << b[i][j] << ' ';		
		}
		cout<<endl; 
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M;
	
	for(int i=0; i<N; ++i) 
		for(int j=0; j<M; ++j){
			char c;
			cin>>c;
			A[i][j] = c-'0';
		}	
	for(int i=0; i<N; ++i) 
		for(int j=0; j<M; ++j){
			char c;
			cin>>c;
			B[i][j] = c-'0';
		}	
		
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) C[i][j] = A[i][j] ^ B[i][j];
		
	for(int i=1; i<=M-2; ++i)
		for(int j=1; j<=N-2; ++j)
			if(C[j-1][i-1])
				flip(j,i);
		
	
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
		if(C[i][j]){
			cout<<-1;
			return 0; 	
		}
		
	cout<<cnt; 
	
	return 0;
}

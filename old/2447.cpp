#include<iostream>
using namespace std;
char ARR[2200][2200];

void re(int x, int y, int n){
	if(n==1){
		ARR[y][x] = '*';
		return;
	}
	
	int div = n/3;
	
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			if(i!=1 || j != 1)
				re(x+(i*div), y+(j*div), div);
		}
	}
	
}


int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int N;
	cin>>N;
	
	re(0,0,N); 
	
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(ARR[i][j])
				cout << ARR[i][j];
			else
				cout << ' ';
		}
		cout<<'\n'; 
	}
	
	return 0;
}

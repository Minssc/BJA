#include<iostream>

using namespace std;
int N,C[3];
int D[2200][2200]; 

int check(int y, int x, int size){
	for(int i=0; i<size; ++i)
		for(int j=0; j<size; ++j)
			if(D[y][x] != D[y+i][j+x]) return -1; 	
	
	return D[y][x]+1; 
}

void split(int y, int x, int size){
	int div = size/3; 
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			int r = check(y+i*div,x+j*div,div);
			if(r<0) split(y+i*div,x+j*div,div);
			else C[r]++; 
		}
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N; 
	int psum = 0; 
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
		cin>>D[i][j]; 
		if(D[i][j]) psum++; 
	}
	
	if(psum==N*N&&D[0][0]==-1) C[0]++;
	else if(psum==0) C[1]++;
	else if(psum==N*N&&D[0][0]==1) C[2]++; 
	
	if(!C[0]&&!C[1]&&!C[2]) split(0,0,N); 
	
	for(auto &i:C)
		cout<<i<<'\n'; 
	return 0;
}


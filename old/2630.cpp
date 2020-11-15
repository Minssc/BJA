#include<iostream>
#define pi pair<int, int>
#define F first
#define S second
using namespace std;
int D[129][129]; 
int N, W, B;

void split(int a, int b, int c, int d){
	int hlen = (c-a)/2; 
	int psum = 0; 
	for(pi p:{pi(0,0),pi(hlen,0),pi(0,hlen),pi(hlen,hlen)}){
		for(int i=p.F; i<p.F+hlen; ++i) for(int j=p.S; j<p.S+hlen; ++j) psum += D[a+i][b+j];
		if(psum==0) W++; 
		else if(psum==hlen*hlen) B++; 
		else split(a+p.F,b+p.S,a+hlen+p.F,b+hlen+p.S);  
		psum = 0; 
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin>>D[i][j]; 
	split(0,0,N,N); 
	
	cout<<W<<'\n'<<B<<'\n';
	return 0;
}


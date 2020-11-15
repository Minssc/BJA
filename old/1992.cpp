#include<iostream>
#include<string> 
#define pi pair<int, int>
#define F first
#define S second
using namespace std;
int D[65][65]; 
int N;
string ASTR; 

void split(int a, int b, int c, int d){
	int hlen = (c-a)/2; 
	int psum = 0; 
	ASTR+='('; 
	for(pi p:{pi(0,0),pi(0,hlen),pi(hlen,0),pi(hlen,hlen)}){
		psum = 0; 
		for(int i=p.F; i<p.F+hlen; ++i) for(int j=p.S; j<p.S+hlen; ++j) psum += D[a+i][b+j];
		if(psum==0) ASTR+='0'; 
		else if(psum==hlen*hlen) ASTR+='1';
		else split(a+p.F,b+p.S,a+hlen+p.F,b+hlen+p.S);  
	}
	ASTR+=')'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
		char c; cin>>c; 
		D[i][j] = c-'0'; 
	}

	int psum = 0; 
	for(int i=0;i<N;++i) for(int j=0;j<N;++j) psum+=D[i][j]; 
	if(psum==0||psum==N*N){
		if(psum) cout<<1;
		else cout<<0;
		return 0; 
	}
	
	split(0,0,N,N); 
	
	cout<<ASTR; 
	return 0;
}


#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int N; cin>>N; 
	int T = 1+(2*(N-1));
	for(int i=0; i<N; ++i){
		for(int j=0; j<N-i-1; ++j) cout<<' ';
		for(int j=0; j<1+(2*i); ++j) cout<<'*';	
		cout<<'\n'; 
	}
	
	return 0;	
}

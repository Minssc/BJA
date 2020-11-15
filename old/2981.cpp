#include<iostream>

using namespace std;
int N,M;
int D[101]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; ++i){
		cin>>D[i]; 
		M=max(M,D[i]);
	}
	
	for(int m=2; m<=M+1; ++m){
		int v=D[0]%m;
		bool flag=true;
		for(int i=1; i<N; ++i){
			if(D[i]%m!=v){
				flag=false; 
				break; 
			}
		}
		if(flag) cout<<m<<' '; 
	}
	
	return 0;
}


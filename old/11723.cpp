#include<iostream>
using namespace std;
int N,S=0; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; ++i){
		string cmd; cin>>cmd; 
		
		if(cmd=="add"){
			int v; cin>>v; 	
			S|=1<<v;
		}else if(cmd=="remove"){
			int v; cin>>v; 	
			S&=~(1<<v); 
		}else if(cmd=="check"){
			int v; cin>>v; 	
			cout<<((S>>v)&1)<<'\n'; 
		}else if(cmd=="toggle"){
			int v; cin>>v; 	
			S^=1<<v; 
		}else if(cmd=="all"){
			S=0b111111111111111111110; 
		}else if(cmd=="empty"){
			S = 0; 
		}
	}
	
	return 0;
}


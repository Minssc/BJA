#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	int N; cin>>N; 
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			if(i>j) cout<<' ';
			else cout<<'*'; 	
		cout<<'\n'; 
	}
	
	return 0;
}

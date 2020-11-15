#include<iostream>

using namespace std;
int L,P; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>L>>P; 
	for(int i=0; i<5; ++i){
		int v; cin>>v; 
		cout<<v-L*P<<' '; 	
	}
	
	return 0;
}


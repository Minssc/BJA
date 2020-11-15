#include<iostream>

using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int tc; cin>>tc; 
	for(int i=0; i<tc; ++i){
		int v; cin>>v;
		int oc=0,ec=0; 
		
		for(int k=1; k<=v; ++k){
			int pc=0;
			int ck=k;  
			while(ck>1){
				for(int j=2; j<=ck; ++j){
					if(ck%j==0){
						pc++; 
						ck/=j;
						break; 
					}
				}
			}
			if(pc%2==0) oc++;
			else ec++; 
		}
		cout<<oc<<':'<<ec<<'\n'; 
		if(oc>ec) cout<<'O'<<'\n';
		else cout<<'E'<<'\n'; 
	}
	
	return 0;
}


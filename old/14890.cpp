#include<iostream>

using namespace std;
int D[101][101]; 
int N,L; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>L;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin>>D[i][j]; 
	
	int cnt = 0; 
	for(int i=0; i<N; ++i){
		int tlen = 1; 
		int lh = D[i][0];
		bool valid = true;  
		for(int j=1; j<N; ++j){
			if(D[i][j] == lh)
				tlen++; 	
			else if(D[i][j]-lh == 1){ // 올라가  
				tlen -= L; 
				if(tlen<0){
					valid = false;
					break; 
				}
				tlen = 1; 
				lh = D[i][j]; 
			}else if(D[i][j]-lh == -1){ // 내려가  
				if(tlen<0){
					valid = false;
					break; 
				}
				tlen = -L+1; 
				lh = D[i][j]; 
				
			}else{
				valid = false;
				break; 
			}
			
		}
		if(valid && tlen>=0) cnt++; 	
		
	}

	for(int i=0; i<N; ++i){
		int tlen = 1; 
		int lh = D[0][i];
		bool valid = true;  
		for(int j=1; j<N; ++j){
			if(D[j][i] == lh)
				tlen++; 	
			else if(D[j][i]-lh == 1){ // 올라가  
				tlen -= L; 
				if(tlen<0){
					valid = false;
					break; 
				}
				tlen = 1; 
				lh = D[j][i]; 
			}else if(D[j][i]-lh == -1){ // 내려가  
				if(tlen<0){
					valid = false;
					break; 
				}
				tlen = -L+1; 
				lh = D[j][i]; 
				
			}else{
				valid = false;
				break; 
			}
			
		}
		if(valid && tlen>=0) cnt++; 
	}
		
	cout<<cnt; 
	
	return 0;
}


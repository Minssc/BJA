#include<iostream>

using namespace std;
int N,R,C;
int CNT; 

void find(int s, int r, int c){
	if(s==2){
		for(int i=0; i<=1; ++i){
			for(int j=0; j<=1; ++j){
				if(r+i==R&&c+j==C){
					cout<<CNT; 
					return;	
				}
				CNT++;
			}
		}
		return; 
	}
	
	int ns=s>>1; 
	for(int i=0; i<=1; ++i)
		for(int j=0; j<=1; ++j)
			if(r+i*ns<=R&&R<r+(i+1)*ns&&c+j*ns<=C&&C<c+(j+1)*ns) find(ns,r+i*ns,c+j*ns); 
			else CNT+=ns*ns; 
}	

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>R>>C; 
	find(1<<N,0,0); 
	
	return 0;
}


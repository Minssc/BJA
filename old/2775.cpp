#include<iostream>
using namespace std;
int ARR[15][15];

int main(){
    cin.tie(NULL), ios_base::sync_with_stdio(false);
    int T;
    for(int i=0; i<15; ++i){
    	ARR[0][i] = i; 
	}

    for(int i=0; i<15; ++i){
    	for(int j=1; j<15; ++j){
    		for(int k=0; k<=i; ++k){
    			ARR[j][i] += ARR[j-1][k]; 
    		}
    	}
	}
	
    cin>>T;
    
    for(int t=1; t<=T; ++t){
    	int K,N;
    	cin>>K>>N;
    	cout << ARR[K][N] << endl; 
    }
    
    return 0;
}

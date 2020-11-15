#include<iostream>
using namespace std;
int D[1001]; 
int DP[1001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n;cin>>n;
	for(int i=0; i<n; ++i) cin>>D[i]; 
	
	int mval = 0; 
	for(int i=0; i<n; ++i){
		DP[i] = 1; 
		for(int j=0; j<i; ++j) 
			if(D[i]<D[j] && DP[i] < DP[j]+1) DP[i] = DP[j]+1;
		
		mval = max(mval, DP[i]); 
	}
	
	cout<<mval; 
	return 0;
}

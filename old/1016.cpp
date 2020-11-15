#include<iostream>

#define ll long long 
using namespace std;
ll D[1000001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	ll minN,maxN; cin>>minN>>maxN; 
	
	for(ll i=2; i*i<=maxN; ++i){
		ll sq = i*i;
		ll quot = minN/sq;  
		if(minN%sq) quot++; 
		while(quot*sq<=maxN){
			D[quot*sq-minN]++; 
			quot++; 	
		}
	}
	
	ll cnt=maxN-minN+1;
	for(int i=0; i<maxN-minN+1; ++i)
		if(D[i]) cnt--; 
	
	cout<<cnt; 
	
	return 0;
}


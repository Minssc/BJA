#include<iostream>

#define L 7370000
using namespace std;
bool NP[L]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int k; cin>>k; 
	for(int i=2; i*i<L; ++i) for(int j=i*i; j<L; j+=i) NP[j] = 1; 
	
	int cnt=0, idx=2; 
	while(cnt<k) if(!NP[idx++]) cnt++;
	
	cout<<idx-1; 
	
	return 0;
}


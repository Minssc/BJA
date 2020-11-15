#include<iostream>

#define pii pair<int, int>
#define fi first
#define se second 
using namespace std;
int N; 
pii D[501];
int DP[501][501];  

int dp(int s, int e){
	int &ret=DP[s][e];
	if(ret) return ret; 
	if(s==e) return 0; 
	
	ret=1234567890; 
	for(int i=s; i<e; ++i) ret=min(ret,dp(s,i)+dp(i+1,e)+D[s].fi*D[i].se*D[e].second); 
	
	return ret; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N; 
	for(int i=0; i<N; ++i) cin>>D[i].fi>>D[i].se; 
	
	cout<<dp(0,N-1); 
	return 0;
}


#include<iostream>
#include<algorithm>
#include<set>

#define pi pair<int, int> 
#define fi first
#define se second 

using namespace std;
pi D[100001]; 
set<pi> T; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n; cin>>n; 
	for(int i=0; i<n; ++i) cin>>D[i].fi>>D[i].se;
	sort(D,D+n); 	
	
	int dsqr = 1234567890; 
	
	for(int i=0; i<n; ++i){
		auto lb = lower_bound(D,D+n,D[i].fi-dsqr);
		auto ub = upper_bound(D,D+n,D[i]+
	}
	
	return 0;
}


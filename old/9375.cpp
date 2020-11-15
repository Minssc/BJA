#include<iostream>
#include<unordered_map> 
#include<string>

using namespace std;

void solve(){
	unordered_map<string, int> map; 
	int n; cin>>n; 
	for(int i=0; i<n; ++i){
		string a,b; cin>>a>>b; 
		map[b]++; 
	}
	
	int ans=1; 
	for(auto &p:map) ans*=(p.second+1); 
	
	cout<<ans-1<<'\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int tc; cin>>tc; 
	for(int t=0; t<tc; ++t) 
		solve(); 
	
	return 0;
}


#include<iostream>
#include<unordered_map> 
#include<vector> 
#include<algorithm> 

#define ll long long
using namespace std;
int N; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	unordered_map<ll, int> um; 
	for(int i=0; i<N; ++i){
		long long v; cin>>v; 
		um[v]++; 	
	}
	
	vector<pair<ll,int>> vec; 
	for(auto &p:um) vec.push_back(p); 	
	
	sort(vec.begin(),vec.end(),[](const pair<ll,int> &a, const pair<ll,int> &b){
		return a.second==b.second?a.first<b.first:a.second>b.second; 
	}); 
	
	cout<<vec.front().first; 
	
	return 0;
}

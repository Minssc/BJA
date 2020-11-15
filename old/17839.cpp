#include<iostream>
#include<string> 
#include<vector>
#include<map> 
#include<set> 
#include<queue>

using namespace std;
int N; 
map<string,vector<string>> GM; 
set<string> ST; 
queue<string> Q; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N; 
	for(int i=0; i<N; ++i){
		string a,b,c; cin>>a>>b>>c; 
		auto it=GM.find(a); 
		if(it==GM.end()) GM.insert(pair<string,vector<string>>(a,{c})); 
		else it->second.push_back(c); 
	}
	
	if(GM.find("Baba")==GM.end()) return 0; 
	
	Q.push("Baba"); 
	while(!Q.empty()){
		string ns=Q.front(); Q.pop(); 
		auto it=GM.find(ns); 
		for(auto &s:it->second){
			if(ST.find(s)!=ST.end()) continue; 
			ST.insert(s);
			Q.push(s); 	
		}
	}
	
	for(auto &s:ST) cout<<s<<'\n'; 
	
	return 0;
}


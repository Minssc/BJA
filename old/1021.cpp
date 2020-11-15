#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;
deque<int> Q; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	Q.resize(n); 
	for(int i=0; i<n; ++i) Q[i]=i+1; 
	
	int cnt=0; 
	for(int i=0; i<m; ++i){
		int targ; cin>>targ;
		int idx=find(Q.begin(),Q.end(),targ)-Q.begin(), j; 
		if(idx<=Q.size()/2) 
			for(j=0; j<idx; ++j) Q.push_back(Q.front()), Q.pop_front(); 
		else
			for(j=0; j<Q.size()-idx; ++j) Q.push_front(Q.back()), Q.pop_back(); 
		
		cnt+=j; 
		Q.pop_front(); 	
	}
	
	cout<<cnt; 
	return 0;
}


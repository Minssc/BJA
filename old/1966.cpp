#include<iostream>
#include<vector>
using namespace std;

void solve(int tc){
	int N,M;	
	cin>>N>>M; 
	vector<pair<int,int>> Q; 
	for(int i=0; i<N; ++i){
		int p;
		cin>>p; 
		Q.push_back(make_pair(i,p)); 
	}
	
	int cnt = 1; 
	while(!Q.empty()){
		auto p = Q.front(); Q.erase(Q.begin()); 
		bool print = true; 
		for(auto pp:Q){
			if(pp.second > p.second){
				print = false; 
				break; 	
			}
		}
		
		if(print){
			if(p.first == M)
				break; 
			cnt++; 
		}
		else{
			Q.push_back(p); 
		}
	}
	
	cout<<cnt<<'\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	for(int i=1; i<=T; ++i)
		solve(i);
		
	return 0;
}

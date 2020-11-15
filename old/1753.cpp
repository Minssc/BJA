#include<iostream>
#include<vector>
#include<queue> 

using namespace std;
vector<pair<int, int>> D[20001]; 
int DIJ[20001]; 
int V,E,S; 

void dij(int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	pq.push(make_pair(0,start)); 
	
	while(!pq.empty()){
		auto d = pq.top(); pq.pop(); 	
		if(DIJ[d.second] && DIJ[d.second]<d.first) continue; 
		
		for(auto &p:D[d.second]){
			if(!DIJ[p.first] || DIJ[p.first] > d.first+p.second){
				DIJ[p.first] = d.first+p.second; 
				pq.push(make_pair(d.first+p.second, p.first)); 	
			}
		}
	}
}	

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>V>>E>>S; 
	
	for(int i=0; i<E; ++i){
		int a,b,c; cin>>a>>b>>c; 
		D[a].push_back(make_pair(b,c)); 
	}
	
	dij(S); 
	for(int i=1; i<=V; ++i){
		if(i==S)
			cout<<0;
		else if(DIJ[i])
			cout<<DIJ[i];
		else
			cout<<"INF";
		cout<<'\n'; 
	}
	
	return 0;
}


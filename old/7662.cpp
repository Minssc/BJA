#include<iostream>
#include<algorithm> 
#include<queue>
#include<set> 

#define pii pair<int, int> 
using namespace std;

void solve(){
	int k; cin>>k; 
	priority_queue<pii> gpq; 
	priority_queue<pii,vector<pii>,greater<pii>> lpq; 
	set<int> dels; 
	
	for(int i=0; i<k; ++i){
		char cmd; cin>>cmd;
		int v; cin>>v; 
		if(cmd=='I'){
			gpq.push({v,i});
			lpq.push({v,i}); 
		}else if(cmd=='D'){
			if(v==1){
			 	while(!gpq.empty()){
			 		auto p=gpq.top(); gpq.pop(); 
					if(dels.find(p.second)==dels.end()){
						dels.insert(p.second); 
						break; 
					}
			 	}
			}else{
				while(!lpq.empty()){
					auto p=lpq.top(); lpq.pop(); 
					if(dels.find(p.second)==dels.end()){
						dels.insert(p.second);
						break; 
					}
				}
			}
		}
	}
	
	while(!gpq.empty()){
		if(dels.find(gpq.top().second)==dels.end()) break;
		else gpq.pop(); 
	}
	while(!lpq.empty()){
		if(dels.find(lpq.top().second)==dels.end()) break;
		else lpq.pop(); 
	}	
	
	if(lpq.empty()&&gpq.empty()) cout<<"EMPTY"<<'\n'; 
	else cout<<gpq.top().first<<' '<<lpq.top().first<<'\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int tc; cin>>tc; 
	for(int t=0; t<tc; ++t)
		solve(); 
	
	return 0;
}


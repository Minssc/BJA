#include<iostream>
#include<queue>

using namespace std;
int N; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	priority_queue<int,vector<int>,greater<int>> pq;  
	for(int i=0; i<N; ++i){
		int cmd;cin>>cmd; 
		if(cmd) pq.push(cmd); 
		else{
			if(pq.empty()) cout<<0<<'\n';
			else{
				cout<<pq.top()<<'\n';
				pq.pop(); 
			}
		}
	}
	
	return 0;
}


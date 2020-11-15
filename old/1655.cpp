#include<iostream>
#include<queue>

using namespace std;
int N;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N; 
	priority_queue<int> lq;
	priority_queue<int,vector<int>,greater<int>> rq; 
	 
	for(int i=0; i<N; ++i){
		int v; cin>>v; 
		if(lq.empty()) lq.push(v); 
		else if(v<lq.top()){
			rq.push(lq.top()), lq.pop(); 
			lq.push(v); 
		}else
			rq.push(v); 
		
		if(rq.size()>lq.size()) lq.push(rq.top()), rq.pop();	
		
		cout<<lq.top()<<'\n'; 
	}
	return 0;
}


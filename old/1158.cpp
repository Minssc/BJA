#include<iostream>
#include<deque> 
using namespace std;
int N,K; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>K; 
	deque<int> Q;
	for(int i=1; i<=N; ++i) Q.push_back(i); 
	
	cout<<'<'; 
	while(!Q.empty()){
		for(int i=1; i<K; ++i){
			Q.push_back(Q.front()); Q.pop_front(); 
		}
		cout<<Q.front();
		if(Q.size()!=1) cout<<", "; 
		Q.pop_front(); 
	}
	cout<<'>'; 
	
	return 0;
}


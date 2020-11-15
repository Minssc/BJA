#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> GV;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;cin>>N;
	for(int i=0; i<N; ++i){
		int V; cin>>V;
		GV.push_back(V); 
	}
	
	sort(GV.begin(),GV.end()); 
	
	int M;cin>>M;
	for(int i=0; i<M; ++i){
		int V;cin>>V;
		if(binary_search(GV.begin(),GV.end(),V))
			cout<<1<<'\n';
		else
			cout<<0<<'\n'; 
	}
	
	return 0;
}

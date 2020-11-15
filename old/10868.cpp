#include<iostream>
#include<algorithm>
using namespace std;
int N,M; 
pair<int, int> D[100001]; 

int mine(int a, int b){
	for(int i=1; i<=N; ++i)
		if(a<=D[i].second && D[i].second<=b) return D[i].first; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=1; i<=N; ++i){
		cin>>D[i].first;	
		D[i].second = i; 
	}
	sort(D+1,D+N+1); 
	
	for(int i=0; i<M; ++i){
		int a,b; cin>>a>>b; 
		cout<<mine(a,b)<<'\n'; 	
	}
	
	return 0;
}


#include<iostream>
#include<algorithm>

using namespace std;
int N,M; 
pair<int, int> D[100001]; 

int kth(int from, int to, int k){
	int cnt = 0; 
	for(int i=1; i<=N; ++i)
		if(from <= D[i].second && D[i].second<=to)
			if(++cnt == k) return D[i].first; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=1; i<=N; ++i){ 
		cin>>D[i].first; 
		D[i].second = i; 
	}
	
	sort(D+1, D+1+N); 
	
	for(int i=0; i<M; ++i){
		int a,b,c; cin>>a>>b>>c; 
		cout<<kth(a,b,c)<<'\n'; 
	}
	return 0;
}


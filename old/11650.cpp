#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(NULL), ios_base::sync_with_stdio(false); 
	int N;
	cin>>N;	
	
	vector<pair<int, int>> V;
	for(int i=0; i<N; ++i){
		int a,b;
		cin>>a>>b;
		V.push_back(make_pair(a,b)); 	
	}
	
	sort(V.begin(), V.end()); 
	
	for(int i=0; i<N; ++i)
		cout << V[i].first << ' ' << V[i].second << '\n'; 
	
	return 0;
}

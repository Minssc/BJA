#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Compare(const pair<int, int> &a, const pair<int, int> &b){
	return (a.second == b.second ? a.first < b.first : a.second < b.second);
}

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
	
	sort(V.begin(), V.end(), Compare); 
	
	for(int i=0; i<N; ++i)
		cout << V[i].first << ' ' << V[i].second << '\n'; 
	
	return 0;
}

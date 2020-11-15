#include<iostream>
#include<vector> 
#include<string>
#include<algorithm>
using namespace std;

bool compare(const pair<int, string> &a, const pair<int, string> &b){
	return a.first < b.first; 
	
}

int main(){
	cin.tie(NULL), ios_base::sync_with_stdio(false); 
	int N;
	cin>>N;
	vector<pair<int, string>> PV;
	for(int i=0; i<N; ++i){
		int a; string b;
		cin>>a>>b;
		PV.push_back(make_pair(a,b)); 
	}
	
	stable_sort(PV.begin(),PV.end(), compare); 
	
	for(auto &p:PV)
		cout << p.first << ' ' << p.second << '\n'; 
	
	return 0;
}

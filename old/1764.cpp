#include<iostream>
#include<string>
#include<map> 
#include<vector>
#include<algorithm>
using namespace std;

map<string,int> GM; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,M;
	cin>>N>>M; 
	for(int i=0; i<N; ++i){
		string S;
		cin>>S; 
		GM.insert(make_pair(S,i)); 
	}
	
	vector<string> SV; 
	for(int i=0; i<M; ++i){
		string S;
		cin>>S; 
		if(GM.find(S) != GM.end())
			SV.push_back(S); 
	}
	
	sort(SV.begin(),SV.end()); 
	
	cout<<SV.size()<<'\n'; 
	for(auto s:SV)
		cout << s << '\n'; 
	return 0;
}

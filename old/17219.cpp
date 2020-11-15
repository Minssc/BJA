#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string, string> UM;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,M; cin>>N>>M; 
	for(int i=0; i<N; ++i){
		string site, pw; cin>>site>>pw;
		UM[site] = pw; 
	}
	for(int i=0; i<M; ++i){
		string site; cin>>site; 
		cout<<UM[site]<<'\n';  	
	}
	
	return 0;
}

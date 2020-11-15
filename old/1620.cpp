#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int N,M;
unordered_map<string,int> PM;
string S[100001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M;
	for(int i=1; i<=N; ++i){
		string s; cin>>s;
		PM.insert(make_pair(s,i)); 
		S[i] = s; 
	}
	for(int i=1; i<=M; ++i){
		string s; cin>>s; 
		int idx = 0;
		try{
			idx = stoi(s); 
		}catch(exception e){}
		
		if(!idx)
			cout<<PM.find(s)->second<<'\n';
		else
			cout<<S[idx]<<'\n'; 
	}
	return 0;
}

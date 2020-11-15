#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const string &a, const string &b){
	if(a.size() == b.size()){
		int ac = 0, bc = 0;
		for(auto &c:a)
			if('0' <= c && c <= '9')
				ac+=c-'0';	
		
		for(auto &c:b)
			if('0' <= c && c<= '9')
				bc+=c-'0'; 
				
		return (ac == bc ? a<b : ac < bc); 
	}
	
	return a.size() < b.size(); 	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 	
	
	vector<string> SV; 
	
	for(int i=0; i<N; ++i){
		string s;
		cin>>s; 
		SV.push_back(s); 
	}
	
	sort(SV.begin(),SV.end(),compare);
	
	for(auto &s:SV)
		cout << s << '\n'; 
	
	return 0;
}

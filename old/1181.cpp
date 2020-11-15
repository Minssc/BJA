#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std;

bool compare(const string &a, const string &b){
	return (a.size() == b.size() ? (a.compare(b) > 0 ? false : true) : a.size() < b.size()); 
}

int main(){
	cin.tie(NULL), ios_base::sync_with_stdio(false); 
	int N; 
	cin>>N;
	vector<string> SV; 
	string s;
	
	for(int i=0; i<N; ++i){
		cin>>s;
		if(find(SV.begin(), SV.end(), s) == SV.end())
			SV.push_back(s); 	
	}
	
	sort(SV.begin(),SV.end(), compare);
	
	for(auto &s:SV)
		cout << s << '\n'; 
		
	
	return 0;
}

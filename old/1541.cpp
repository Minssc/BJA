#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> splitString(string s, char c){
	vector<string> SV;
	int idx;
	while((idx = s.find(c)) != string::npos){
		SV.push_back(s.substr(0,idx));
		s = s.substr(idx+1, s.size()); 	
	}
	SV.push_back(s); 
	
	return SV; 	
}

int addString(string s){
	vector<string> SV = splitString(s, '+'); 
	int sum = 0; 
	for(auto s:SV)
		sum += stoi(s); 
	return sum; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string S;
	cin>>S; 
	int sum = 0; 
	vector<string> SV;
	
	SV = splitString(S, '-'); 
	sum = addString(SV.front()); 
	SV.erase(SV.begin()); 
	
	for(auto s:SV)
		sum -= addString(s); 
	
	cout<<sum;
	
	return 0;
}

/*
55-50+40-10
55 -90 -10 

*/

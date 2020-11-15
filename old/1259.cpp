#include<iostream>
#include<string>
using namespace std;

bool isPal(string &s){
	for(int i=0; i<=s.size()/2; ++i)
		if(s[i] != s[s.size()-1-i])
			return false; 
	return true; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string S; 
	while(true){
		cin>>S;
		if(S=="0") break; 
		if(isPal(S))
			cout<<"yes";
		else
			cout<<"no";
		cout<<'\n'; 
	}
	return 0;
}

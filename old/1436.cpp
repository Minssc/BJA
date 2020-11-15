#include<iostream>
#include<string>
using namespace std;

bool isCursed(int n){
	string s = to_string(n); 
	
	for(int i=0; i<s.size()-2; ++i){
		if(s[i] != '6') continue;
		if(s[i] == s[i+1] && s[i+1] == s[i+2])
			return true; 
	}
	return false; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 
	int le666 = 666; 
	int n666 = le666; 
	int c = 1; 
	
	while(c < N){
		n666++; 
		
		if(isCursed(n666)){
			c++;
			le666 = n666; 
		}
	}
		
	cout << le666; 
	
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

int hash(string &s){
	unsigned long long r = 1; 
	unsigned long long result = 0; 
	for(auto &c:s){
		result += (c-'a'+1) * r, result%=1234567891;
		r*=31, r%=1234567891;
	}
	return result; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N; cin>>N;
	string S; cin>>S; 
	cout<<::hash(S)<<'\n'; 
	return 0;
}

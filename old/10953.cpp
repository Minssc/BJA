#include<iostream>
#include<string>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T;cin>>T;
	for(int t=0; t<T; ++t){
		string S; cin>>S; 
		int A,B;
		auto it = S.find(","); 
		A = stoi(S.substr(0,it));
		B = stoi(S.substr(it+1,S.size())); 
		cout<<A+B<<'\n'; 
	}
	
	return 0;
}

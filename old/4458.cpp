#include<iostream>
#include<string>
#include<algorithm> 

using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n; cin>>n; cin.ignore(); 
	for(int i=0; i<n; ++i){
		string s; getline(cin,s); 
		s[0]=toupper(s[0]); 
		cout<<s<<'\n'; 	
	}
	
	return 0;
}


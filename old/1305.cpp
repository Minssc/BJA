#include<iostream>
#include<string> 
using namespace std;
int pi[1000001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int l; cin>>l; 
	string s; cin>>s; 
	for(int i=1,j=0; i<l; ++i){
		while(j>0&&s[i]!=s[j]) j = pi[j]; 
		if(s[i]==s[j]) pi[i] = ++j; 	
	}
	
	cout<<l-pi[l-1]; 
	
	return 0;
}


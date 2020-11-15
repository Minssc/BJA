#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int pi[5001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string s; cin>>s; 
	int maxv = 0; 
	for(int si=0, sn = s.size(); si<sn; ++si){
		for(int i=1,j=0; i<sn; ++i){
			while(j>0&&s[i]!=s[j]) j=pi[j-1]; 
			if(s[i]==s[j]) pi[i] = ++j; 
			maxv = max(maxv,pi[i]); 
		}
		s.erase(s.begin()); 
		memset(pi,0,sizeof(int)*s.size()); 
	}
	
	cout<<maxv; 
	return 0;
}


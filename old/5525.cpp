#include<iostream>
#include<string> 

using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m; 
	string s; cin>>s; 
	int ans=0; 
	for(int cur=0; cur<s.size(); ++cur){
		if(s[cur+1]=='O'&&s[cur+2]=='I'){
			int cnt=0; 
			while(s[cur]=='I'&&s[cur+1]=='O'){
				cur+=2, cnt++; 
				if(s[cur]=='I'&&cnt==n) cnt--, ans++; 	
			}
		}
	}
	
	cout<<ans; 
	
	return 0;
}


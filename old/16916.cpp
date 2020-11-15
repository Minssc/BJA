#include<iostream>
#include<string>

using namespace std;
int pi[1000001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string t,p; cin>>t>>p; 
	for(int i=1,j=0,pn=p.size(); i<pn; ++i){
		while(j>0&&p[i]!=p[j]) j=pi[j-1]; 
		if(p[i]==p[j]) pi[i] = ++j; 	
	}
	
	for(int i=0,j=0,tn=t.size(),pn=p.size(); i<tn; ++i){
		while(j>0&&t[i]!=p[j]) j=pi[j-1]; 
		if(t[i]==p[j]){
			if(j==pn-1){
				cout<<1;
				return 0; 
			}else
				++j; 
		}
	}
	
	cout<<0; 
	return 0;
}


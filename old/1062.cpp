#include<iostream>
#include<string>

using namespace std;
int N,K,MAXV; 
string W[51]; 
bool V[26];

void dfs(int a, int c){
	if(c==K){
		int cnt=0; 
		for(int i=0; i<N; ++i){
			auto &w=W[i]; 
			if([&w](){
				for(auto &ch:w)
					if(!V[ch-'a'])
						return false; 
				return true; 
			}()) cnt++; 
		}
		MAXV = max(MAXV,cnt); 
	}else{
		for(int i=a; i<26; ++i){
			if(V[i]) continue; 
			V[i]=1;
			dfs(i,c+1); 
			V[i]=0; 
		}
	}	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>K; 
	if(K<5){
		cout<<0;
		return 0; 
	}else if(K==26){
		cout<<N;
		return 0; 	
	}
	
	V[0] = V['c'-'a'] = V['n'-'a'] = V['t'-'a'] = V['i'-'a'] = 1; 
	K-=5; 
	for(int i=0; i<N; ++i){
		string s; cin>>s; 
		s=s.substr(4,s.size()-8); 
		W[i]=s; 
	}
	
	dfs(0,0); 
	cout<<MAXV;
	
	return 0;
}


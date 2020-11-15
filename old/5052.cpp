#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;
string D[10001]; 

int hashs(string s){
	int result = 0;
	int m = 1; 
	for(auto &c:s){
		result += c*m; result %= 1234567891;
		m *= 31; m %= 1234567891; 
	}
	return result; 
}

void solve(){
	unordered_set<int> hashes[11]; 
	int n; cin>>n; 
	for(int i=0; i<n; ++i){	 
		cin>>D[i]; 
		hashes[D[i].size()].insert(hashs(D[i])); 
	}
	
	sort(D,D+n); 

	for(int i=0; i<n; ++i){
		string &s = D[i]; 
		for(int j=1; j<s.size(); ++j){
			if(!hashes[j].size()) continue; 
			int hv = hashs(s.substr(0,j)); 
			if(hashes[j].find(hv) != hashes[j].end()){
				cout<<"NO"<<'\n'; 
				return;	
			}
//			for(auto &h:hashes[j]){
//				if(hv == h){
//					cout<<"NO"<<'\n'; 
//					return; 
//				}
//			}
		}
	}
	cout<<"YES"<<'\n'; 
}

int main(){
	freopen("input/5052.txt","r",stdin); 
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T; cin>>T; 
	for(int t=0; t<T; ++t)
		solve(); 
	
	return 0;
}


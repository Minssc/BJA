#include<iostream>
#include<string>
#include<list>

using namespace std;
list<char> L; 
string S; 
int N; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>S>>N;
	for(auto &c:S) L.push_back(c); 
	auto it = L.end(); 
	
	for(int i=0; i<N; ++i){
		char cmd; cin>>cmd; 
		if(cmd=='L'&&it!=L.begin()) it--; 
		else if(cmd=='D'&&it!=L.end()) it++;
		else if(cmd=='B'&&it!=L.begin()) it = L.erase(--it); 
		else if(cmd=='P'){
			char ch; cin>>ch; 
			L.insert(it,ch); 
		}
		
	}
	
	for(auto &c:L)
		cout<<c; 
	return 0;
}


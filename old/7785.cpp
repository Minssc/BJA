#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(){
	freopen("input/7785.txt","r",stdin); 
	cin.tie(0), ios_base::sync_with_stdio(0);
	set<string, greater<string>> M;
	int N;
	cin>>N;
	for(int i=0; i<N; ++i){ 
		string S,B;
		cin>>S>>B; 
		if(B=="enter") M.insert(S);
		else M.erase(S); 
	}
	
	for(auto i=M.begin(); i!=M.end(); ++i)
		cout << *i << '\n'; 
	
	return 0;
}

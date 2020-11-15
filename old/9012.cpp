#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T; cin>>T;
	for(int t=0; t<T; ++t){
		string S; cin>>S; 
		stack<char> ST; 
		
		for(auto &c:S){
			if(c=='(')
				ST.push(c); 
			else{
				if(ST.empty()){
//					cout<<"NO"<<'\n'; 
					ST.push(c); 
					break; 
				}else
					ST.pop(); 
			}
		}
		
		if(ST.empty())
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n'; 
	
	}
	
	return 0;
}
	

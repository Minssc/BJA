#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string S;
	stack<char> ST; 
	
	while(true){
		getline(cin, S); 
		if(S==".") break; 
		for(auto &c:S){
			if(c=='(' || c=='['){
				ST.push(c); 	
			}else if(c==')' || c==']'){	
				if(ST.empty()){
					ST.push('0'); 
					break; 	
				}else{
					if(ST.top() != c-1 && ST.top() != c-2){
						break; 
					}else
						ST.pop(); 	
					
				}
			}
		}
		if(!ST.empty()){
			cout<<"no"<<'\n'; 
			while(!ST.empty()) ST.pop(); 
			continue;	
		}
		cout<<"yes"<<'\n'; 
	}
	
	return 0;
}

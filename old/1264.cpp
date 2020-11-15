#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string s; 
	char needle[]={'a','e','i','o','u'};
	while(true){
		getline(cin,s); 
		if(s=="#") break; 
		
		int cnt=0; 
		for(auto &c:s)
			for(auto &nc:needle)
				if(nc==tolower(c)) cnt++;	
			
		cout<<cnt<<endl; 
	}
	
	return 0;
}


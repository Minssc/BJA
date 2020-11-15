#include<iostream>
#include<algorithm> 
#include<string>

using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string n; cin>>n; 
	sort(n.begin(),n.end(),greater<char>()); 
	cout<<n; 
	
	return 0;
}


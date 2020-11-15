#include<iostream>

using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n; cin>>n; 
	int a,b,c; 
	for(int i=0; i<n-3; ++i) cin>>a; 
	cin>>a>>b>>c; 
	if((b-a)==(c-b)) cout<<c+(b-a);
	else cout<<c*(b/a); 
	
	return 0;
}


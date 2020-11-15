#include<iostream>

using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n; cin>>n; 
	unsigned long long int v=1; 
	int zcnt = 0; 
	for(int i=1; i<=n; ++i){
		v*=i;  
		while((v%10)==0) v/=10,zcnt++; 
		v%=1000; 
	}
	
	cout<<zcnt; 
	return 0;
}


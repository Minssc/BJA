#include<iostream>

using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n,m;cin>>n>>m;
	for(int i=1; i<=n*m; ++i){
		cout<<i;
		if(i%m) cout<<' '; 	
		else cout<<'\n';
	}
	
	return 0;
}


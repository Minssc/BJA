#include<iostream>
using namespace std;

int mpow(int a, int b){
	if(b==1) return a; 
	return mpow(a,b/2)%10 * mpow(a,b/2)%10 * (b&1?a:1)%10; 
}

void solve(){
	int a,b; cin>>a>>b;
	int r = mpow(a%10,b); 
	cout<<(r?r:10)<<'\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T; cin>>T; 
	for(int t=0; t<T; ++t)
		solve();
	
	return 0;
}
	

#include<iostream>

using namespace std;

void solve(){
	int m,n,x,y; cin>>m>>n>>x>>y; 
	
	while(true){
		if(x>n*m) break; 
		if((x-1)%n+1==y){
			cout<<x<<'\n'; 
			return;	
		}
		x+=m;
	}
	
	cout<<-1<<'\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int tc; cin>>tc; 
	for(int t=0; t<tc; ++t)
		solve(); 
	
	return 0;
}


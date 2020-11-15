#include<iostream>

using namespace std;
bool notP[1000001]; 

void solve(int &n){
	for(int i=n-1; i>=2; --i){
		if(notP[i]) continue; 
		if(!notP[n-i]){
			cout<<n<<" = "<<n-i<<" + "<<i<<'\n'; 
			return;	
		}
	}
	cout<<"Goldbach's conjecture is wrong."; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	notP[1]=1; 
	for(int i=2; i<1000; ++i) 
		for(int j=2; i*j<=1000000; ++j)
			notP[i*j]=1; 
	
	int n;
	while(true){
		int n; cin>>n; 
		if(!n) break;
		solve(n); 
	}
	
	return 0;
}


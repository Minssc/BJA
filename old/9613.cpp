#include<iostream>

using namespace std;
int D[101]; 

void solve(){
	int n; cin>>n;
	for(int i=0; i<n; ++i) cin>>D[i]; 
	
	unsigned long long sum=0; 
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j){
			int a=D[j],b=D[i],n; 
			while(b){
				n=a%b;
				a=b;
				b=n; 
			}
			sum+=a; 
		}
	}
	
	cout<<sum<<'\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int tc; cin>>tc; 
	for(int t=0; t<tc; ++t)
		solve(); 
	
	return 0;
}


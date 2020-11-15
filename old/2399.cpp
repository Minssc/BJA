#include<iostream>

using namespace std;
int D[10001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=0; i<n; ++i) cin>>D[i]; 
	
	unsigned long long sum=0; 
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			if(i!=j) sum+=abs(D[i]-D[j]);	
				
	cout<<sum; 
	return 0;
}


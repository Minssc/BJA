#include<iostream>
#include<vector>

using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<int> V; 
	for(int i=0; i<n; ++i){
		int a; cin>>a; 
		
		auto it = lower_bound(V.begin(),V.end(),a); 
		if(it==V.end()) V.push_back(a); 
		else if(*it>a) *it=a; 
	}
	
	cout<<V.size(); 
	
	return 0;
}


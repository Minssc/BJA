#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> 
#include<set> 
using namespace std;
int D[51]; 
bool notPrime[1001]; 
set<int> BL; 

bool doPair(){
	
	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N; cin>>N; 
	vector<int> V; 
	
	notPrime[1] = 1; 
	for(int i=2; i<=1000; ++i)
		for(int j=2; j*i<=1000; ++j)
			notPrime[i*j] = 1; 
	
	for(int i=0; i<N; ++i){ 
		cin>>D[i]; 
		if(i != 0 && !notPrime[D[0]+D[i]]) V.push_back(D[i]); 
	}
	
	for(auto it=V.begin(); it!=v.end();){
		BL.insert(*it); 
		if(!doPair())
			V.erase(it); 
		else
			it++; 	
		BL.erase(*it); 
	}
	
	sort(V.begin(),V.end()); 
	for(auto &i:V)
		cout<<i<<' '; 
	cout<<'\n'; 
	
	return 0;
}
/*
1 2 3 4 5 6 7 8
13 14 16 18
2 5
4 5

*/

#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> D; 
int N,L; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>L;
	D = vector<int>(N,vector<int>(N)); 
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin>>D[i][j]; 
	
	
	return 0;
}


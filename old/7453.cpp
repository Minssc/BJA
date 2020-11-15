#include<iostream>
#include<vector> 
#include<algorithm> 

using namespace std;
int N; 
vector<vector<int>> D; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N; 
	D.resize(4,vector<int>(N)); 
	for(int i=0; i<N; ++i) for(int j=0; j<4; ++j) cin>>D[j][i]; 
	
	vector<int> psv(N*N);
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) psv[N*i+j]= -(D[2][i]+D[3][j]); 
	sort(psv.begin(),psv.end()); 
	
	unsigned long long cnt=0; 
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			auto r=equal_range(psv.begin(),psv.end(),D[0][i]+D[1][j]); 
			cnt+=r.second-r.first;
		}
	}
	
	cout<<cnt; 
	return 0;
}


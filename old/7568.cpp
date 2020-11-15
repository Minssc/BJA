#include<iostream>
#include<vector>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N;
	
	vector<pair<int, int>> PV; 
	for(int i=0; i<N; ++i){
		int x,y;
		cin>>x>>y; 
		PV.push_back(make_pair(x, y));
	}
	
	for(int i=0; i<N; ++i){
		int c = 0; 
		auto &A = PV[i];
		for(int j=0; j<N; ++j){
			if(i==j)
				continue; 
			auto &B = PV[j];
			if(B.first > A.first && B.second > A.second)
				c++;
		}
		
		cout << c + 1 << ' ';
	}
		
	return 0;
}

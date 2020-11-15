#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int> C[100001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int N; 
	cin>>N; 
	
	for(int i=0; i<N; ++i)
		cin>>C[i].first>>C[i].second; 
		
		
	sort(C,C+N, [](const pair<int,int> &a, const pair<int, int> &b){
		return (a.second == b.second ? a.first < b.first : a.second < b.second); 
	}); 
	
	int end = 0; 
	int cnt = 0;
	for(int i=0; i<N; ++i){
		if(end<=C[i].first){
			cnt++;
			end = C[i].second;
		}
	}
		
	cout<<cnt; 
	
	return 0;
}

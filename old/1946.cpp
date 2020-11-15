#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int> D[100001]; 

void solve(int tc){
	int N; 
	cin>>N;
	for(int i=0; i<N; ++i)
		cin>>D[i].first>>D[i].second; 
	
	sort(D,D+N);
	
	int max = N; 
	int cmin = 1234567890;
	for(int i=0; i<N; ++i){
		if(D[i].second < cmin)
			cmin = D[i].second; 
		if(D[i].second > cmin)
			max--; 
	}
	
	cout << max << '\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T;
	cin>>T; 
	
	for(int t=1; t<=T; ++t)
		solve(t);	
	
	return 0;
}

/*
1 4 
2 3
3 2
4 1
5 5 

1 4
2 5
3 6
4 2
5 7
6 1
7 3


*/

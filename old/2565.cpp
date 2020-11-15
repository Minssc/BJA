#include<iostream>
#include<algorithm>
using namespace std;

pair<short, short> E[101];
short D[101]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 
	for(int i=1; i<=N; ++i)
		cin>>E[i].first>>E[i].second;
	
	sort(E, E+N+1); 
	
	D[1] = 1;
	int max = -1234567890;
	for(int i=2; i<=N; ++i){
		D[i] = 1; 
		for(int j=1; j<=N; ++j){
			if(E[j].second < E[i].second && D[i] <= D[j])
				D[i] = D[j]+1;
			max = D[i] > max ? D[i] : max; 
		}
	}
	
	cout << N-max; 
	
	return 0;
}

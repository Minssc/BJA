#include<iostream>
#include<algorithm>
using namespace std;
int P[1001];

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N; 
	cin>>N; 
	for(int i=1; i<=N; ++i)
		cin>>P[i]; 
	
	sort(P, P+N+1); 

	int minTime = 0; 
	
	for(int i=1; i<=N; ++i)
		for(int j=1; j<=i; ++j)
			minTime += P[j]; 
	
	cout << minTime; 
	
	return 0;
}

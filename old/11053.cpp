#include<iostream>
using namespace std;

short A[1001];
short D[1001];

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N;
	for(int i=1; i<=N; ++i)
		cin>>A[i];
	
	D[1] = 1; 
		
	for(int i=1; i<=N; ++i){
		D[i] = 1; 
		for(int j=1; j<i; ++j){
			if(A[j] < A[i] && D[i] <= D[j]){
				D[i] = D[j]+1; 	
			}else if(A[j] == A[i]){
				D[i] = D[j];	
			}
		}
		
	}
	
	int max = D[1];
	for(int i=2; i<=N; ++i)
		if(max < D[i])
			max = D[i];
	cout<<max;
	
	return 0;
}
	
	

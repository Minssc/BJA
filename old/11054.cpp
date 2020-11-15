#include<iostream>
//#include<cstring>
using namespace std;
short A[1001];
short DU[1001]; 
short DD[1001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N;
	for(int i=1; i<=N; ++i)
		cin>>A[i];	
	
	//memset(DU, 1, sizeof(DU)); 
	//memset(DD, 1, sizeof(DD)); 
	DU[1] = DD[N] = 1; 
	
	for(int i=2; i<=N; ++i){	
		DU[i] = 1; 	
		for(int j=1; j<i; ++j){
			if(A[j] < A[i] && DU[i] <= DU[j]){
				DU[i] = DU[j]+1;
			}
			else if(A[j] == A[i]){
				DU[i] = DU[j];
			}
		}
	}
	
	for(int i=N-1; i>=1; --i){
		DD[i] = 1; 
		for(int j=N; j>i; --j){
			if(A[j] < A[i] && DD[i] <= DD[j]){
				DD[i] = DD[j]+1;
			}
			else if(A[j] == A[i]){
				DD[i] = DD[j];
			}
		}
	}
	
	int max = 0; 
	for(int i=1; i<=N; ++i){
		if(DU[i]+DD[i] > max)
			max = DU[i]+DD[i]; 	
	}
	
	cout<<max-1;
	
	return 0;
}

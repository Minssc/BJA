#include<iostream>
#include<algorithm>
using namespace std;
int A[5000001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,K;
	cin>>N>>K; 	
	for(int i=0; i<N; ++i)
		cin>>A[i];
//	sort(A,A+N);
	nth_element(A,A+K-1,A+N);
	
	cout<<A[K-1];
	
	return 0;
}

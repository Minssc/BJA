#include<iostream>
using namespace std;

int ARR[10001];

int main(){
	cin.tie(NULL), ios_base::sync_with_stdio(false); 
	int N,A;
	cin>>N;
	
	for(int i=0; i<N; ++i){
		cin>>A;
		ARR[A]++; 
	}
	
	for(int i=1; i<10001; ++i)
		for(int j=0; j<ARR[i]; ++j)
			cout << i << '\n';	
		
	
	return 0; 	
}

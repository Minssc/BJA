#include<iostream>
#include<algorithm>
using namespace std;

int W[100001]; 
/*
15 10 2
25/2
*/
int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 
	for(int i=0; i<N; ++i)
		cin>>W[i]; 
		
	sort(W, W+N); 
	
	int max = 0; 
	for(int i=0; i<N; ++i){
		if(W[i]*(N-i) > max)
			max = W[i]*(N-i);
	}
	
	cout<<max; 
	
	return 0;
}

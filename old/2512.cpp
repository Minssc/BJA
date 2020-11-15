#include<iostream>
using namespace std;
int N,M;
int D[10001]; 

int test(int m){
	long long sum=0;
	for(int i=0; i<N; ++i) sum += (m<D[i]?m:D[i]);
	if(sum>M) return 1;
	else if(sum<M) return -1;	
	else return 0; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	int start = 0;
	for(int i=0; i<N; ++i){
		cin>>D[i];
		if(D[i]>start) start = D[i];  
	}
	cin>>M; 
	int end = 0;
	int middle;
	
	while(start+1>end){
		middle = (start+end)/2; 
		int result = test(middle);
		
		switch(result){
			case 1:
				start = middle-1; 
				break;	
			case -1:
				end = middle+1;
				break;
			case 0:
				cout<<middle;
				return 0;
		}
		
	}
	cout<<start;
	return 0;
}

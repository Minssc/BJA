#include<iostream>
using namespace std;

int CARD[101];

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 	
	int N,M; 
	cin>>N>>M;
	for(int i=0; i<N; ++i) cin>>CARD[i]; 
	int result = 0; 
	
	for(int i=0; i<N-2; ++i) for(int j=i+1; j<N-1; ++j) for(int k=j+1; k<N; ++k){
		int sum = CARD[i]+CARD[j]+CARD[k];
		
		if(sum <= M && sum > result)
			result = sum;
	}
				
	cout<<result;
	return 0;
}


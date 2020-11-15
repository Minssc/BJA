#include<iostream>
using namespace std;
int D[1001]; 
int C[1001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N; cin>>N;
	for(int i=0; i<N; ++i) cin>>D[i]; 
	vector<int> V;
	int mlen = 0; 
	
	for(int i=0; i<N; ++i){
		C[i] = D[i];
		for(int j=0; j<=i; ++j)
			if(D[i]>D[j] && C[i] < C[j]+D[i])
				C[i] = C[j]+D[i];	
		
		mlen = max(mlen, C[i]); 
	}
	cout<<mlen;
	return 0;
}

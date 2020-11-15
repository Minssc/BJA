#include<iostream>
using namespace std;
short C[1000001];  

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 
	
	C[0] = 0;
	C[1] = 0;
	for(int i=2; i<=N; ++i){
		int min = C[i-1]+1; 
		//C[i] = min(min(C[i/3]+1, C[i/2]+1), C[i-1]+1); 
		if((i%3==0) && (C[i/3] + 1 < min))
			min = C[i/3]+1;
		if((i%2==0) && (C[i/2] + 1 < min))
			min = C[i/2]+1;
		
		C[i] = min; 
	}
		
	cout << C[N]; 
	
	return 0;
}

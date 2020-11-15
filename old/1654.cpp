#include<iostream>
using namespace std;
int K,N;
int D[10001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	cin>>K>>N; 
	unsigned long long T=0;
	for(int i=0; i<K; ++i){
		cin>>D[i]; 
		T+=D[i]; 	
	}
	T/=N;
	long long CNT = 0; 
	pair<int, int> p = {0,0}; 
	 
	while(CNT < N){
		CNT = 0; p.first = 0; 
		int NT = 0; 
		for(int i=0; i<K; ++i){
//		cout<<i<<": " <<D[i]<<" " << D[i]/T << " " << T <<'\n'; 
//			if(D[i]%T>p.first)
//				p = {D[i]%T, i}; 
//			if(D[i]/(D[i]/T+1) > p.first)
//				p = {D[i]/(D[i]/T+1),i};
			if(D[i]/(D[i]/T+1) > NT)
				NT = D[i]/(D[i]/T+1);
			CNT += D[i]/T; 	
		}
//		cout<<"CNT: " << CNT<<'\n'; 
		if(CNT>=N)
			break; 
//		T = D[p.second]/(D[p.second]/T+1);
		T = NT;  
	}
	
	cout<<T<<'\n'; 
		
	return 0;
}

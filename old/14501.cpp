#include<iostream>
using namespace std;

int T[20];
int P[20];
int D[20]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N;
	for(int i=1; i<=N; ++i)
		cin>>T[i]>>P[i]; 
		
	int max = 0;
	
	for(int i=N; i>0; --i){
		if(i+T[i] > N + 1) continue; 
		//if(T[i+T[i]] <= N+1)
		//	D[i] += D[i+T[i]]; 	
		int md = 0; 
		for(int j=i+T[i]; j<=N; ++j)
			if(D[j]>md)
				md = D[j]; 
		
		D[i] += P[i]+md; 
		if(D[i] > max)
			max = D[i]; 
	}
	
	/*
	for(int i=1; i<=N; ++i){
		if(i+T[i] > N+1) continue; 
		D[i] = P[i]; 	
		for(int j=i+T[i]; j<=N; ){
			if(j+T[j] > N+1) {
				j++;
				continue;
			}
			D[i] += P[j];  
			j+=T[j]; 
		}
		if(max<D[i])
			max = D[i]; 			
	}
	*/
	
	//for(int i=1; i<=N; ++i)
	//	cout << D[i] << ' '; 
	
	cout<<max; 
	
	return 0;
}

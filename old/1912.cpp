#include<iostream>
using namespace std;

short GA[100001];
int D[100001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 
	for(int i=1; i<=N; ++i)
		cin>>GA[i]; 
		
	int M=-1234567890; 
	
	for(int i=1; i<=N; ++i){
		if(D[i-1]+GA[i] < GA[i]){
			D[i] = GA[i]; 
		}
		else{
			D[i] = D[i-1]+GA[i]; 
		}
		if(D[i]>M)
			M = D[i]; 
	}
	cout<<M;
	
	return 0;
}

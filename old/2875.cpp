#include<iostream>
using namespace std;
int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	int N,M,K;
	cin>>N>>M>>K; 
	
	while(K > 0){
		if(M*2>N){
			M--;
			K--; 
		}else{
			N--;
			K--; 	
		}
	}
	
	if(M*2<=N)
		cout << M;
		
	else
		cout << N/2;
		
	
	
	return 0;
}

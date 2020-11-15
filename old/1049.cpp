#include<iostream>
#include<math.h>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,M;
	cin>>N>>M; 
	
	int minh = 1001, mins = 1001; 
	for(int i=0; i<M; ++i){
		int h,s;
		cin>>h>>s; 
		minh = min(minh,h);
		mins = min(mins,s); 
	}
	
	int cost = 0; 
	
	if(minh<6*mins){
		cost += N/6*minh, N%=6;
		cost += min(minh, N*mins); 
	}else{
		cost = N*mins;	
	}
	
	cout<<cost; 
	
	return 0;
}

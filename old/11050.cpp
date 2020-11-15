#include<iostream>
using namespace std;
int N,K;
int bin(int a, int b){
	if(b==0||a==b) return 1; 
	return bin(a-1,b)+bin(a-1,b-1); 	
}

int main(){
	cin>>N>>K; 
	cout<<bin(N,K);	
	
	return 0;
}

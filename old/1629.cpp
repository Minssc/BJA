#include<iostream>
#include<cmath>
using namespace std;
unsigned long long A,B,C;

unsigned long long bpow(int N){
	if(N==1) return A;
	return bpow(N/2)%C*bpow(N/2)%C*(N&1?A:1)%C;//%C; 
}

int main(){
	cin>>A>>B>>C; A%=C; 
	cout<<bpow(B); 
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10 
  2   4       8     
  

*/

#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(a%b==0)
		return min(a,b);
	return gcd(b,a%b); 
}

int main(){
	int A,B; cin>>A>>B;
	int GCD = gcd(A,B);
	cout<<GCD<<'\n';
	cout<<(A*B)/GCD<<'\n';
	
	return 0;	
}

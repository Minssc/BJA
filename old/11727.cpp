#include<iostream>
using namespace std;
int CACHE[31]; 

int re(int n){
	if(n%2!=0) return 0; 
	if(n == 0) return 1; 
	if(n == 2) return 3; 
	if(CACHE[n]) return CACHE[n];
	int r = CACHE[n] = 3*re(n-2);
	int a = n-4;
	
	while(a>=0){ 
		r+=2 * re(a);
		a-=2; 	
	}
	return CACHE[n] = r; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 
	
	
	cout<<re(N);//%10007;
	
	return 0;
}

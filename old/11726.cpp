#include<iostream>
using namespace std;
int CACHE[1001]; 

int re(int n){
	if(n == 1) return 1; 
	if(n == 2) return 2;
	if(CACHE[n]) return CACHE[n];
	return CACHE[n] = (re(n-1)+re(n-2))%10007;
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;
	cin>>N; 
	
	cout<<re(N);//%10007;
	
	return 0;
}

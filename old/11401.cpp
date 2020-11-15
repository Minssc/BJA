#include<iostream>
#define ull unsigned long long
#define MOD 1000000007
using namespace std;
int N,K; 
ull F[4000001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>K; 
	F[0] = F[1] = 1; 
	for(int i=2; i<=N; ++i) F[i] = (F[i-1]*i)%MOD; 
	ull den = (F[K]*F[N-K])%MOD; 
	
	ull idx = MOD-2; 
	ull fNum = 1; 
	while(idx>0){
		if(idx&1) fNum *= den,fNum%=MOD; 	
		den = (den*den)%MOD;
		idx/=2; 
	}
	
	cout<<(F[N]*fNum)%MOD; 
	
	return 0;
}


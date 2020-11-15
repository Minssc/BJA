#include<iostream>
#include<set> 
using namespace std;
int P[1000001]; 

int getP(int a){
	if(P[a] == a) return a; 
	return P[a] = getP(P[a]);	
}

void unionP(int a, int b){
	a = getP(a);
	b = getP(b);
	if(a<b) P[b] = a;
	else P[a] = b; 
}

int findP(int a, int b){
	a = getP(a);
	b = getP(b);
	if(a==b) return 1;
	else return 0; 	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int n,m; cin>>n>>m; 
	for(int i=0; i<=n; ++i) P[i] = i; 
	
	for(int j=0; j<m; ++j){
		int cmd,v1,v2; cin>>cmd>>v1>>v2; 
		if(cmd){
			if(findP(v1,v2))
				cout<<"YES"<<'\n';
			else
				cout<<"NO"<<'\n'; 
		}else
			if(v1!=v2) unionP(v1,v2); 
	}
	
	return 0;
}

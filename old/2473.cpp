#include<iostream>
#include<algorithm>

#define ll long long 
using namespace std;
int N;
int D[5001]; 
ll mind=3000000005LL; 

ll abs(ll &a){
	return a<0?-a:a; 
}

void solve(){
	int p[3]; 
	for(int i=0; i<N; ++i){
		int mid = i+1; 
		int right = N-1; 
		
		while(mid<right){
			ll sum = (ll)D[i]+D[mid]+D[right]; 
			ll dif = ::abs(sum); 
			if(dif<mind){
				p[0]=i,p[1]=mid,p[2]=right; 
				mind=dif; 
			}
			
			if(sum<0) mid++;
			else right--; 
		}
	}
	
	for(auto &i:p)
		cout<<D[i]<<' ';
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N; 
	for(int i=0; i<N; ++i) cin>>D[i]; 
	sort(D,D+N);
	 
	solve(); 
	return 0;
}


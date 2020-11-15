#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int V,E; 
struct node{
	int val,from,to;
	bool operator<(const node &n){
		return this->val<n.val; 	
	}
};
node D[100001]; 
int P[10001]; 

int getParent(int x){
	if(P[x] == x) return x; 
	return P[x] = getParent(P[x]); 
}

void unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a<b) P[b] = a; 
	else P[a] = b; 	
}

bool sameParent(int a, int b){
	return getParent(a) == getParent(b); 	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>V>>E; 
	for(int i=1; i<=V; ++i) P[i] = i; 
	for(int i=0; i<E; ++i) cin>>D[i].from>>D[i].to>>D[i].val; 	
	
//	sort(D,D+E,[](const node &a, const node &b){ return a.val<b.val; }); 
	sort(D,D+E); 
	
	int sum = 0; 
	for(int i=0; i<E; ++i){
		auto &n = D[i]; 
		if(!sameParent(n.from, n.to)){
			sum += n.val; 
			unionParent(n.from, n.to); 
		}
	}
	
	cout<<sum; 
	
	return 0;
}


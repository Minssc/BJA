#include<iostream>

#define ull unsigned long long
using namespace std;
int N; 
int D[100001]; 

ull planks(int left, int right){
	if(left==right) return D[left]; 
	int mid=(left+right)/2;
	ull ret=max(planks(left,mid),planks(mid+1,right)); 
	int lo=mid, hi=mid+1; 
	ull height=min(D[lo],D[hi]); 
	ret=max(ret,height*2); 
	
	while(left<lo||hi<right){
		if(hi<right&&(lo==left||D[lo-1]<D[hi+1])){
			++hi; 
			height=min(height,(ull)D[hi]); 
		}else{
			--lo;
			height=min(height,(ull)D[lo]);
		}
		ret=max(ret,height*(hi-lo+1)); 
	}
	return ret; 
}

void solve(){
	for(int i=0; i<N; ++i) cin>>D[i]; 
	cout<<planks(0,N-1)<<'\n'; 	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	while(true){
		cin>>N;
		if(!N) break; 
		solve(); 	
	}
	
	return 0;
}


#include<iostream>
#include<vector> 

using namespace std;
int N,M,K; 
int D[1000001]; 
vector<int> T; 

int initTree(int start, int end, int node){
	if(start==end) return T[node] = D[start]; 
	int mid=(start+end)/2; 
	return T[node] = initTree(start,mid,node*2)+initTree(mid+1,end,node*2+1); 	
}

int sumTree(int start, int end, int node, int left, int right){
	if(left>end||right<start) return 0; 
	if(left<=start&&end<=right) return T[node]; 
	int mid=(start+end)/2; 
	return sumTree(start,mid,node*2,left,right)+sumTree(mid+1,end,node*2+1,left,right); 
}

void updateTree(int start, int end, int node, int index, int dif){
	if(index<start||index>end) return;
	T[node]+=dif;
	if(start==end) return;
	int mid=(start+end)/2; 
	updateTree(start,mid,node*2,index,dif);
	updateTree(mid+1,end,node*2+1,index,dif); 	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M>>K; 
	T.resize(4*N); 
	
	for(int i=0; i<N; ++i) cin>>D[i]; 
	initTree(0,N-1,1); 
	
	for(int i=0; i<M+K; ++i){
		int a,b,c; cin>>a>>b>>c;
		
		if(a==1){
			updateTree(0,N-1,1,b-1,c-T[b]); 
		}else if(a==2){
			cout<<sumTree(0,N-1,1,b-1,c)<<'\n'; 
		}
	}
	
	return 0;
}


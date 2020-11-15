#include<iostream>
#include<algorithm>
using namespace std;
int N,C;
int D[200001]; 

bool check(int m){
	int cnt = 1;
	int prev = D[0];
	for(int i=1; i<N; ++i){
		if(D[i]-prev>=m){
			cnt++;
			prev = D[i];
		}
	}
	
	if(cnt>=C)
		return true;
	return false; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>C; 
	for(int i=0; i<N; ++i) cin>>D[i]; 
	sort(D,D+N); 
	int start = 1, end = D[N-1]-D[0];
	int result = 0;
	
	while(start<=end){
		int middle = (start+end)/2;
		if(check(middle)){
			result = max(result, middle);
			start = middle+1;
		}else
			end = middle-1;
	}
	
	cout<<result<<'\n'; 
	return 0;
}

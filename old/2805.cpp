#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
int D[1000001]; 

int cut(int h){
	unsigned long long sum = 0; 
	for(int i=0; i<N; ++i){
		if(D[i]<=h) break;
		sum += D[i]-h; 
	}
	
	if(sum>M)
		return 1;
	else if(sum<M)
		return -1;
	else 
		return 0; 	
}

void maxHeight(int m){
	int start = D[0];
	int end = 0; 
	int middle; 
	int result;
	
	while((start+1)>end){
		middle = (start+end)/2; 
		result = cut(middle);	
		if(!result){
			cout<<middle; 
			return;	
		}
		switch(result){
			case 1:
				end = middle+1;
				break;
			case -1:
				start = middle-1; 	
				break;	
		}
	}
	cout<<start<<'\n';
	
}

int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	cin>>N>>M;
	for(int i=0; i<N; ++i) cin>>D[i]; 
	sort(D,D+N,greater<int>()); 
	maxHeight(M); 
	return 0;
}

/*
20 15 10 17
20 17 15 10 

*/

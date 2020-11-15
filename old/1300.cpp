#include<iostream>
using namespace std;
//10,000,000,000

int main(){
	int N,K;
	cin>>N>>K;
	int end = 1000000000;
	int start = 1;
	int middle;
	int result = 0; 
	
	while(start<=end){
		middle = (start+end)/2; 
		long long num = 0;
		for(int i=1; i<=N; ++i) num += min(middle/i,N);
		if(num<K)
			start = middle+1;
		else{
			result = middle;
			end = middle-1;	
		}
	}
	
	cout<<result;	
	
	return 0;
}
/*
000
012
024

123
246
369
122334669

*/

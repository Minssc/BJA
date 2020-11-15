#include<iostream>
#include<stack>
using namespace std;
int D[100001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int K; cin>>K;
	stack<int> ST; 
	for(int i=0; i<K; ++i) cin>>D[i];
	
	int sum = 0; 
	for(int i=0; i<K; ++i){
		if(!D[i]){
			sum -= ST.top();
			ST.pop(); 	
		}else{
			sum += D[i];
			ST.push(D[i]); 	
		}
	}
	
	cout<<sum; 
	return 0;
}

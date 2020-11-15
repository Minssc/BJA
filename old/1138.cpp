#include<iostream>
using namespace std;

int D[11]; 
int L[11]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,A;
	cin>>N; 
	for(int i=1; i<=N; ++i)
		cin>>D[i]; 
	
	for(int i=1; i<=N; ++i){
		int idx = 1; 
		for(int j=1; j<=N; ++j){
			if(L[j]) continue; 
			if(D[i]+1 == idx){
				L[j] = i; 
				break;
			}
			idx++;
		}
	}
	
	for(int i=1; i<=N; ++i)
		cout << L[i] << ' '; 
	cout << endl; 
	
	return 0;
}
/*
	L배열에 숫자 있으면 치지않고
	입력받은 인덱스에 삽입.  
*/

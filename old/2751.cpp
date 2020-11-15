#include<iostream>
using namespace std;


int main(){
	cin.tie(NULL), ios_base::sync_with_stdio(false); 
	int N; 
	cin>>N;
	int *A = new int[N]; 
	for(int i=0; i<N; ++i)
		cin>>A[i];
		
	int temp; 
	
	for(int i=1; i<N; ++i){
		int c = i; 
		do{
			int root = (c-1)/2; 
			if(A[root]<A[c]){
				temp = A[root];
				A[root] = A[c];
				A[c] = temp; 		
			}
			c = root; 
		}while(c!=0);
	}
	
	for(int i=N-1; i>=0; --i){
		temp = A[0];
		A[0] = A[i];
		A[i] = temp; 
		int root = 0;
		int c = 1; 
		
		do{
			c = 2*root+1;
			if(c<i-1 && A[c] < A[c+1])
				c++;
			
			if(c<i && A[root] < A[c]){
				temp = A[root];
				A[root] = A[c];
				A[c] = temp; 
			}
			root = c; 
		}while(c<i);
	}
	
	
	
	for(int i=0; i<N; ++i){
		cout << A[i] << ' ';	
	}
	
		
	delete[] A; 
	return 0;
}

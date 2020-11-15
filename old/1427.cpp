#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N;
	cin>>N; 
	
	int n=N, d=0;
	while(n>0){
		d++;
		n/=10;	
	}
	
	int *A = new int[d];
	n=N;
	int i=0; 
	while(n>0){
		A[i++] = n%10; 
		n/=10;	
	}
	
	sort(A, A+d, greater<int>());
	
	for(int i=0; i<d; ++i)
		cout << A[i];
	cout<<endl; 
	
	return 0;	
}

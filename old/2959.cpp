#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int A[4]; 
	for(auto &i:{0,1,2,3})
		cin>>A[i]; 
	sort(A,A+4); 
	cout<<A[2]*A[0]<<'\n'; 
	
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string A,B; 
	cin>>A>>B; 
	if(B.size() > A.size()){
		string temp = A;
		A = B; 
		B = temp; 
	}
	
	if(!A.compare(B)){
		cout<<0;
		return 0; 	
	}
	int min = 1234567890;
	for(int i=0; i<=A.size()-B.size(); ++i){
		int diff = 0; 
		for(int j=0; j<B.size(); ++j)
			if(A[i+j] != B[j])
				diff++; 	
		
		if(diff<min)
			min = diff; 
	}
	
	cout<<min;
	
	return 0;
}

#include<iostream>
using namespace std;

int fact(int a){
	if(a<=1)
		return 1; 
	return a*fact(a-1); 
}

int main(){
	int N;
	cin>>N;
	
	cout << fact(N);	
	
	return 0; 	
}

#include<iostream>
using namespace std;

int main(){
	int A = 0;
	for(int i=1; i<=8; ++i){
		int a; cin>>a;
		A*=10,A+=a; 
	}
	
	if(A==12345678) cout<<"ascending";
	else if(A==87654321) cout <<"descending";
	else cout<<"mixed";
	return 0;
}

/*
1 10 11 100
1 2  3  4


*/

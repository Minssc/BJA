#include<iostream>
#include<string>
using namespace std;

int cval(string &s){
	if(s=="black") return 0;
	else if(s=="brown") return 1;
	else if(s=="red") return 2;
	else if(s=="orange") return 3;
	else if(s=="yellow") return 4;
	else if(s=="green") return 5;
	else if(s=="blue") return 6;
	else if(s=="violet") return 7;
	else if(s=="grey") return 8;
	else if(s=="white") return 9;
	else return -1; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string A,B,C;
	cin>>A>>B>>C;
	long long val = cval(A)*10 + cval(B);
	for(int i=0; i<cval(C); ++i) val *= 10; 
	
	cout<<val; 
	
	return 0;
}

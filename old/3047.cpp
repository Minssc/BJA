#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int	A[3];
	for(int i=0; i<3; ++i)
		cin>>A[i];
	string S; cin>>S; 
	sort(A,A+3);
	for(auto &c:S)
		cout << A[c-'A'] << ' ';	
	cout<<'\n'; 
	
	return 0;
}

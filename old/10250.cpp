#include<iostream>
using namespace std;

void solve(int TC){
	int H,W,N;
	
	cin>>H>>W>>N;
	cout << (N%H==0 ? H : N%H);
	if(((N-1)/H+1) < 10)
		cout<<0; 
	cout << (N-1)/H+1;
	cout << endl;
	
}

int main(){
    cin.tie(NULL), ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    
    for(int t=1; t<=T; ++t)
    	solve(t);
    
    return 0;
}

#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 
    long A,B,C;
    cin>>A>>B>>C;
    if(C-B<=0){
    	cout<< -1;
    	return 0; 
	}
    cout<<(int)((double)A/(C-B)+1)<<endl; 
    
    return 0; 
}

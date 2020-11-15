#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 
    int N;
    cin>>N;
    
    
    int A = 0, B= 0; 
    A = N/5;
    
    	
    while(A>0){
    	if((N-A*5)%3 == 0){
    		cout << A+(N-A*5)/3;
    		return 0;
		}
    	A--;
	}
    if(N%3==0){
    	cout << N/3;
    	return 0;
	}
    	
	cout<<-1;
    
    return 0; 
}

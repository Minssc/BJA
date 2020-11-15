#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 
    
    int N;
    cin>>N;
    
    int i=1, c=1; 
    while(N>c) c += i++*6; 
    
    cout << i;
    
    return 0; 
}

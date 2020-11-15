#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL), ios_base::sync_with_stdio(false);
    int H,M;
    cin>>H>>M;
    
    if(M<45)
    {
        M = 60 - (45-M); 
        H--;
    }
    else
    {
        M -= 45; 
    }
    
    if(H<0)
        H = 23;
    
    cout << H << ' ' << M << endl; 
    
    
    return 0;
}

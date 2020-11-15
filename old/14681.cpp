#include<iostream>
using namespace std;

int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	int X,Y;
	cin>>X>>Y;
	
	if(X>0 && Y>0)
		cout << 1;
	else if(X>0 && Y<0)
		cout << 4;
	else if(X<0 && Y>0)
		cout << 2;
	else if(X<0 && Y<0)
		cout << 3; 

	return 0; 	
}

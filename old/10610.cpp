#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string S;
	cin>>S; 
	int sum=0;
	for(auto c:S)
		sum += c-'0'; 
		
	sort(S.begin(), S.end(), greater<char>());
	
	if(sum%3!=0 || S[S.size()-1] != '0'){
		cout<<-1;
		return 0;
	}
	
	cout<<S;
	return 0;
}








/*
30 60 90 120 150 180 210 240 270 300

30 60 90 20 50 80 10 40 70 
10 20 30 40 50 60 70 80 


*/

#include<iostream>
#include<queue>
using namespace std;

long long desc(int n){
	if(n<=10) return n;
	queue<long long> Q;
	for(int i=1; i<=9; ++i) Q.push(i);
	
	while(!Q.empty()){
		long long v = Q.front(); Q.pop();
		if(!--n) return v;
		
		for(int i=0; i<v%10; ++i)
			Q.push(v*10+i);
		
	}
	return -1;
}

int main(){
	int N; cin>>N; 	
	
	cout << desc(N);
	
	return 0;
}
/*
0 1 2 3 4 5 6 7 8 9 10 21 20 
0 1 2 3 4 5 6 7 8 9 
9[8-0] 98 97 96 95 94 93 92 91 90
8[7-0]
7[6-0]
6[5-0]
5[4-0]
4[3-0]
3[2-0]
2[1-0]
10

98[7-0]
97[6-0] 
910

*/

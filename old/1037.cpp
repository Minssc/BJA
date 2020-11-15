#include<iostream>
#include<algorithm>
using namespace std;
int D[51]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N; cin>>N; 
	for(int i=0; i<N; ++i) cin>>D[i];
	sort(D,D+N);
	cout<<D[0]*D[N-1]<<'\n';
	return 0;
}
/*
2
3
4
2
3 2
8
4 2
9
3
10
5 2
12
2 3 4 6
14
2 7
16
2 8 4
18
2 9 
20
2 4 5 10

*/

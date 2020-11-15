#include<iostream>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T;cin>>T;
	for(int t=1; t<=T; ++t){
		int ax,ay,ar,bx,by,br;
		cin>>ax>>ay>>ar>>bx>>by>>br; 
		int dist = abs(ax-bx)*abs(ax-bx)+abs(ay-by)*abs(ay-by);
		int M = (ar+br)*(ar+br);
		int m = abs(ar-br)*abs(ar-br);
		if(!dist && ar==br)
			cout << -1 << '\n';
		else if(dist == M || dist == m)
			cout << 1 << '\n';
		else if(M < dist || m > dist)
			cout << 0 << '\n';
		else 
			cout << 2 << '\n';
	}
	
	return 0;
}

#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

int main(){
	int N;cin>>N; 
	deque<int> dq;
	for(int i=1; i<=N; ++i) dq.push_back(i);
	if(N==1){
		cout<<1;
		return 0;
	}
	int v;
	while(true){
		dq.pop_front();
		v = dq.front(),dq.pop_front();
		if(dq.empty())
			break;
		dq.push_back(v);
	}
	cout<<v;
	
	return 0;
}

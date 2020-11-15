#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int N;cin>>N;	
	deque<int> dq;
	for(int i=0; i<N; ++i){
		string S; cin>>S; 
		if(S=="push_front"){
			int A;cin>>A;
			dq.push_front(A); 	
		}else if(S=="push_back"){
			int A;cin>>A;
			dq.push_back(A); 	
		}else if(S=="front"){
			if(!dq.empty())
				cout<<dq.front()<<'\n';	
			else
				cout<<-1<<'\n';
		}else if(S=="back"){
			if(!dq.empty())
				cout<<dq.back()<<'\n';
			else
				cout<<-1<<'\n';
		}else if(S=="size"){
			cout<<dq.size()<<'\n';
		}else if(S=="empty"){
			cout<<dq.empty()<<'\n';
		}else if(S=="pop_front"){
			if(!dq.empty()){
				cout<<dq.front()<<'\n';
				dq.pop_front();
			}else
				cout<<-1<<'\n';
		}else if(S=="pop_back"){
			if(!dq.empty()){
				cout<<dq.back()<<'\n';
				dq.pop_back();
			}else
				cout<<-1<<'\n';
		}
	}
	return 0;
}

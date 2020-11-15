#include<iostream>

struct node{
	char val;
	int left,right;	
};
using namespace std;
int N;
node nodes[28]; 

void pre(char c=1){
	if(!c) return; 
	auto &Node = nodes[c]; 
	
	cout<<Node.val;
	pre(Node.left);
	pre(Node.right); 
}

void mid(char c=1){
	if(!c) return; 
	auto &Node = nodes[c]; 
	
	mid(Node.left);
	cout<<Node.val;
	mid(Node.right); 
}

void post(char c=1){
	if(!c) return; 
	auto &Node = nodes[c]; 
	
	post(Node.left);
	post(Node.right);
	cout<<Node.val; 
} 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	
	for(int i=0; i<N; ++i){
		char a,b,c; cin>>a>>b>>c;
		auto &Node = nodes[a-'A'+1]; 
		Node.val = a;
		
		if(b!='.') Node.left = b-'A'+1; 
		if(c!='.') Node.right = c-'A'+1; 
	}
	
	pre(); cout<<'\n'; 
	mid(); cout<<'\n'; 
	post(); cout<<'\n'; 
	
	return 0;
}


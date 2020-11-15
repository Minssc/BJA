#include<iostream>
#include<string>
using namespace std;

struct Node{
	int val;
	Node *next;
	Node(int a, Node* ptr){
		this->val = a;
		this->next = ptr; 
	}
};

Node *HEAD;
Node *TAIL; 
int _size = 0; 

void push(int a){
	Node *node = new Node(a,0); 
	if(_size==0)
		HEAD = node; 
	else
		TAIL->next = node; 
	
	TAIL = node; 
	_size++; 
}

int pop(){
	if(_size==0) return -1;
	int r = HEAD->val;
	Node *nhead = HEAD->next; 
	delete HEAD;
	HEAD = nhead; 
	_size--; 
	return r; 
}

int size(){
	return _size; 	
}

bool empty(){
	return !_size;
}

int front(){
	if(_size == 0) return -1;
	return HEAD->val; 	
}

int back(){
	if(_size == 0) return -1; 
	return TAIL->val; 	
}


int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int N;cin>>N;	
	for(int i=0; i<N; ++i){
		string S; cin>>S; 
		if(S=="push"){
			int A;cin>>A;
			push(A); 	
		}else if(S=="front"){
			cout<<front()<<'\n';	
		}else if(S=="back"){
			cout<<back()<<'\n';
		}else if(S=="size"){
			cout<<size()<<'\n';
		}else if(S=="empty"){
			cout<<empty()<<'\n';
		}else if(S=="pop"){
			cout<<pop()<<'\n';
		}
	}
	return 0;
}

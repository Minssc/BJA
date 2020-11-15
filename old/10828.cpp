#include<iostream>
#include<string> 
using namespace std;

int D[10001]; 
int s_pointer; 

void push(int v){	
	D[s_pointer++] = v; 
}

int pop(){
	if(!s_pointer) return -1;
	return D[--s_pointer]; 	
}

int size(){
	return s_pointer; 	
}

bool empty(){
	return s_pointer?false:true; 
}

int top(){
	if(!s_pointer) return -1; 
	return D[s_pointer-1]; 	
}

int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	string CMD;
	int N;cin>>N;
	for(int i=0; i<N; ++i){
		cin>>CMD; 
		if(CMD=="push"){
			int V;cin>>V;
			push(V); 
		}else if(CMD=="top"){
			cout << top() << '\n'; 
		}else if(CMD=="size"){
			cout << size() << '\n'; 
		}else if(CMD=="empty"){
			cout << empty() << '\n'; 
		}else if(CMD=="pop"){
			cout << pop() << '\n'; 
		}
	}
	
	return 0;
}

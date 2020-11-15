#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	string s; cin>>s; 
	string result = "";
	stack<char> st; 
	
	for(auto &c:s){
		if('A'<=c && c<= 'Z')
			result += c;
		else
			switch(c){
				case '(':
					st.push(c); break; 
				case '*': case '/':
					while(!st.empty() && (st.top() == '*' || st.top() == '/')) result += st.top(), st.pop();
					st.push(c); 
					break;
				case '+': case '-':
					while(!st.empty() && st.top() != '(') result += st.top(), st.pop(); 
					st.push(c);
					break;
				case ')':
					while(!st.empty() && st.top() != '(') result += st.top(), st.pop();
					st.pop();
					break;
			}
	}
	
	while(!st.empty()) result += st.top(), st.pop(); 
	
	cout<<result;
			
	return 0;	
}

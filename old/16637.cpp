#include<iostream>
#include<string> 

using namespace std;
int N, ANS=-1234567890; 
string S;

int calc(char op, int lvalue, int rvalue){
	if(op=='+') return lvalue+=rvalue; 
	else if(op=='-') return lvalue-=rvalue; 
	else if(op=='*') return lvalue*=rvalue; 
}

void solve(int idx, int lvalue){
	cout<<idx<<','<<lvalue<<'\n'; 
	if(idx>N){
		ANS=max(ANS,lvalue); 
		return; 	
	}
	
	int temp=calc(S[idx-1],lvalue,S[idx]-'0'); 
	solve(idx+2, temp); 
	if(idx+4<=N){
		cout<<"idx:"<<idx<<','<<lvalue<<'\n'; 
		int atemp=calc(S[idx+3],S[idx+2]-'0',S[idx+4]-'0'); 
		cout<<atemp<<'\n'; 
		lvalue=calc(S[idx-1],lvalue,S[idx]-'0'); 
		cout<<lvalue<<'\n'; 
		lvalue=calc(S[idx+1],lvalue,atemp);
		
		cout<<lvalue<<'\n'; 
		return solve(idx+6,lvalue); 	
	}
	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>S; 
	S='+'+S; 
	
//	int ret=0; 
//	for(int i=1; i<S.size(); i+=2){
//		if(S[i-1]=='+') ret+=S[i]-'0';
//		else if(S[i-1]=='-') ret-=S[i]-'0';
//		else if(S[i-1]=='*') ret*=S[i]-'0';
//		cout<<S[i]<<','<<S[i-1]<<' '<<ret<<'\n'; 
//	}
//	cout<<ret;
	solve(1,0); 
	cout<<ANS; 
	
	return 0;
}

/*
(3+8)*7-9*2
*/ 


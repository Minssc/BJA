#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int D[100001]; 

void solve(){
	string CMD; cin>>CMD; 
	int N; cin>>N;
	string arr; cin>>arr;
//	int nD = 0;
//	for(auto &c:CMD)
//		if(c=='D')
//			nD++; 
//	if(nD>N){
//		cout<<"error"<<'\n'; 
//		return;	
//	}else if(nD==N){
//		cout<<"[]"<<'\n'; 
//		return; 	
//	}

//	bool front = true; 
//	auto fit = arr.begin()+1, bit = arr.end()-2; 
//	cout<<"CMD:"<<CMD<<" ARR: " << arr<<'\n'; 
//	for(auto &c:CMD){
//		if(fit>bit){
//			cout<<"error"<<'\n';
//			return; 	
//		}
//		if(c=='R'){
//			front = !front;	
//		}else{
//			if(front) while(fit<arr.end()-1 && *(fit++) != ',');
//			else while(bit>arr.begin() && *(bit--) != ','); 
//			
//		}
//		cout<<"FIT: " << *fit << "BIT: " << *bit << ',' << (bit-fit)<<'\n'; 
//	}
//	
//	if(fit>bit){
//		cout<<"[]"<<'\n'; 
//		return;	
//	}
//	
//	cout<<'[';
//	if(front){
//		while(fit<bit){
//				
//		}
//	}else{
//		
//		
//	}
//	cout<<']'<<'\n'; 
	
	arr = arr.substr(1,arr.size()-2);
	int pos,lpos = 0; 
	for(int i=0; i<N; ++i){
		pos = arr.find(",",lpos+1); 
		int v = stoi(arr.substr(lpos+0,pos-lpos));
		D[i] = v; 
		lpos = pos+1; 
	}
	
	int start = 0, end = N-1; 
	bool front = true; 
	
	for(auto &c:CMD){
		if(c=='R')
			front = !front; 	
		else{
			if(start>end){
				cout<<"error"<<'\n';	
				return; 
			}
			if(front) start++;
			else end--; 
		}
	}
	if(start>end){
		cout<<"[]"<<'\n'; 
		return;	
	}
	cout<<'['<<D[(front?start:end)];
	if(front)
		for(auto i=start+1; i<=end; ++i)
			cout<<','<<D[i];
	else
		for(auto i=end-1; i>=start; --i)
			cout<<','<<D[i];
	cout<<']'<<'\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int T; cin>>T;
	for(int t=0; t<T; ++t)
		solve();
	
	return 0;
}

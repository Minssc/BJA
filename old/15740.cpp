#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> A,B;
int S_A,S_B;
class BIGNO{
	private:
		string IS;
		int type;
	public:
		BIGNO(string s){
			if(s.front() == '-'){
				this->type = 1;
				s.erase(s.begin());
			}
			IS = s;
		}
		
		BIGNO operator+(const BIGNO &B){
			int blen = max(B.s
		}
		
		string getString(){
			return IS; 
		}
};

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string a,b;
	cin>>a>>b;
	
	BIGNO A(a);
	BIGNO B(b); 
	
//	cout<<A+B;
	return 0;
}

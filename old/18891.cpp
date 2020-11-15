#include<iostream>
#include<string>
#include<vector>
#include<iomanip> 
#include<algorithm>

using namespace std;
int P, V;
struct vdata {
	string name;
	int lseat, votes, sseat, tseat, total;
	double vvratio, td;
};
vector<vdata> GV;

int main() {
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin >> P >> V;
	int valid_votes = 0, invalid_seats = 253;
	for (int i = 0; i < P; ++i) {
		string name;
		int lseat, votes;
		cin >> name >> lseat >> votes;
		GV.push_back({ name,lseat,votes });
		invalid_seats -= lseat;
		valid_votes += votes;
	}

	int tvotes = 0;
	vector<int> VG;
	for (int i = 0; i < GV.size(); ++i) {
		auto &d = GV[i];
		if (d.lseat >= 5 || (double)d.votes / valid_votes >= 0.03) {
			tvotes += d.votes;
			VG.push_back(i);
		}else
			invalid_seats+=d.lseat; 
	}

	int allocated_seats = 0;
	for (auto &i : VG) {
		auto &d = GV[i];
		d.vvratio = (double)d.votes / tvotes;
		double temp = ((300 - invalid_seats)*d.vvratio - d.lseat) / 2;
		if (temp < 1.0) d.sseat = 0;
		else d.sseat = (int)(temp + 0.5);
		allocated_seats += d.sseat;
	}

	int seats_left = 0; 
	if (allocated_seats < 30) {
		seats_left = 30 - allocated_seats;
		for (auto &i : VG) {
			auto &d = GV[i];
			double temp = (30 - allocated_seats)*d.vvratio;
			d.sseat += (int)temp;
			seats_left -= (int)temp;
			d.td = temp - (int)temp;
		}
	}
	else if (allocated_seats > 30) {
		seats_left = 30;
		for (auto &i : VG) {
			auto &d = GV[i];
			double temp = 30.0 * d.sseat / allocated_seats;
			d.sseat = (int)temp;
			seats_left -= d.sseat;
			d.td = temp - (int)temp;
		}
	}
	
	if(seats_left){
		vector<int> tosort = VG;
		stable_sort(tosort.begin(), tosort.end(), [](const int &a, const int &b) {
			return GV[a].td > GV[b].td;
			});
		for (int i = 0; i < seats_left; ++i) GV[tosort[i]].sseat++;		
	}

	seats_left = 17;
	for (auto &i : VG) {
		auto &d = GV[i];
		double temp = 17 * d.vvratio;
		d.tseat = (int)temp;
		seats_left -= d.tseat;
		d.td = temp - (int)temp;
	}

	vector<int> tosort = VG;
	stable_sort(tosort.begin(), tosort.end(), [](const int &a, const int &b) {
		return GV[a].td > GV[b].td;
		});
	for (int i = 0; i < seats_left; ++i) GV[tosort[i]].tseat++;

	for (auto &d : GV) d.total = d.lseat + d.sseat + d.tseat;
	
//	for (auto &d : GV) {
//		cout << left << setw(25) << d.name << setw(5) << d.lseat << setw(5) << d.sseat << setw(5) << d.tseat << setw(5) << d.total << endl;
//	}
	
	sort(GV.begin(),GV.end(),[](const vdata &a, const vdata &b){
		return (a.total==b.total? a.name<b.name : a.total>b.total); 	
	});

	for(auto &d:GV)
		cout<<d.name<<' '<<d.total<<'\n'; 
	return 0;
}






#include<iostream>
#include<cmath>
#include<map>
#include<utility>
using namespace std;
int main() {
	string a,b,c;
	int total=0;
	// get 3 lines

	while (getline(cin,a)) {
		getline(cin,b);
		getline(cin,c);
		map<char,bool> counta, countb, countc;
		for (char i: a) counta[i] = true;
		for (char i: b) countb[i] = true;
		for (char i: c) countc[i] = true;

		for (pair<char,bool> p: counta) {
			if (countb[p.first] and countc[p.first]) {
				if ('a'<=p.first and p.first<='z') {
					total += p.first-'a'+1;
				}
				else {
					total += 26 + p.first-'A'+1;
				}
			}
		}
	}
	cout << total << endl;
}

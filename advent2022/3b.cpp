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
	/*
	while (getline(cin,s)) {
		// split into 2
		for (int i=0;i<s.size()/2;i++) {
			for (int j=s.size()-1;j>=s.size()/2;j--) {
				if (s[i]==s[j]) {
					cout << i << " " << j << endl;
					if ('a'<=s[i] and s[i]<='z') {
						total += s[i]-'a'+1;
					}
					else {
						total += 26 + s[i]-'A'+1;
					}
					goto end;
				}
			}
		}
end:;
		cout<<endl;
	}
	cout<<total << endl;
	*/
}

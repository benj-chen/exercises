#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int main() {
	string s;
	int total=0;
	while (getline(cin,s)) {
		char a = s[0], b = s[2];
		int sc_a = a-'A', sc_b = b-'X';
		total += sc_b+1;
		if (sc_a+1==sc_b or (sc_a -2 == sc_b)) {
			// win
			cout << "rps"[sc_a] << "rps"[sc_b];
			total += 6;
		}
		else if (sc_a==sc_b){
			total += 3;
		}
	}
	cout<<total << endl;
}

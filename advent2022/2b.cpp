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
		switch(sc_b) {
			case 2:
				// lose
				sc_b = sc_a+1;
				sc_b %=3;
				break;
			case 1:
				sc_b = sc_a;
				break;
			case 0:
				// win
				sc_b = (sc_a -1 + 3) % 3;
				break;
		}
		total += sc_b+1;
		if (sc_a+1==sc_b or (sc_a -2 == sc_b)) {
			// win
			total += 6;
		}
		else if (sc_a==sc_b){
			total += 3;
		}
	}
	cout<<total << endl;
}

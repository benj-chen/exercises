#include<iostream>
#include<cmath>
using namespace std;
int main() {
	string s;
	int cur = 0, max = 0;
	while (getline(cin,s)) {
		if (s=="") {
			max = fmax(cur,max);
			cur = 0;
		}
		else {
			cur += stoi(s);
		}
	}
	cout << max << endl;
}

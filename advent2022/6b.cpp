#include<iostream>
#include<cmath>
using namespace std;
int main() {
	string s;
		
	while (getline(cin,s)) {
		for (int i=0;i<s.size();i++) {
		bool it = false;
			for (int j=i;j<i+14;j++) {
				for (int k=i;k<i+14;k++) if (j!=k) if (s[j]==s[k])
			it = true;}
		if (not it) {cout << i+14 << endl; break;}
		}	
	}

}

#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int main() {
	string s;

	int total=0;
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
}

#include<iostream>
#include<cmath>
#include<vector>
#include<utility>
using namespace std;
vector<string> split_delimiter_char(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=c;
    }
    return res;
}
int main() {
	string s;
	int count = 0;
	while (getline(cin,s)) {
		vector<string> a1 = split_delimiter_char(s,',');
		vector<string> b1 = split_delimiter_char(a1[1],'-');
		a1 = split_delimiter_char(a1[0],'-');
		pair<int,int> a = {stoi(a1[0]),stoi(a1[1])},

		b = {stoi(b1[0]),stoi(b1[1])};
		if( 
			(a.first <= b.first and a.second >= b.second) or
			(b.first <= a.first and b.second >= a.second) or 
			(a.first <= b.first and b.first <= a.second) or 
			(b.first <= a.first and a.first <= b.second)
		  ) {
			cout << "*";
			count++;
		}
		cout << a.first << a.second << b.first << b.second << endl;
	}
	cout << count << endl;
}

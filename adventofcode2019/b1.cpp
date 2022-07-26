#include <iostream>
#include <vector>
// previously did day 1 early
#include <fstream>
using namespace std;
ifstream fin("in");
using vs = vector<string>;
using vi = vector<int>;
vi split(string s, char delim) {
    vi ret(1);
    for (char c: s) {
        if (c==delim) ret.push_back(0);
        else ret.back() = ret.back() * 10 + c-'0';
    }
    return ret;
}
int main() {
    string s; cin >> s;
    vi in = split(s,',');
    for (int i=0;i<in.size();i+=4) {
        switch(in[i]) {
            case 99:
            cout << in[0] << endl; return 0;
            case 1:
            // add
            in[in[i+3]] = in[in[i+1]] + in[in[i+2]];
            break;
            case 2:
            in[in[i+3]] = in[in[i+1]] * in[in[i+2]];
            break;
        }
    }
}
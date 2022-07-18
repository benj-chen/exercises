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
vi input;
int solve() {
    vi in = input;
    for (int i=0;i<in.size();i+=4) {
        switch(in[i]) {
            case 99:
            return in[0];
            case 1:
            // add
            in[in[i+3]] = in[in[i+1]] + in[in[i+2]];
            break;
            case 2:
            in[in[i+3]] = in[in[i+1]] * in[in[i+2]];
            break;
        }
    }
    return -1;
}
int main() {
    
    string s; fin >> s;
    input = split(s,',');
    input[0]=0;
    for (int i=0;i<100;i++) for (int j=0;j<100;j++) {
        input[1] = i;
        input[2] = j;
        if (solve() ==  19690720) {
            cout << 100 * i + j << endl;
        }
    }
}
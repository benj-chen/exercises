// with O2 optimization flag, exec time is 0.006s
#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using st=string;
int ct[2]; // init to 0
int main() {
    ifstream in("i6");
    st raw_input;
    vector<st> input(1);
    while (getline(in,raw_input)) {
        if (raw_input=="") input.push_back("");
        else input.back()+=raw_input+"\n";
    }
    in.close();
    
    for (st s: input) {
        map<char,int> set_s;
        for (char c: s) set_s[c]++; // default map value is 0 if it doesn't exist. No seg fault which is nice.
        ct[0]+=set_s.size()-1; // \n is an element
        for (pair<char,int> p: set_s) { // include utility
            if (p.first=='\n') continue;
            if (set_s[p.first]==set_s['\n']) ct[1]++;
        }
    }
    // part 1 answer 6259, part 2 answer 3178
    cout << ct[0] << '\n' << ct[1] << '\n';
}
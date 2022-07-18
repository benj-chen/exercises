#include <iostream>
#include <vector>
#include <map>
// previously did day 1 early
#include <fstream>
using namespace std;
using vs = vector<string>;
using str = string;
ifstream fin("in");
vs split(str s, char delim) {
    vs ret(1);
    for (char c: s) {
        if (c==delim) ret.push_back("");
        else ret.back()+=str(1,c);
    }
    return ret;
}

    map<string, vector<string>> mp;
int sum = 0;
int dfs(string root) {
    if (mp[root].empty()) {
        return 0; // direct
    }
    int ct=mp[root].size();
    for (string s: mp[root]) ct += dfs(s);
    sum+=ct;
    return ct;
}
int main() {
    string s;
    while (getline(fin,s)) {
        vs t = split(s,')');
        mp[t[0]].push_back(t[1]);
        cout << t[0] << " " << t[1] << endl;
    }
    cout << dfs("COM") << endl;
    cout << sum << endl;
}
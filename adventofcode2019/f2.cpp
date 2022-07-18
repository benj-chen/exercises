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
bool dfs(string root, string goal, vector<string>& to_add) {
    if (root==goal) {
        return 1;
    }
    if (mp[root].empty())
    return 0;
    for (string s: mp[root]) {
        if (dfs(s,goal,to_add)) {
            to_add.push_back(s);
            return 1;
        }
    }
    return 0;
}
int main() {
    string s;
    while (getline(fin,s)) {
        vs t = split(s,')');
        mp[t[0]].push_back(t[1]);
        cout << t[0] << " " << t[1] << endl;
    }

vector<string> comyou,comsan;
    dfs("COM","YOU",comyou);
    dfs("COM","SAN",comsan);
    for (auto i: comyou) cout << i << " "; cout << endl;
    for (auto i: comsan) cout << i << " "; cout << endl;
    // find common
    while (comyou.back() == comsan.back()) {
        comyou.pop_back();
        comsan.pop_back();
    }
    cout << comyou.size()+comsan.size()-2 << endl;
}
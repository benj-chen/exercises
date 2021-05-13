#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
using pii = pair<int,int>;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>
#define alg_type int // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
#define f first
#define s second
vt<string> inputs;
vector<string> split_delimeter_string(string s, string delim) {
    vector<string> res;
    const int dl = delim.length();
    for (int i=0;i<s.length()-dl && s.length()>dl;i++) {
        string seg = s.substr(i,dl);
        if (seg==delim) {
            res.push_back(s.substr(0,i));
            s=s.substr(i+dl);
            i=0;
        }
    }
    res.push_back(s);
    return res;
}
void get_input() {
    ifstream fin("22.txt");
    string s;
    fin >> s;
    inputs=split_delimeter_string(s.substr(1,s.length()-2),"\",\""); // leading and closing "
}
int main() {
    get_input();
    sort(inputs.begin(),inputs.end());
    int score=0;
    FOR(i,0,inputs.size()) {
        int res=0;
        for (char c: inputs[i]) res+=c-'A'+1;
        score+=(i+1)*res;
    }
    cout << score << endl;
}
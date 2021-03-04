#include <bits/stdc++.h>

using namespace std;
string rp(int i,string c) {
    string s;
    while (i--) {
        s+=c;
    }
    return s;
}
int main() {
    int n,o_parens;
    const int ZERO=0x30;
    cin >> n;
    n++;
    for (int q=1;q<n;q++) {
        cout << "Case #" << q << ": ";
        string s;
        cin >> s;
        o_parens=s[0]-ZERO;
        string r = rp(o_parens,"(") + to_string(s[0]-ZERO);
        int diff;
        for (int i=1; i<s.length();i++) { // s[1:]
            diff= s[i] - s[i-1];
            o_parens+=diff;
            if (diff < 0){ // smaller, close parens
                r+=rp(-diff,")");
            }
            else if (diff) { // bigger, open parens
                r+=rp(diff,"(");
            }
            r+=to_string(s[i]-ZERO);
        }
        cout << r + rp(o_parens,")") << '\n';
    }
}
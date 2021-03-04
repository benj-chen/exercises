#include <string>
#include <iostream>

using namespace std;
string rp(int i,string c) { // repeated string of c, i times
    string s;
    while (i--) s+=c;
    return s;
}
int main() {
    int n,o_parens;
    const char ZERO=0x30; // ASCII 48, saying 0x30 is way cooler
    cin >> n;
    n++;
    for (int q=1;q<n;q++) {
        cout << "Case #" << q << ": ";
        string s;
        cin >> s;
        o_parens=s[0]-ZERO;
        string r = rp(o_parens,"(") + to_string(o_parens);
        int diff;
        for (int i=1; i<s.length();i++) { // s[1:]
            o_parens+= diff = s[i] - s[i-1];
            if (diff < 0) r+=rp(-diff,")"); // smaller, close parens
            else if (diff) r+=rp(diff,"(");  // bigger, open parens
            r+=to_string(s[i]-ZERO);
        }
        cout << r << rp(o_parens,")") << '\n';
    }
}
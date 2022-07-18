#include <iostream>
#include <vector>
// previously did day 1 early
#include <fstream>
using namespace std;
ifstream fin("in");
int main() {
    int ct = 0;
    for (int i=284639; i<=748759;i++) {
        string s = to_string(i);
        // 2 dig check
        bool ok = false;
        for (int j=1;j<s.size();j++) {
            if (s[j]==s[j-1])
            ok = true;
            if (s[j-1]>s[j]) {
                ok = false; break;
            }
        }
        if (ok)
        ct++;
    }
    cout << ct << endl;
    // 63871 too high
}
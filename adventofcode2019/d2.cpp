#include <iostream>
#include <map>
// previously did day 1 early
#include <fstream>
using namespace std;
ifstream fin("in");
int main() {
    int ct = 0;
    for (int i=284639; i<=748759;i++) {
    // if (true) { int i = 112233;
        string s = to_string(i);
        int rep = 0;
        // 2 dig check
        bool ok = false;
        for (int j=1;j<s.size();j++) {
            if (s[j]==s[j-1]) {
                rep++;
            }
            else {
                if (rep==1) {
                    ok = true;
                }
                rep=0;
            }
            if (s[j-1]>s[j]) {
                ok = false; break;
            }
        }
        if(rep == 1) {
            ok = true;
        }
        if (ok)
        ct++;
    }
    cout << ct << endl;
    // 449 too low
}
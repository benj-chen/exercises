#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int countplus(string &s) {
    int ct=0;
    for (char &c: s) {
        if (c=='+') ct++;
    }
    return ct;
}

int main() {
    string s;
    cin >> s;
    int pluscount=countplus(s)+1,loc=0, elem=0;
    int inp[pluscount];
    for (char &c: s) {
        if (c=='+') {
            inp[loc++]=elem;
            elem=0;
        }
        else elem=(elem*10)+c-48; // ascii number 0 starts at dec 48.
    }
    inp[loc]=elem;
    sort(inp,inp+pluscount);
    cout << inp[0];
    bool firsttime=1;
    for (int &i: inp) {
        if (firsttime) {
            firsttime=0;
            continue;
        }
        cout <<'+' << i;
    }
    cout << "\n";
}
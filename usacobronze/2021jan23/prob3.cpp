#include <algorithm>
#include <iostream>

using namespace std;
bool gr(int a, int b) {return a>b;}
int main() {
    int n,len,takeout=0;
    cin >> n;
    int c[n],s[n];
    for (int i=0;i<n;i++) cin >> c[i];
    for (int i=0;i<n;i++) cin >> s[i];
    long long prod=1;
    sort(c,c+n,gr);
    sort(s,s+n);
    for (int i: c) {
        len=0;
        for (int y: s) if (i<=y) len++;
        prod*=len-takeout++;
    }
    cout << prod << endl;
}
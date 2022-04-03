#include <bits/stdc++.h>
using namespace std;
int main() {
    // treat x and y separately
    int n; cin >> n;
    int xg,yg; cin >> xg >> yg;
    int x[n], y[n];
    for (int i=0;i<n;i++) cin >> x[i] >> y[i];
    vector<long long> possx, possy; // 40 bits: 1 if included, 0 if not
    for (long long i = 0; i< (1LL<<40LL); i++) {
        int k = i + 1;
    }
    cout << "ok" << endl;
}
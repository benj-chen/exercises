#include <bits/stdc++.h>
// had to submit multiple times to figure out:
// don't use fmin
// use unsigned long long
// but I had the correct logic from the start
// optimized later
using namespace std;
int main() {
int T;
cin >> T;
T++;
for (int t=1;t<T;t++) {
    int N,K,S;
    cin >> N >> K >> S;
    // restart
    cout << "Case #" << t << ": " << K+N + (K-S-S<0? K-S-S : 0) << endl;
}
}
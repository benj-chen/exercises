#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>

// Smallest number evenly divisible among 1-20
vi factors_of(int i) {
    vi res;
    restart:;
    if (i==1) return res;
    FOR(a,2,i+1) { // always mod 1
        if (i%a==0) {
            res.push_back(a);
            i/=a;
            goto restart;
        }
    }
    return res;
}
int main() {
    int res=1;

    FOR(i,1,21) {
        EACH(j,factors_of(i)) {
            if (res%j==0) {
                res/=j;
            }
        }
        res*=i;
    }
    cout << res << endl;
}
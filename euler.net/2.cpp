#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(a) for (int i=0;i<a;i++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define pii pair<int,int>
#define vi vector<int>
int sum=0;
int main() {
    // fibonacci numbers alternate between odd and even
    // start with 1 and 2
    int o=1, e=2, sum=0;
    while (max(o,e) < 4000000) {
        o+=e;
        e+=o;
        if (!(o%2)) sum+=o;
        if (!(e%2)) sum+=e;
    }
    cout << sum << endl;
    return 0;
}
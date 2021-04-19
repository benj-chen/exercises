#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
#define FOR(a,st,b) for (ull a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>

ull sumrange(ull st, ull end) {
    assert (end>=st);
    return (st+end)*(end-st+1)>>1;
}
bool isnt_prime(ull a) {
    if (a==1) return true;
    if (a==2) return false;
    if (a%2==0) return true;
    FOR(i,3,a) if (a%i==0) return true;
    return false;
}
int main() {
    // generate all the non-primes below two million, then subtract the sum of 1 to two million from that
    // statistically a number is more likely to be composite than prime
    ull total=sumrange(1,2000000);
    ull total2=0;
    FOR(i,1,2000001) {
        if (isnt_prime(i)) {
            total2+=i;
        }
    }
    cout << total-total2 << endl;
    cout << total << endl;
    cout << total2 << endl;
}
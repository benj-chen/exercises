#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
#define FOR(a,st,b) for (ull a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>
ull sieve(int q) {
    // find all the prime numbers under the int q, has to be in int range because vectors can't hold that large
    // modded
    vector<bool> prime;
    prime.resize(q*q);
    for (int i=2;i<q;i++) {
        prime[i]=1;
    }
    ull res=0;
    for (int i=2;i<q;i++) {
        if (prime[i]) {
            // start from i*i
            for (ll j=i*i;j<q;j+=i) prime[j]=0;
            res+=i;
        }
    }
    return res;
}
int main() {
    cout << sieve(2e6) << endl;
}
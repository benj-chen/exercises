#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
using pii = pair<int,int>;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>
#define alg_type vi // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
#define f first
#define s second
vi sieve(int q) {
    // find all unique prime numbers under the int q, has to be in int range because vectors can't hold that large
    vector<bool> prime;
    prime.resize(q+3);
    for (int i=2;i<q;i++) {
        prime[i]=1;
    }
    vi res;
    for (int i=2;i<q;i++) {
        if (prime[i]) {
            // start from i*i
            for (int j=i;j<q;j+=i) prime[j]=0; // int max * int max obviously goes over int range, this can be solved by resizing the vector but that's sorta pointless
            res.push_back(i);
        }
    }
    return res;
}
int main() {
    vi primes = sieve(2e7); // 2e9 is technically nearing the limit but takes a bit long
    


}
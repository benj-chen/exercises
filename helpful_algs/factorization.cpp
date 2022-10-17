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
vi prime_factors(int q) {
    // import sieve with this
    int prod=1;
    vi f = sieve(q);
    vi res;
    start:;
    for (int i: f) {
        if (!(q%i)) {
            q/=i;
            res.push_back(i);
            goto start;
        }
    }
    return res;
}
string binary_representation(ll i) {
    // i must be positive
    if (!i) return "0";
    assert (i>0);
    string res="";
    while (i) {
        res+=to_string(i>>1<<1!=i);
        i>>=1;
    }
    reverse(begin(res),end(res));
    return res;
}
vi factors(int n)
{
    vi res;
    double sqrtn=sqrt(n);
    for (int i=1; i<=sqrtn; i++)
    {
        if (n%i == 0)
        {
            res.push_back(i);
            if (n/i!=i) res.push_back(n/i);
        }
    }
    return res;
}
bool is_prime(int n) {
    // replace with ll or ull as needed
    int s = sqrt(n);
    // 2 for speed
    if (n>>1<<1==n) return false;
    for (int i=3;i<=s;i+=2) if (!(n%i)) return false;
    return true;
}
int lcm(int a, int b) {
    auto fact = [](int n){
        map<int,int> res;
        // import sieve with this
        int prod=1;
    vi f = sieve(n);
    start:;
    for (int i: f) {
        if (!(n%i)) {
            n/=i;
            res[i]++;
            goto start;
        }
    }
    return res;
    };
    
    map<int,int> pfa = fact(a), pfb = fact(b);
    for (pair<int,int> i: pfa) {
        pfb[i.first] = fmax(pfb[i.first],i.second);
    }
    int res = 1;
    for (pair<int,int> i: pfb) {
        for (int j=0;j<i.second;j++) res*=i.first;
        cout << res << endl;
        cout << i.first << " "<<i.second << endl;
    }
    return res;
}
int main() {
    cout << lcm(60,72) << endl;
    auto i = prime_factors(60);
    auto j = prime_factors(72);
    for (int k: i) cout << k << endl;
    cout << endl;
    for (int k: j) cout << k << endl;
}
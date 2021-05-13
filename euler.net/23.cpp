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
#define alg_type int // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
#define f first
#define s second

map<int,bool> m; // true if it is abundant
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
void build_sum(int n) {
    vi f = factors(n);
    int sum=-n;
    for (int i: f) sum+=i;
    m[n]=(sum>n);
}

int main() {
    ull sum=0, magic_number=28123+1; // everything under magic number might not be written as the sum of two abundant numbers
    FOR(i,1,magic_number) {
        build_sum(i);
        // test every addition pair
        FOR(j,1,2+(i>>1)) {
            if (m[j] && m[i-j])
                // don't care
                goto end;
        }
        sum+=i;
        end:;
    }
    cout << sum << endl;
}
// i was close... exactly the right idea but poor execution
#include<bits/stdc++.h>
#define f(n) for(int i=0;i<n;i++)
// print vectors with space delimiter
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];return out;}
using namespace std;
struct stype {
    int q,l,v;
    stype(int q, int l, int v): q(q), l(l), v(v) {}
    bool operator<(stype other) {
        return this->l < other.l;
    }
};
bool cust_comp(stype a, stype b) {
    // comp by price
    return a.v > b.v;
}
int main() {int T; cin >> T;T++;for(int t=1;t<T;t++) {
    int d,n,x; cin >> d >> n >> x;
    vector<stype> seeds;
    f(n) {
        int q,l,v; cin >> q >> l >> v;
        seeds.push_back(stype(q,l,v));
    }
    sort(seeds.begin(),seeds.end());
    // the first seeds[0].l days: no planting
    d -= seeds[0].l;
    // quickest growing is first
    int upto = 0; // upto, which changes with each while iteration, represents the possible seeds to choose from.
    int interval = -1;
    auto upd = [&]() {
        if (upto >= n) return n+1; // finish
        if (upto==n-1) {
            upto = n;
            interval = 1;
            return n;
        }
        // work up until the initial upto and the current upto l value differ
        int initl = seeds[upto].l;
        while (seeds[++upto].l == initl) {
            if (upto==n-1) {
                // last interval
                interval = d;
                upto = n;
                return upto;
            }
        }
        interval = seeds[upto].l - initl;  
        return upto;
    };
    long long total = 0;
    while (upd() <= n and d>0) {
        // sort the list up to upto by value
        sort(seeds.begin(),seeds.begin()+upto,cust_comp);
        // number of seeds to get is interval (++, --??) * x
        if (interval > d) interval = d;
        int to_grow = interval * x;
        d -= interval;
        // for (int i=0;i<upto;i++) {
            // "it's growing time" --growius
            while (to_grow >0) {
                // find highest seed
                int seed_spot = -1;
                while (seeds[++seed_spot].q == 0) {
                    if (seed_spot == upto - 1) /*nothing to grow*/ {seed_spot = upto; break;}}
                if (seed_spot >= upto) break;
                if (to_grow >= seeds[seed_spot].q) {
                    total += seeds[seed_spot].q * seeds[seed_spot].v;
                    to_grow -= seeds[seed_spot].q;
                    // cout << "     " << seeds[seed_spot].q << " " <<seeds[seed_spot].v << endl;

                    seeds[seed_spot].q = 0;
                }
                else {
                    total += to_grow * seeds[seed_spot].v;
                    // cout << "     " << to_grow << " " <<seeds[seed_spot].v << endl;
                    seeds[seed_spot].q -= to_grow;
                    to_grow = 0;
                }
            }
        // }
        // cout << endl<<
            // "end day" << " " << to_grow << " "<< interval  << " " << upto << endl;
    }
    cout << "Case #" << t << ": " << total << endl;
}
}

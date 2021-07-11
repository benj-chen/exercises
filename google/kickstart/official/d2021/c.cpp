// template for comps
// aaaaaa should have used upper_bound, I even had that idea but didn't have the brain to implement it.. because it was 1am.
// I had the idea that the analysis had tho! I'll consider this a win.
#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define pq priority_queue
#define f first
#define s second
#define ar array

#define F(i,n)for(int i=0;i<n;i++)
#define FO(i,sa,n)for(int i=sa;i<n;i++)
#define FOR(i,sa,n,sp)for(int i=sa;i<n;i+=sp)

#define all(c)(c).begin(),(c).end()
// #define iter(c,ind)(ind<0?:(c).end()+ind+1,0)
// #define iter_f(c,ind) ((c).begin()+ind)
// #define iter_b(c,b_ind)((c).end()-b_ind)
// #define iter_b2(c,b_ind)((c).begin()+(c).size()-b_ind)
// ((c).begin()+c.size()-b_ind)
using ll = long long;
using vi = vt<int>;
using vl = vt<ll>;
using vvi = vt<vi>;
using vvl = vt<vl>;
using vvvi = vt<vvi>;
using vvvl = vt<vvl>;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

using vpii = vt<pii>;
using vpll = vt<pll>;

// print vectors with space delimiter because that's more common with comps
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];return out;}
// int binary_search_index(vpll& v, ll i, int l, int r) {
//     // to see if it exists (bool), use std::binary_search(begin, end, item);
//     if (r >= l) {
//         int mid = l + (r - l) / 2;
//         if (v[mid].first == i)
//             return mid;
//         if (v[mid].first > i)
//             return binary_search_index(v, i, l, mid - 1);
//         return binary_search_index(v, i, mid + 1, r);
//     }
//     return l; // return r?
// }
int look(vpll& v, ll n) {
    FO(i,1,v.size()) {
        if (v[i].first>n) return i-1;
    }
    return v.size()-1; // should be v.size(), but avoid segfault for now
}
void solve() {
    int n,m;
    cin >> n >> m;
    vpll psets = {make_pair(0,0)};
    F(i,n) {
        ll a,b;
        cin >> a >> b;
        psets.push_back(make_pair(a,b));
    }
    sort(psets.begin(),psets.end());
    F(t,m) {
        ll s;
        cin >> s;
        int ind = look(psets,s); // snaps down for linear search
        // look at the current one, and the one after, to find the diff
        // k.i.m that 0,0 is the first index and can't be used as a pset
        // for (auto a: psets) {
        //     cerr << a.first << " " << a.second << endl;
        // }
        if (ind==0) {
            // take the first first
            cout << " " << psets[1].first;
            psets[1].first++;
            if (psets[1].first>psets[1].second) psets.erase(psets.begin()+1);
            continue;
        }
        // if ind == v.size()-1 and exceeds the last last, take the last last
        if (ind==psets.size()-1 && s>psets.back().second) {
            cout << " " << psets.back().second;
            psets.back().second--;
            if (psets.back().first>psets.back().second) psets.pop_back();
            continue;
        }
        
        if (psets[ind].first<=s && s<=psets[ind].second) {
            // s is in there
            psets.insert(psets.begin()+ind,psets[ind]); // duplicate
            psets[ind].second=s-1;
            psets[ind+1].first=s+1;
            if (psets[ind+1].first>psets[ind+1].second) psets.erase(psets.begin()+ind+1);
            if (psets[ind].first>psets[ind].second) psets.erase(psets.begin()+ind);
            cout << " " << s;
        }
        else {
            // s aint in there
            int dl,dr; // delta left, right
            dl = s-psets[ind].second;
            dr=psets[ind+1].first-s;
            if (dr<dl){
                // take right
                cout << " " << psets[ind+1].first;
                psets[ind+1].first++;
                if (psets[ind+1].first>psets[ind+1].second) psets.erase(psets.begin()+ind+1);
            }
            else {
                cout << " " << psets[ind].second;
                psets[ind].second--;
                if (psets[ind].first>psets[ind].second) psets.erase(psets.begin()+ind);
            }
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    T++;
    FO(t,1,T) {
        cout << "Case #" << t << ":";
        solve();
    }
}
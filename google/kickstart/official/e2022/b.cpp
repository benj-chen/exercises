// b
#include<bits/stdc++.h>
#define f(j) for (int i=0;i<j;i++)
using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){out<<'{';if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];out<<'}';return out;}

template<typename T, typename U>
ostream& operator<<(ostream& out, const pair<T,U> p){out << '(' << p.first << ","<<p.second<<')';return out;}

int binary_search_up(vi& v, int i, int l, int r) { // too high: v.size()+2

    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (v[mid] == i)
            return mid;
        if (v[mid] > i)
            return binary_search_up(v, i, l, mid - 1);
        return binary_search_up(v, i, mid + 1, r);
    }
    return l; // snap up
}

// int main(int argc, char** argv) {ifstream cin(argv[1]);
int main() {
    // vi v = {1,2,3,4};
    // cout << binary_search_up(v,-1,0,v.size());
    // return 0;

    // vi v = {1,2,3,4};
    // int j = v[0];
    // v.erase(v.begin()+0);
    // v.insert(v.begin()+0,j);
    // cout << v << endl;
    // return 0;
int T;cin>>T;T++;for(int t=1;t<T;t++) {
    int n; cin >> n;
    vi v(n);
    f(n) cin >> v[i];
    vi c = v;
    map<int,int> res;
    sort(v.begin(),v.end());
    // exception: biggest
    cout << "Case #" << t << ":"; // no space
    // exception: smallest
    for (int i=1;i<n-1;i++) if (res[v[i]]==0){
        // temp erase: diff duplicates
        int j = v[i];
        // binary search for i*2
        int ind = binary_search_up(v,j*2+1,0,v.size());
        // too big: max works
        if (ind==n+2)
            // cout << " " << v.back();
            res[j]=v.back();
        // too small: -1
        else if (ind==0/* and v[ind] > (j*2)*/) {
            if (v[ind]> j*2)
                res[j]=-1;
            else{
                res[j]=v[0];
            }
            // cout << " " << -1;
        }
        else {
            // take that -1
            // cout << " " <<v[ind-1];
            res[j]=v[ind-1];
            // if (res[j] == j and count(v.begin(),v.end(),j)==1) {
            //     // change
            //     if (ind>2) res[j]=v[ind-2];
            //     else res[j]=-1;
            // }
        }
        // restore
    }
    // biggest: second to last
    // cout << " " << v[n-2] << endl;
    res[v[n-1]]=v[n-2];
    for (int i: c) {
        cout << " " << res[i];
    }
    cout << endl;
}}
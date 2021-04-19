#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>
#define alg_type int // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
int binary_search_index(alg_vec_type& v, alg_type i, int l, int r) {
    // to see if it exists (bool), use std::binary_search(begin, end, item);
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (v[mid] == i)
            return mid;
        if (v[mid] > i)
            return binary_search_index(v, i, l, mid - 1);
        return binary_search_index(v, i, mid + 1, r);
    }
    return -1; 
}
int main() {
    vi a = {1,2,3,4,5};
    cout << binary_search_index(a,5,0,5) << endl;
}
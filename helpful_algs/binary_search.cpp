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
int binary_search_up(alg_vec_type& v, alg_type i, int l, int r) {

    if (r > l) {
        int mid = l + (r - l) / 2;
        if (v[mid] == i)
            return mid+1;// snap up
        if (v[mid] > i)
            return binary_search_up(v, i, l, mid - 1);
        return binary_search_up(v, i, mid + 1, r);
    }
    return l; // snap up
}

int main() {
    vi a = {2,4,6,8,8,10,10};
    cout << binary_search_up(a,0,0,a.size()) << endl;;
    cout << binary_search_up(a,1,0,a.size()) << endl;;
    cout << binary_search_up(a,2,0,a.size()) << endl;;
    cout << binary_search_up(a,3,0,a.size()) << endl;;
    cout << binary_search_up(a,4,0,a.size()) << endl;;
    cout << binary_search_up(a,6,0,a.size()) << endl;;
    cout << binary_search_up(a,7,0,a.size()) << endl;;
    cout << binary_search_up(a,8,0,a.size()) << endl;;
    cout << binary_search_up(a,10,0,a.size()) << endl;;
    cout << binary_search_up(a,11,0,a.size()) << endl;;
    cout << binary_search_up(a,12,0,a.size()) << endl;;
}
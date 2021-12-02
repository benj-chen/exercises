#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
#define vt vector
#define vi vector<int>
#define alg_type int // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
// unsorted is generally faster than sorted on larger datasets
vt<alg_vec_type> all_perms(alg_vec_type& l) {
    if (l.empty()) return {{}};
    vt<alg_vec_type> res;
    for (int i=0;i<l.size();i++) {
        int add_back=l[i];
        l.erase(l.begin()+i);
        for(alg_vec_type y: all_perms(l)) {
            y.push_back(add_back);
            res.push_back(y);
        }
        l.insert(l.begin()+i,add_back);
    }
    sort(res.begin(),res.end());
    return res;
}
vt<alg_vec_type> all_perms_unsorted(alg_vec_type& l) {
    if (l.empty()) return {{}};
    vt<alg_vec_type> res;
    for (int i=0;i<l.size();i++) {
        int add_back=l[i];
        l.erase(l.begin()+i);
        for(alg_vec_type y: all_perms(l)) {
            y.push_back(add_back);
            res.push_back(y);
        }
        l.insert(l.begin()+i,add_back);
    }
    return res;
}
vt<alg_vec_type> unique_perms(alg_vec_type& l) {
    if (l.empty()) return {{}};
    set<alg_vec_type> res;
    for (int i=0;i<l.size();i++) {
        int add_back=l[i];
        l.erase(l.begin()+i);
        for(alg_vec_type y: all_perms(l)) {
            y.push_back(add_back);
            res.insert(y);
        }
        l.insert(l.begin()+i,add_back);
    }
    return vt<alg_vec_type>(res.begin(),res.end());
}
vt<alg_vec_type> unique_perms_unsorted(alg_vec_type& l) {
    if (l.empty()) return {{}};
    unordered_set<alg_vec_type> res;
    for (int i=0;i<l.size();i++) {
        int add_back=l[i];
        l.erase(l.begin()+i);
        for(alg_vec_type y: all_perms(l)) {
            y.push_back(add_back);
            res.insert(y);
        }
        l.insert(l.begin()+i,add_back);
    }
    return vt<alg_vec_type>(res.begin(),res.end());
}
int main() {
}
#include<bits/stdc++.h>
using namespace std;
struct fab {
    string s;
    int d, u;
    fab(string s, int d, int u): s(s), d(d), u(u) {}
    bool operator==(fab b) {
        return this->u == b.u;
    }
};
bool sorta(fab a, fab b) {
    // lex
    if (a.s == b.s) {
        return a.u < b.u;
    }
    return a.s < b.s;
}
bool sortb(fab a, fab b) {
    // d
    if (a.d == b.d) {
        return a.u < b.u;
    }
    return a.d < b.d;
}
int main(){
int T;cin>>T;T++;for(int t=1;t<T;t++) {
    int n; cin >> n;
    string a; int b; int c;
    vector<fab> items;
    for (int i=0;i<n;i++) {
    cin >> a >> b >> c;
    fab f(a,b,c);
    items.push_back(f);
    }
    vector<fab> d = items, e = items;
    sort(d.begin(),d.end(),sorta);
    sort(e.begin(),e.end(),sortb);
    int ct=0;
    for (int i=0;i<n;i++) {
        if (d[i]==e[i]) ct++;
    }
    cout << "Case #" << t << ": " << ct << endl;
}
}
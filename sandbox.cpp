#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define F(i,n)for(int i=0;i<n;i++)
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];return out;}
vi v;
int f(int a) { // to apply this to the values themselves, lower everything by 1
    while (a<0 || a>=v.size()) { // should only ever need to do this once for this problem
    if (a<0) a+=v.size();
    if (a>=v.size()) a-=v.size();}
    return a;
}
int cind = 0, c;
bool same(vi v, vi u) {
    if (v.size()!=u.size()) return 0;
    F(i,v.size()) {
        if (v[i]!=u[i]) return 0;
    }
    return 1;
}
void cut_paste(int st, int en, int len = 3)
{
    int elem = v[en];
    vi rm;
    F(i,len) rm.push_back(v[f(st+1+i)]);
    // erase
    F(i,len) {
        int ind = i+1+st;
        if (ind>=v.size()) ind-=v.size();
        v.erase(v.begin()+ind);
    }
    // re-add them after elem
    F(i,v.size()) {
        if (v[i]==elem) {
            v.insert(v.begin()+i, )
        }
    }
    // vi rm, other;
    // F(i,len) rm.push_back(v[f(st+1+i)]);
    // bool prepost = 0;
    // F(i,v.size()) {
    //     F(j,len) {
    //         if (v[i]==rm[j]) {
    //             goto end;
    //         }
    //     }
    //     other.push_back(v[i]);
    //     end:;
    // }
    // vi res;
    // for (int i: other) {
    //     res.push_back(i);
    //     if (i==v[en]) {
    //         for (int j: rm) {
    //             res.push_back(j);
    //         }
    //     }
    // }
    // v = res;
}
void foo(int st, int en, int len=3) {
    // take v[st], v[st+1], v[st+2] and insert them to be at v[en+1], v[en+2], v[en+3]- direction 3 of the instructions
    int origstval = v[st];
    vi rm;
    F(i,len) rm.push_back(v[f(st+i)]);
    // insert - be careful because f() will mess up because v.size() changed
    F(i,len) {
        v.insert(v.begin()+en,rm[len-i-1]);
    }
    // remove
    int bonus=0;
    if (v[st]!=origstval) bonus=3;
    if (st+bonus < v.size() && st+bonus+len >= v.size()) {
        // the 3 that need to be erased are at the front and back
        // one situation: 2 front, 1 back should be 1 front, 2 back
        F(i,len) {
            if (st+bonus < v.size()) {
                v.erase(v.begin()+st+bonus);
            }
            else v.erase(v.begin());
        }
    }else F(i,len) {
        v.erase(v.begin()+(st+bonus >= v.size() ? st+bonus-v.size():st+bonus)); // problem
    }
}
void solve() {
    // find destination cup
    c = v[cind];
    int d=-1, dind=-1;
    F(i,v.size()) {
        int real = f(c-i-1);
        // if it's not one of the three indices after c then ok
        if (real!=v[f(cind+1)] && real!=v[f(cind+2)] && real!=v[f(cind+3)]) {
            d=real;
            break;
        }
    }
    F(i,v.size()) if (v[i]==d) {
        dind=i;break;
    }
    cut_paste(cind,dind);
    // cind = f(cind+1);
    // find c again
    F(i,v.size()) {
        if (v[i]==c) {
            cind=f(i+1);
            return;
        }
    }
}
int main() {
    string s;
    cout << "puzzle input: " << endl;
    cin >> s;
    for (char c: s) {
        v.push_back(c-'0'-1); // 1 becomes 0, 2 becomes 1 - see f()
    }
    c = v[0];
    int times=100;
    F(i,times) solve();
    // add 1 back to everything
    for (int& i: v) i++;
    cout << v << endl;
    int reach1 = false;
    string pre1,post1;
    F(i,v.size()) {
        if (v[i]==1) reach1=true;
        if (reach1) {
            post1+=string(1,'0'+v[i]);
        }
        else pre1+=string(1,'0'+v[i]);
    }
    cout << post1.substr(1)+pre1 << endl;
    
}


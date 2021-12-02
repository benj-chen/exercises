#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define F(i,n)for(int i=0;i<n;i++)
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];return out;}

int f(int a) { // to apply this to the values themselves, lower everything by 1
    while (a<0 || a>=v.size()) { // should only ever need to do this once for this problem
    if (a<0) a+=v.size();
    if (a>=v.size()) a-=v.size();}
    return a;
}
bool same(vi v, vi u) {
    if (v.size()!=u.size()) return 0;
    F(i,v.size()) {
        if (v[i]!=u[i]) return 0;
    }
    return 1;
}
void cut_paste(int st, int en, int len = 3)
{
    vi rm, other;
    F(i,len) rm.push_back(v[f(st+1+i)]);
    bool prepost = 0;
    F(i,v.size()) {
        F(j,len) {
            if (v[i]==rm[j]) {
                goto end;
            }
        }
        other.push_back(v[i]);
        end:;
    }
    vi res;
    for (int i: other) {
        res.push_back(i);
        if (i==v[en]) {
            for (int j: rm) {
                res.push_back(j);
            }
        }
    }
    v = res;
}
void foo() {
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
int cind = 0, c;
vi v;
queue<int> rm;
void solve() {
}
int main() {
    string s;
    cout << "puzzle input: " << endl;
    cin >> s;
    for (char c: s) {
        v.push_back(c-'0'-1); // 1 becomes 0, 2 becomes 1 - see f()
    }
    rm.push(v[1]);
    int times=100;
    F(i,times) {solve(); cout << v << endl;}
    // add 1 back to everything
    for (int& i: v) i++;
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

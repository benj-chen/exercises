#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(a) for (int i=0;i<a;i++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define pii pair<int,int>
using ul = unsigned long;
ul big_number;
priority_queue<ul> prime_factors;
void reduce_to_odd() {
    cout << big_number << endl;
    while ((big_number>>1<<1)==0) big_number>>=1;
    cout << big_number << endl;
}

string digits() {return to_string(big_number);}
vector<ul> factors;
void solve() {
    if (big_number==1) return;
    if (digits().back()=='5') {
        factors.push_back(5);
        big_number/=5;
        solve();
    }
    for (ul i=0;i<=big_number;i+=10) {
        int j=1;
        if (!i) j=3;
        for (;j<10;j+=(j==3? 4:2)) {
            ul num = i+j;
            if (big_number % num==0) {
                big_number/=num;
                factors.push_back(num);
                solve();
            }
        }
    }
}
int main() {

    // return 0;
    big_number=600851475143;
    solve();
    for (int i=0;i<factors.size();i++) {
        // see if it's actually prime. Technically not necessary for this test case. I just got lucky.

        for (int j=2;j<factors[i]/2;j++) {
        
            if (factors[i]%j==0) {
                factors.push_back(factors[i]/j);
                factors.push_back(j);
                factors.erase(factors.begin()+i);
            }
        }
    }
    sort(begin(factors),end(factors));
    cout << factors.back() << endl;

}
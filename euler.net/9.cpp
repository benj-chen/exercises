#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>


int sq(int a) {return a*a;}
int main() {
    // There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
    FOR(a,1,1000) FOR(b,a,1000) FOR(c,b,1000) 
        if (a+b+c==1000) 
            if (sq(a)+sq(b)==sq(c)) {
                cout << a*b*c << endl;
                return 0;
            }
    return -1;
}
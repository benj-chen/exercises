#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
using pii = pair<int,int>;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>
#define alg_type vi // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
#define f first
#define s second
map<int,int> tens,res;
void build_ones() {
    res = {
        {1,3},//"one"
        {2,3},
        {3,5},
        {4,4},
        {5,4},
        {6,3},
        {7,5},
        {8,5},
        {9,4},
        {0,0} // zero is special becuase you wouldn't say a hundred zero
    };
}
void build_tens() {
    // don't count hyphens/spaces
    // 10,20, etc. are special cases, as are [11,19]
    
    for (pii p: (map<int,int>){
        {10,3},
        {20,6},
        {30,6},
        {40,5},
        {50,5},
        {60,5},
        {70,7},
        {80,6},
        {90,6},
        {11,6},
        {12,6},
        {13,8},
        {14,8},
        {15,7},
        {16,7},
        {17,9},
        {18,8},
        {19,8}
    }) res[p.f]=p.s;
    for (int i=2;i<10;i++) {
        
        int ten=i*10;
        for (int j=1;j<10;j++) { // 0 already handled
            res[ten+j]=res[ten]+res[j];
        }
    }

}
void build_hundreds() {
    // don't count spaces
    for (int i=1;i<10;i++) {
        res[i*100]=res[i]+10; // "hundredand" is 3
        for (int j=1;j<100;j++) {
            res[i*100+j]=res[i*100]+res[j];
        }
        res[i*100]-=3; // remove "and"
    }
}
void build_thousands() {
    // technically not necessary
    for (int i=1;i<10;i++) {
        res[i*1000]=res[i] + 11; // "thousandand" is 11
        for (int j=1;j<1000;j++) {
            res[i*1000+j]=res[i*1000]+res[j];
        }
        res[i*1000]-=3; 
    }
}
int main() {
    build_ones();
    build_tens();
    build_hundreds();
    build_thousands(); // or just add 11 to sol, since "onethousand" is 11
    int sol = 0;
    for (int i=1;i<=1000;i++) sol+=res[i];
    cout << sol << endl;
}

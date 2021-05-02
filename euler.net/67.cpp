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
vt<vi> triangle;
void get_input() {
    ifstream in("67.txt");
    triangle.resize(100);
    FOR(i,1,101) {
        triangle[i-1].resize(i);
        FOR(j,0,i) in >> triangle[i-1][j];
    }
}
void simplify_layer(int row) {
    // first call should be the second row from the bottom
    int cols = triangle[row].size();
    FOR(i,0,cols) {
        triangle[row][i]+=fmax(triangle[row+1][i],triangle[row+1][i+1]);
    }
}
int main() {
    get_input();
    // prefix sums essentially? graph simplifying or whatever fancy term
    // start at the bottom and simplify the two numbers below it
    for (int i=triangle.size()-2;i>-1;i--) {
        simplify_layer(i);
    }
    cout << triangle[0][0] << endl;
}
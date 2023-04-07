
#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
#define fr(i,m,n) for (int i=m;i<n;i++)
#define fo(i,n) fr(i,0,n)
#define f(n) fo(i,n)
using namespace std;

int main() {

    int n; cin >> n;
    char a[n][n];
    int p_row[n],
        p_col[n];
    f(n) {
        string s;
        cin >> s >> p_row[i];
        fo(j,n) a[i][j] = s[j];
    }
    f(n) cin >> p_col[i]
    ;
    // for (int i: p_col) cout << i << " ";
    // cout << endl;
    // for (int i: p_row) cout << i << " ";
    // cout << endl;
    // f(n) fo(j,n) cout << a[i][j] << endl;
    
    // pre query
    // cols
    int pr = 0;
    f(n) {
        queue<pair<int,int>> sets;
        if (a[n-1][i] == 'D') {
            sets.push({n-1,i});
            //pr += p_col[i];
        }
        while (sets.size()) {
            pair<int,int> p = sets.front();
            sets.pop();
            pr += p_col[i];
            if (p.first > 0) {
                if (a[p.first-1][p.second] == 'D') {
                    sets.push({p.first-1,p.second});
                }
            }
            if (p.second > 0) {
                if (a[p.first][p.second-1] == 'R') {
                    sets.push({p.first,p.second-1});
                }
            }
        }
    }
    // row
    f(n) {
        queue<pair<int,int>> sets;
        if (a[i][n-1] == 'R') {
            sets.push({i,n-1});
        }
        while (sets.size()) {
            pair<int,int> p = sets.front();
            sets.pop();
            pr += p_row[i];
            if (p.first > 0) {
                if (a[p.first-1][p.second] == 'D') {
                    sets.push({p.first-1,p.second});
                }
            }
            if (p.second > 0) {
                if (a[p.first][p.second-1] == 'R') {
                    sets.push({p.first,p.second-1});
                }
            }
        }
    }
    cout << pr << endl;
    int q; cin >> q;
    f(q) {
        int w,e; cin >> w >> e;
        w--;e--;
        if (a[w][e] == 'D') a[w][e] = 'R';
        else a[w][e] = 'D';
        
    // f(n) fo(j,n) cout << a[i][j] << endl;
    int pr = 0;
    f(n) {
        queue<pair<int,int>> sets;
        if (a[n-1][i] == 'D') {
            sets.push({n-1,i});
            //pr += p_col[i];
        }
        while (sets.size()) {
            pair<int,int> p = sets.front();
            sets.pop();
            pr += p_col[i];
            if (p.first > 0) {
                if (a[p.first-1][p.second] == 'D') {
                    sets.push({p.first-1,p.second});
                }
            }
            if (p.second > 0) {
                if (a[p.first][p.second-1] == 'R') {
                    sets.push({p.first,p.second-1});
                }
            }
        }
    }
    // row
    f(n) {
        queue<pair<int,int>> sets;
        if (a[i][n-1] == 'R') {
            sets.push({i,n-1});
        }
        while (sets.size()) {
            pair<int,int> p = sets.front();
            sets.pop();
            pr += p_row[i];
            if (p.first > 0) {
                if (a[p.first-1][p.second] == 'D') {
                    sets.push({p.first-1,p.second});
                }
            }
            if (p.second > 0) {
                if (a[p.first][p.second-1] == 'R') {
                    sets.push({p.first,p.second-1});
                }
            }
        }
    }
    cout << pr << endl;
    }
}
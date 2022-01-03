#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define pq priority_queue
#define f first
#define s second
#define ar array

#define F(i,n)for(int i=0;i<n;i++)
#define FO(i,sa,n)for(int i=sa;i<n;i++)
#define FOR(i,sa,n,sp)for(int i=sa;i<n;i+=sp)

#define all(c)(c).begin(),(c).end()
#define iter(c,ind)(ind<0?(c).end()+ind:(c).begin()+ind)
// iter does c[ind] perfectly on any container assuming one index

using ll = long long;
using vi = vt<int>;
using vl = vt<ll>;
using vvi = vt<vi>;
using vvl = vt<vl>;
using vvvi = vt<vvi>;
using vvvl = vt<vvl>;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

// print vectors with space delimiter
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];return out;}

int main() {
    string onoff;
    // vector<vector<vector<bool>>> board = {{{0}}};
    map<array<int,3>, bool> board;
    
    while (cin>>onoff) {
        int x1,x2,y1,y2,z1,z2;
        cin.ignore(3);
        cin >> x1;
        cin.ignore(2);
        cin >> x2;
        cin.ignore(3);

        cin >> y1;
        cin.ignore(2);

        cin >> y2;
        cin.ignore(3);
        cin >> z1;
        cin.ignore(2);
        cin>>z2;
        if (x1>x2) {
            x1+=x2;
            x2 = x1-x2;
            x1-=x2;
        }
        if (y1>y2) {
            y1+=y2;
            y2 = y1-y2;
            y1-=y2;
        }
        if (z1>z2) {
            z1+=z2;
            z2 = z1-z2;
            z1-=z2;
        }
        bool oo = onoff=="on";
        for (int x=x1;x<=x2;x++) for (int y=y1;y<=y2;y++) for(int z=z1;z<=z2;z++) {
            board[{x,y,z}] = oo;
        }
    }
    long long ct = 0;
    for (pair<array<int,3>, bool> p: board) {
        ct+=p.second;
    }
    cout<<ct;
        /*
        bool oo = onoff=="on";
        if (board.size() <= x2) board.resize(x2+1);
        if (board[0].size()<=y2) {
            for (vector<vector<bool>>& v: board) v.resize(y2+1);
        }
        if (board[0][0].size()<=z2) {
            for (vector<vector<bool>>& v: board) for (vector<bool>& w: v) w.resize(z2+1);
        }
        cout<<board.size()<<endl;
        for (;x1<=x2;x1++) {
            
        cout<<x1<<" " <<x2<<" " <<y1<<" " <<y2<<" " << z1<<" " <<z2<<endl;
            for (;y1<=y2;y1++) {
                for (;z1<=z2;z1++) {
                    board[x1][y1][z1] = oo;
                    cout<<x1<<","<<y1<<","<<z1<<endl;
                }
            }
        }
    }
    long long ct = 0;
    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board[0].size();j++) {
            for (int k=0;k<board[0][0].size();k++) {
                ct+=board[i][j][k];
            }
        }
    }
    cout<<ct<<endl;
    */
}
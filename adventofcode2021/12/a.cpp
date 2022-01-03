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
    map<string,vector<string>> adj;
    map<string, bool> vis;
    string s,t;
    vector<string> st,end;
    while(cin>>s>>t) {
        
        if (s=="start") {
            st.push_back(t);
        }
        else if (s=="end")
        {
            end.push_back(t);
        }
        else {
            if ('a'<=s[0] && s[0]<='z') {
                vis[s]=0;
            }
            adj[s].push_back(t);
            adj[t].push_back(s);
        }
        if (t=="start") {
            st.push_back(s);
        }
        else if (t=="end")
        {
            end.push_back(s);
        }
        else {
            if ('a'<=t[0] && t[0]<='z') {
                vis[t]=0;
            }
            adj[s].push_back(t);
            adj[t].push_back(s);
        }
    }
    // find all paths that don't backtrack

}
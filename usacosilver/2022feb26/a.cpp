#include <bits/stdc++.h>
using namespace std;
// print vectors with space delimiter because that's more common with comps
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];out<<endl;return out;}
using p = pair<int,int>;
#define f first
#define s second
#define F(i,n)for(int i=0;i<n;i++)
vector<vector<int>> ar;
void recurse(int i, vector<int>& d) {
    
}
int main() {
    int n;
    cin >> n;
    ar(n, vector<int>(n));
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {cin >> ar[i][j]; ar[i][j]--;}
    // clean up data
    F(i,n) {
        F(j,n) {
            if (ar[i][j]==i) {
                ar[i].resize(j+1);
            }
        }
    }
    // any 1-ers?
    vector<int> res;
    while ()
    F(i,n) {
        if (ar[i].size()==1) {
            // rm from everything else
            F(j,n) {
                F(k,n) {
                    if (ar[j][k]==i) {
                        ar[j].erase(ar[j].begin()+k);
                    }
                }
            }
            res[i]=i;
        }
        cout << ar << endl;
    }
    // cycle of trades
    vector<bool> done(n);
    F(i,n) {
        if (!done[i]){
        vector<int> v = recurse(i, {});
        for (int i: v) {
            done[i]=1;
        }
        }
    }
}
// int main() {
//     int n;
//     cin >> n;
//     vector<vector<int> > ar(n, vector<int>(n));
//     for (int i=0;i<n;i++) for (int j=0;j<n;j++) {cin >> ar[i][j]; ar[i][j]--;}
//     for (int i=0;i<n;i++) {
//         int best = i;
//         for (int j: ar[i]) {
//             if (j==i) {
//                 break;
//             }
//             // j must have another place to go to - if it does we are done
            
//         }
//         cout << best << endl;
//     }
//     // vector<map<int /* attractiveness value */, set<int> /*cows whose value is this*/> > vals(n);
    
//     /*
//     int ind = 0;
//     for (vector<int>& v: ar) {
//         int i = 0;
//         for (int j: v) {
            
//             vals[j][i].insert(ind);
//             i++;
//         }
//         ind++;
//     }
//     cout << vals.size() << endl << endl;
//     for (auto a: vals) {
//         for (auto b: a) {
//             cout << b.f;
//             cout << ",";
//             for (auto c: b.s) {
//                 cout << c << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
//     map<int> res;
//     while (res.size()<n) {

//     }
//     */
// }
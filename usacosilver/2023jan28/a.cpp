#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#define fr(i,m,n) for (int i=m;i<n;i++)
#define fo(i,n) fr(i,0,n)
#define f(n) fo(i,n)
using namespace std;
bool in(char a, string b) {
    for (char i: b) {
        if (i==a) return 1;
    }
    return 0;
}
int main() {
    int t;
    cin >> t;
    fo(T,t) {
        int total = 0;
        string a,b;
        cin >> a >> b;
        int s = a.size();
        map<char,string> m;
        f(s) {
            if (!in(b[i],m[a[i]]))
                m[a[i]]+=b[i];
        }
        string have_checked = "";
        for (pair<char,string> p: m) {
            // cout << p.first << " " << p.second << endl;
            // if any string is more than 1 long, use -1
            if (p.second.size() > 1) {
                cout << -1 << endl;
                goto end;
            }
        }
        
        // find cycles
        for (pair<char,string> p: m) {
            // cout << "x" << endl;
            if (!in(p.first,have_checked)) {
                // new cycle?
                char last = p.first;
                int sz = 0;
                string in_cycle;
                while (!in(last,in_cycle)) {
                    in_cycle += last;
                    if (m[last].size())
                        last = m[last][0];
                    else break;
                    sz++;
                }
                // cout << "s" << sz << endl;
                if (last != p.first) continue;;
                if (sz==1) continue;
                have_checked += in_cycle;
                // still here? new cycle
                total += sz + 1;
                if (m.size()>=52) {cout << -1 << endl; goto end;}
            }
            end1:;
        }
        // cout << "subt" << total << endl;
        for (pair<char,string> p: m) {
            if (!in(p.first,have_checked)) {
                // indiv
                if (p.first != p.second[0])
                total++;
            }
        }
        cout << total << endl;
    //     // find cycles: floyd's but easier
    //     for (pair<char,string> p: m) {
    //         if (!in(p.first,have_checked)) {
    //             // new cycle or indiv swap
    //             char last = p.first;
    //             // cout << "'" << last << "'" << endl;
    //             int sz =0;
    //             // have_checked += last;
    //             // to self, 0
    //             if (p.first == p.second[0]) {continue;}
    //             int ct =0;
    //             while (!in(last,have_checked)) {
    //                 // cout << last;
    //                 have_checked += last;
    //                 if (m[last].size())
    //                     last = m[last][0];
    //                 else {
    //                     // dead end
    //                     total += ct;
    //                     goto end1;
    //                 }
    //                 sz++;
    //                 ct++;
    //             }
    //             // cout << endl;
    //             // from head, keep subtracting 1 from sz until you reach last
    //             // cout << "size1 " << sz << endl;
    //             char head = p.first;
    //             while (head != last) {
    //                 head = m[head][0];
    //                 sz--;
    //                 total++;
    //             }
    //             // cout << "pretotal " << total << endl;
    //             // cout << "size " << sz << endl;
    //             if (sz!=1) {
    //                 total += sz + 1;
    //                 // check if there is a spare free letter
    //                 if (m.size() >= 52) {
    //                     cout << -1 << endl;
    //                     goto end;
    //                 }
    //             }
    //             // cout << total << endl;;
    //         }
    //         end1:;
    //     }
    // cout << total << endl;
    //     for (pair<char,string> p: m) {
    //         if (!in(p.first,have_checked)) {
    //             // new cycle, potentially
    //             char head = p.first, last = p.first;
    //             int sz = 0; // TODO change to 0
    //             while (!in(head,m[last])) { // self pointing chars will not be put into have_checked
    //                 have_checked += last;
    //                 sz++;
    //                 if (m[last].size())
    //                     last = m[last][0];
    //                 else {
    //                     // no cycle
    //                     goto end1;
    //                 }
    //             }
    //             cout << "size is " <<sz << endl;
    //             total+=sz+1;
    //             // needs 1 free temp letter for the cycle to happen, else use -1
    //             if (m.size() >= 52) {
    //                 cout << -1 << endl;
    //                 goto end;
    //             }
    //             end1:;
    //         }
    //     }
    //     // make individual transitions
    //     cout << "result: " <<total << endl;
    end:;
    }
}
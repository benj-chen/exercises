#include <bits/stdc++.h>

using namespace std;

int gi() {
    int a;
    cin >> a;
    return a;
}

int main() {
    int n,m,k,ct=0;
    cin >> n >> m >> k;
    multiset<int> nn,mm;
    while (n--) { // desired sizes
        nn.insert(gi());
    }
    while (m--) {
        mm.insert(gi()); // ap sizes
    }
    // trim nn to match the ulimits of mm, prevent seg fault
    int ma=*mm.end();
    while (*nn.end() -k >= ma) {
        nn.erase(nn.end());
    }
    while (mm.size() && nn.size()) {
        cout  << "\nm: ";
        for (int i: mm) {
            cout << i << ' ';
        }
        cout << "\nn: ";

        for (int i: nn) { // seg fault, nn is empty which is a problem
            cout << i << ' ';
        }
        nn.erase(nn.begin());
        ct++;
        // use lower_bound or upper_bound to find the in-range ap
        multiset<int>::iterator loc=mm.lower_bound(*nn.begin()-k);
        if (*loc<=(*nn.begin()+k)) {
            cout << endl;

            // del all before it
            // remove it and nn begin too
            mm.erase(mm.begin(),loc);
        }
        
    }
    cout << ct;

}

/*
int main() {
    int n,m,k,ct=0;
    cin >> n >> m >> k;
    vector<int> nn(n),mm(m);
    
    while (n--) {
        cin >> nn[n];
    }
    while (m--) {
        cin >> mm[m];
    }
    sort(nn.begin(),nn.end());
    sort(mm.begin(),mm.end());
    for (int i: nn) {

        for (int j: mm) {
            // take the smallest available, too small then remove it
            if (i-k>=j) {
                mm.erase(mm.begin());
            }
            else break;
        }
        if (mm.front() <= i+k) {
            // fit
            ct++;
            mm.erase(mm.begin());
            nn.erase(nn.begin());

        }
    }
    cout << ct;

}
*/
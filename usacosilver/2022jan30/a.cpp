#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a,b,steps=0;
        cin >> a >> b;
        if (a==b) {
            cout << 0 << endl;
            continue;
        }
        if (a<b) {
            int i = 0;
            for (;true;i++) {
                if (a<<i >= b) {
                    break;
                }
            }
            i--;
            int dist = b - (a<<i);
            int pre = dist / (1<<i);
            int post = dist % (1<<i);
            cout << pre+post + i << endl;
        }
        else {
            int steps=0;
            int lgdist;
            for (lgdist=0;true;lgdist++) {
                if (a%2) {
                    steps++;
                    a++;
                }
                a>>=1;
                if (a <= b) {
                    break;
                }
            }
            // for each value until both hit 1, do stuff
            cout << a << " " << b << endl;
            long long best=b-a,times=0, odds = 0;
            while (a>1 && b>1) {
                cout << best << " ";
                odds += (b%2);
                best = fmin(best,b-a+times + odds);
                b>>=1; a>>=1; times++;
            }
            cout <<"ans:"<< best + steps +lgdist<< endl;
            // int dist = b - (a);
            // cout << lgdist + steps + dist << " " << lgdist << (a>>lgdist)<<" " << a << " " << b<< endl;
        }
    }
}
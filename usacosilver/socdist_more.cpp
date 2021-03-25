#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long;
using ull = unsigned long long;
ul sp[10000];
ul ep[10000];
// int st[]={2,4,6,8,10};
int maxst,N,M;
ul maxim,minim;


int lbst(ul i,int start,int end /*size*/) {
    if (i>maxst) return -1;
    int md=(start+end)/2;
    if (!md) return 0;
    if (sp[md]>=i   && sp[md-1]<i) return md;
    if (sp[md+1]>=i && sp[md]<i)   return md+1;
    if (sp[md]>i) return lbst(i,start,md);
    else return lbst(i,md,end);
    return -1;
    assert(0);
    // binary search
}
bool ok(ul loc) {
    int lb=lbst(loc,0,M);
    if (sp[lb]==loc) return 1;
    lb--;
    return sp[lb]<loc && ep[lb]>=loc;
}
bool works(ul dist) {
    ull last=minim;
    for (int i=1;i<N;i++) {
        last+=dist-1;
        do {
            if(last>=maxim/*overflow covered by ull*/) return 0;
            last++;
        } while (ok(last));
    }
    return (last<=maxim);
}
int main() {
    // do input, then sort both
    ifstream cin("socdist.in");
    ofstream cout("socdist.out");
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> sp[i] >> ep[i];
    }
    sort(sp,sp+M);
    sort(ep,ep+M);
    maxim=ep[M-1],minim=sp[0];
    ul largest = maxim-minim;
    // for loop for now, change to binary search. expect slow at first but
    // make work
    ul smallest=1;
    while (true) {
        assert(largest>smallest);
        
        ul mdpt=(largest+smallest)/2;
        if (!works(smallest)) {
            // lower it
            smallest-=(largest-smallest);
            largest=smallest;
            continue;
        }
        else {
            // if it works
            if (!works(smallest+1)) {
                // smallest is it
                cout << smallest << endl;
                return 0;
            }
        }
        if (works(largest)) {
            // raise it
            largest+=(largest-smallest);
            smallest=largest;
            continue;
        }
        if (works(mdpt)) {
            smallest=mdpt;
        }
        // mdpt didn't work so it's too large
        else largest=mdpt;
    }

}
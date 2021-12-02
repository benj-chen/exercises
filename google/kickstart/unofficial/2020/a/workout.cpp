#include <bits/stdc++.h>
using namespace std;
int rnd(int&a,int& b) { // round up division
    return (a/b)+(bool) a%b;
}
int main() {
    int T;
    cin >> T;
    T++;
    for (int t=1;t<T;t++) {
        int N,K;
        cin >> N >> K;
        int in[N];
        // int diff[N-1]; // diff[0] is the second int minus the first int
        priority_queue<int> diff;
        cin >> in[0];
        for (int i=1;i<N;i++) {
            cin >> in[i];
            diff.push(in[i]-in[i-1]);
        }
        
        cout << "Case #" << t << ": ";
        int wdone=0;
        int t1,t2;
        while (true) {
            t1=diff.top();
            diff.pop();
            t2=diff.top();
            int r=rnd(t1,t2);

            if (wdone+r>K) {
                // you only have so much left, split as much then stop
                int a=t1/(wdone+r-K);
                if (a>t2) {
                    cout << a;
                }
                else cout << t2;
                break;
            }
            int t1r=t1/r;
            while (t1>t1r) {
                diff.push(t1r);
                t1-=t1r;
            }
            wdone+=r;
        }
        // it's all about getting the largest down to the second largest in as few workouts as possible. Keep until k runs out
        cout << endl;
        while (!diff.empty()) {
            cout << diff.top()<< ' ';
            diff.pop();
        }
        cout << endl;
    }
}
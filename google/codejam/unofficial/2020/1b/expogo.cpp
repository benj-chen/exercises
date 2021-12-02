// This problem is being finished after reading the analysis
#include <bits/stdc++.h>

using namespace std;
int a,b;
string res;
int abs(int i) {
    if (i>0) return i;
    return -i;
}
int mod2(int i) {
    return (i>0?i%2:-i%2);
}
vector<int> get_spots(bool is_a) {
    int c=(is_a? a:b);
    return {};
}
void solve() {
    if (!((a-b)%2)) { // both odd or even
        res="IMPOSSIBLE";
        return;
    }
    assert (abs(a)%2!=abs(b)%2);
    // ending case
    int& odd=(a%2? a:b);
    int& even=(a%2? b:a);

    if (abs(odd)==1) {
        // good
        if (a==odd) {
            res+=(a>0? "E":"W");
        }
        else if (b==odd) {
            // it's b
            res+=(b>0? "N":"S");
        }
        else {
            // error
            assert(0);
        }
    }


    return;
}

// void solve() {
//     /*
//     until a and b are both 0, try to go to the point, if too far
//     then move it back (maybe do some test here instead), if not
//     then copy the same for up and down. If not that then it's impossible
//     not all numbers can be reached just willy-nilly. For example, -1 can be
//     reached by doing 1 and then -2, but 4 can only be reached by 4 (efficiently).
//     in contrast, 6 can be reached by 2 - 4 or -2 8 depending on what's available.
//     powers of 2 above 1 can only be reached one way - by using that said power
//     there can only be one number that needs a given power of 2 "n"
//     for example, you can't have 1 and 3 because they always require 1 and both cannot
//     require that for it to be a viable sol.
//     is 1 just an exception..?
//     */
//     /*
//     Update: I looked at the analysis after thinking for
//     a bit too long. Turns out I was right in that the
//     odd number thing is an exception! Just goes to show
//     that I need to expand my thinking in a way that would
//     solve the problem.
//     */
    
//     cout << "iter start\n";
//     if (!((a-b)%2)) { // both odd or both even
//         res = "IMPOSSIBLE";
//         return;
//     }
//     if (abs(a)==1 && !b) {
//         if (a>0) res+="E";
//         else res+="W";
//         return;
//     }
//     if (abs(b)==1 && !a) {
//         if (b>0) res+="N";
//         else res+="S";
//         return;
//     }
//     if (a%2) {
//         if (a>0) {
//             res+="E";
//         }
//         else {
//             res+="W";
//         }
//         if (b%2) {
//             if ((a+1)%2) a--;
//             else a++;
//         }
//         else {
//             if ((a-1)%2) a--;
//             else a++;
//         }
//     }
//     else {
//         // b is odd
//         if (b>0) {
//             res+="N";
//         }
//         else {
//             res+="S";
//         }
//         if (a%2) {
//             // b needs to be even
            
//             if ((b+1)%2) b--;
//             else b++;
//         }
//         else {// a is even so b needs to be odd
//             if ((b-1)%2) b--;
//             else b++;
//         }
//     }
//     if (abs(a)%2||abs(b)%2) {
//         cout << "imp\n";
//         res="IMPOSSIBLE";
//         return;
//     }
//     a/=2;
//     b/=2;
//     solve();
// }

int main() {

}

int mann() {
    int T;
    cin >> T;
    T++;
    for (int t=1;t<T;t++) {
        cin >> a >> b;
        cout << "Case #" << t << ": ";
        if (a||b) {
            solve();
            cout << res;
        }
        cout << endl;
        res="";
    }
}
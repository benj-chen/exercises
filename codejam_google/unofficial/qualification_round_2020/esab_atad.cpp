#include <bits/stdc++.h>
using namespace std;




string win(string a, string b) {
    return a;
    if (a==b) return a;
    int al=a.length(),bl=b.length();
    cout << al << ' ' << bl << "lens\n";
    int LCM=(int) lcm(al,bl);
    cout << "ok";
    for (int i=0;i<LCM;i++) {
        if (a[i%al]==b[i%al]) continue;
        if ((a[i%al]=='P' && b[i%al] == 'R') || (a[i%al]=='R' && b[i%al] == 'S') || (a[i%al]=='R' && b[i%al] == 'S')) {
            return a;
        }
        else return b;
    }
}
int lcm_helper(int arr[], int size) { // use numeric
    int prod=1;
    for (int i=0;i<size;i++) {
        prod=lcm(prod,arr[i]);
    }
    return prod;
}
int mainn() {
    cout << ("foo"=="foo");
}
int main() {
    map<char,string> beatby;
    beatby['R']="P";beatby['P']="S";beatby['S']="R";
    int n;
    cin >> n;
    n++;
    for (int q=1;q<n;q++) {
        int w;
        cin >> w;
        string
        // arr[w],
        res="";
        int l2=log2(w+1);
        bool done[l2];
        int lens[l2];
        // for (int i=0;i<w;i++) {
        //     cin >> arr[i];
        //     lens[i]=arr[i].length();
        //     done[i]=false;
        // }
        // new
        vector<string> arr(l2);
        cin >> arr[0];
        string tempa,tempb;
        for (int i=1;i<arr.size();i++) { // this for loop has a floating point exception 8
            cin >> tempa >> tempb;
            arr[i]=win(tempa,tempb);
        }
        for (int i=0;i<arr.size();i++) {
            lens[i]=arr[i].length();
            done[i]=false;
        }
        map<char,bool> appear;
        // ull is 18,446,744,073,709,551,615
        

        
        cout << "Case #" << q << ": ";
        for (int i=0;i<lcm_helper(lens,l2);i++) { // change later - when do you know that you're done? You know you're done when you take the product of all unique values... but let's do better. idk if this is accurate but we'll see I guess.. lcm?
            // for each character
            appear['R']=false;
            appear['P']=false;
            appear['S']=false;
            char repr[w];
            for (int j=0;j<w;j++) {
                if (!done[j]) {
                    repr[j]=arr[j][i%lens[j]];
                    appear[repr[j]]=true;
                }
            }
            int ct = appear['R'] + appear['S'] + appear['P'];
            // ct should be 1,2,3
            if (ct==3) {
                // not viable
                cout << "IMPOSSIBLE\n";
                goto cont;
            }
            if (ct==1) {
                // done=
                cout << res << beatby[appear['R']? 'R' : (appear['S'] ? 'S':'P')] << '\n';
                goto cont;
            }
            else {
                // ct is 2, choose the one that will tie or win. Wins terminate.
                if (appear['R'] && appear['P']) {
                    res+="P";
                }
                else if (appear['R'] && appear['S']) {
                    res+="R";
                }
                else {
                    res+="S";
                }
                string last=res.substr(0,1);
                for (int j=0;j<l2;j++) {
                    if (beatby[repr[j]]==last) {
                        done[j]=true;
                    }
                }
            }

        }
        cout << res << '\n';
        cont:;
    }
}
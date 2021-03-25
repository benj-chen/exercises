#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long;
// vector<bool> create_spots(vector<ul>& st, vector<ul> end, ul sz) {
//     vector<bool> v(sz);

// }
int man() {
    ifstream fin("socdist.in");
    // ofstream cout("socdist.out");
    int n,k;
    fin >> n >> k;
    vector<ul> st(k);
    vector<ul> end(k);
    for (int i=0;i<k;i++) {
        fin >> st[i] >> end[i];
    }
    sort(st.begin(),st.end());
    sort(end.begin(),end.end());
    for (ul& i: end) i++;
    // simulate each result lol
    // the largest d could be is max(end)-min(start)/n
    // check 1 as a base
    ul max=end.back(),min=st[0];
    ul largest = max-min;
    vector<bool> ok(max);
    // for (bool& b: ok) b=false; // seg fault damn
    for (int i=0;i<k;i++) {
        for (int j=st[i];j<end[i];j++) { // req increment
            ok[j]=1;
        }
    }
    for (ul q=1;q<largest;q++)  {
        ul last=min;
        // use n-1 because you place one at the front no matter what
        for (int i=1;i<n;i++) {
            last+=q-1;
            do {
                if (last>=max || last<min){cout << q-1 << endl;return 0;} // goto end; // overflow with an issue - large gap
                // edge case like BLJ the endless stairs in sm64
                last++;
            }
            while (!ok[last]);
        }
        // if (last>max) {
        //     cout << q-1 << endl;
        //     return 0;
        // }
    }

}
// int binary_search(vector<ul>& vec, ul target, int st, int end) {
//     // searches for the index that the target is at, or the number right under
//     // see the middle
//     int mid=(st+end)/2;
    
//     if (vec[mid]==target) {
//         return mid;
//     }
//     if (mid==st) {
//         return st;
//     }
//     else if (mid==end) {
//         return end;
//     }
//     else if (vec[mid]<target) {
//         st=mid;
//     }
//     else end=mid;
//     return binary_search(vec,target,st,end);

// }
// bool ok(vector<ul>& st, vector<ul>& end, ul target) {
//     int ind=binary_search(st,target,0,st.size());
//     if (st[ind+1]<target) ind++; // idk may remove eventually
    
//     return (target<end[ind]);
// }
// int main() {
//     ifstream fin("socdist.in");
//     // ofstream cout("socdist.out");
//     int n,k;
//     fin >> n >> k;
//     vector<ul> st(k);
//     vector<ul> end(k);
//     for (int i=0;i<k;i++) {
//         fin >> st[i] >> end[i];
//     }
//     sort(st.begin(),st.end());
//     sort(end.begin(),end.end());
//     for (ul& i: end) i++;
//     // simulate each result lol
//     // the largest d could be is max(end)-min(start)/n
//     // check 1 as a base
//     ul max=end.back(),min=st[0];
//     ul largest = max-min;
//     // bool ok[max];
//     // for (bool& b: ok) b=false;
//     // cout << "ok\n";
//     // for (int i=0;i<k;i++) {
//     //     for (int j=st[i];j<end[i];j++) { // req increment
//     //         ok[j]=1;
//     //     }
//     // }
//     for (ul q=largest;q;q--)  {
//         ul last=min;
//         // use n-1 because you place one at the front no matter what
//         for (int i=1;i<n;i++) {
//             last+=q-1;
//             do {
//                 if (last>=max || last<min) goto end;
//                 last++;
//             }
//             while (!ok(st,end,last));
//         }
//         if (last<=max) {
//             cout << q << endl;
//             return 0;
//         }
//         end:;
//     }

// }
// int main() {
//     ifstream fin("socdist.in");
//     ofstream cout("socdist.out");
//     int n,k;
//     fin >> n >> k;
//     vector<ul> st(k);
//     vector<ul> end(k);
//     for (int i=0;i<k;i++) {
//         fin >> st[i] >> end[i];
//     }
//     sort(st.begin(),st.end());
//     sort(end.begin(),end.end());
//     for (ul& i: end) i++;
//     // simulate each result lol
//     // the largest d could be is max(end)-min(start)/n
//     // check 1 as a base
//     ul max=end.back(),min=st[0];
//     ul largest = max-min;
//     vector<bool> ok(max);
//     // for (bool& b: ok) b=false;
//     for (int i=0;i<k;i++) {
//         for (ul j=st[i];j<end[i];j++) { // req increment
//             ok[j]=1;
//         }
//     }

//     for (ul q=largest;q;q--)  { // change to binary search essentially for log(n)
//         unsigned long long last=min;
//         // use n-1 because you place one at the front no matter what
//         for (int i=1;i<n;i++) {
//             last+=q-1;
//             do {
//                 if (last>=max) goto end;
//                 last++;
//             }
//             while (!ok[last]);
//         }
//         if (last<=max) {
//             cout << q << endl;
//             return 0;
//         }
//         end:;
//     }

// }

bool good(ul q, vector<bool>& ok,ul& max, ul& min, int n) {
    unsigned long long last=min;
    // use n-1 because you place one at the front no matter what
    for (int i=1;i<n;i++) {
        last+=q-1;
        do {
            if (last>=max) return 0;
            last++;
        }
        while (!ok[last]);
    }
    if (last<=max) {
        return 1;
    }
    return 0;
}

int main() {
    ifstream fin("socdist.in");
    // ofstream cout("socdist.out");
    int n,k;
    fin >> n >> k;
    vector<ul> st(k);
    vector<ul> end(k);
    for (int i=0;i<k;i++) {
        fin >> st[i] >> end[i];
    }
    sort(st.begin(),st.end());
    sort(end.begin(),end.end());
    for (ul& i: end) i++;
    // simulate each result lol
    // the largest d could be is max(end)-min(start)/n
    // check 1 as a base
    ul max=end.back(),min=st[0];
    ul largest = max-min;
    vector<bool> ok(max);
    // for (bool& b: ok) b=false;
    for (int i=0;i<k;i++) {
        for (ul j=st[i];j<end[i];j++) { // req increment
            ok[j]=1;
        }
    }
    ul ub=1,lb=largest;
    while (ub-lb!=-1 && ub-lb!=1 && ub-lb) {
        
        ul mpt=(ub+lb)/2;
        // if lb works then move up
        if (good(lb,ok,max,min,n)) {
            lb=mpt;
        }
        else { // too high, move down
            lb--;
        }
        if (good(ub,ok,max,min,n)) {
            // too low, move up
            ub++;
        }
        else ub=mpt;
        cout << "ub: " << ub << " lb: " << lb << endl;
    }
    cout << ub << " " << lb << endl;
    // for (ul q=largest;q;q--)  { // change to binary search essentially for log(n). put in function
    //     unsigned long long last=min;
    //     // use n-1 because you place one at the front no matter what
    //     for (int i=1;i<n;i++) {
    //         last+=q-1;
    //         do {
    //             if (last>=max) goto end;
    //             last++;
    //         }
    //         while (!ok[last]);
    //     }
    //     if (last<=max) {
    //         cout << q << endl;
    //         return 0;
    //     }
    //     end:;
    // }

}
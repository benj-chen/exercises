#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <array>
#include <functional>
using namespace std;

int gi() {
    int a;
    cin >> a;
    return a;
}
int max(int& i, int& j) {
    return (i>j? i: j);
}
int main() {
    int n,k;
    cin >> n >> k;
    set<int,greater<int> > a;
    for (int i=0;i<n;i++) a.insert((gi()+11)/12);
    // get inf k, then narrow down
    vector<int> b(a.begin(),a.end());
    n=b.size();
    // for (int i: a) {
    //     b.push_back(i);
    // }
    // those within 1 of each other can be grouped together while reducing K
    // k is remaining k
    vector<array<int,2> > c={{b.front(),0}};
    for (int i=1;i<n;i++) {
        if (b[i-1]-b[i]!=1) c.push_back((array<int,2>) {b[i],0});
        else c.back()[1]++;
    }
    // last one technically isn't necessary
    while (c.size()>k) {
        cout << "new iter" << endl;
        int min_d=0x10000;
        int comb=-1;
        for (int i=0;i<c.size()-1;i++) {
            int temp=c[i][0]-c[i][1]-c[i+1][0];
            if (temp < min_d) {
                min_d=temp;
                comb=i;
            }
        }
        c[comb][1]+=c[comb+1][1] + c[comb][0]-c[comb][1]-c[comb+1][0];
        c.erase(c.begin() + comb+1);
    }
    // either merge or teleport to end
    int min_d=0x10000;
    int comb=0;
    for (int i=0;i<c.size()-1;i++) {
        int temp=c[i][0]-c[i][1]-c[i+1][0];
        if (temp < min_d) {
            min_d=temp;
            comb=i;
        }
    }
    if (min_d>c.back()[0]-c.back()[1]) {
        c[comb][1]+=c[comb+1][1] + c[comb][0]-c[comb][1]-c[comb+1][0];
        c.erase(c.begin() + comb+1); 
    } else {};//c[0][1]=0;}

   
    cout << endl;
    for (array<int,2> arr: c) {
        cout << arr[0] << ' ' << arr[1] << endl;
    }
    
    // keep finding the minimum until k is sufficient
    // while (kk>k) {
    // }
    int s=0;
    for (array<int,2> i: c) {
        s+=i[1]+1;
    }
    cout << s*12 << endl; 

}
// int main() {
//     int n,k;
//     cin >> n >> k;
//     int a[n];
//     set<int,greater<int> > b;
//     for (int i=0;i<n;i++) a[i]=(gi()+11)/12;
//     // get inf k, then narrow down
//     sort(a,a+n);
//     for (int i: a) {
//         cout << i << ' ';
//     }
//     // those within 1 of each other can be grouped together while reducing K

// }
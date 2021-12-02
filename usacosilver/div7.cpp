#include <bits/stdc++.h>
using namespace std;
bool in(vector<int>& vec, int item,int st, int end) {
    if (st<end) return 0;
    int md=(st+end)/2;
    if (vec[md]==item) return 1;
    if(vec[md]<item) {
        return in(vec,item,md+1,end);
    }
    return in(arr,st,md-1);
}
int main() {
    ifstream cin("div7.in");
    // ofstream cout("div7.out");
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i=0;i<N;i++) {
        cin >> arr[i];
        arr[i]%=7;
    }
    sort(arr.begin(),arr.end());
    int sum=0;
    while (arr[0]==0) {
        sum++;
        arr.erase(arr.begin());
    }
    int total=0;
    for (int i: arr) total+=i;
    int mod=0;
    while (mod=total%7) {
        // binary search for correct
        if (in(arr,mod,0,arr.size())) {
            cout << arr.size() << endl;
            return 0;
        }
        
    }
    cout << total << endl <<mod << endl;

}